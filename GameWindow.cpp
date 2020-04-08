#include "GameWindow.h"
#include "ui_GameWindow.h"
#include "GridCellToken.h"
#include "GridCellLabel.h"
#include <QPixmap>
#include <QPushButton>
#include <QMessageBox>

GameWindow::GameWindow(const char * fileName, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    QPalette pal = ui->centralwidget->palette();
    pal.setColor(QPalette::Background, QColor(Qt::darkGray));
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(pal);
    ui->centralwidget->update();

    _presenter = new GameWindowPresenter(this, fileName, this);

    _menuBar = new MenuBar(parent, _presenter);
    connect(ui->actionNouvelle_partie, SIGNAL(triggered(bool)), _menuBar, SLOT(newGame()));
    connect(ui->actionQuitter, SIGNAL(triggered(bool)), _menuBar, SLOT(quit()));
    connect(ui->actionRegles_du_jeu, SIGNAL(triggered(bool)), _menuBar, SLOT(rules()));
    connect(ui->actionApropos, SIGNAL(triggered(bool)), _menuBar, SLOT(about()));
}

GameWindow::~GameWindow()
{
    delete _menuBar;
    delete ui;
    delete _presenter;
}

void GameWindow::setTime(int min, int sec) {
    QString s;
    if (min < 10) {
        s.append('0');
    }
    s.append(QString::number(min)).append(":");
    if (sec < 10) {
        s.append('0');
    }
    s.append(QString::number(sec));
    ui->timeLabel->setText(s);
}

void GameWindow::showInitGrid(int size) {
    for(int i = 0; i < size + 2; i++) {
        for(int j = 0; j < size + 2; j++) {
            if (i < size && j < size) {

                QPushButton* tmp = new QPushButton();

                tmp->setFixedHeight(50);
                tmp->setFixedWidth(50);
                QRect rect(5,5,40,40);
                QRegion region(rect, QRegion::Ellipse);
                tmp->setMask(region);

                QPalette pal = tmp->palette();
                pal.setColor(QPalette::Button, QColor(Qt::gray));
                tmp->setAutoFillBackground(true);
                tmp->setPalette(pal);

                ui->gridLayout->addWidget(new GridCellToken(tmp, this), i, j, 1 ,1, Qt::AlignCenter);

                connect(tmp, SIGNAL(clicked(bool)), this, SLOT(clickToken()));
            } else if (i >= size && j >= size) {
            } else {
                ui->gridLayout->addWidget(new GridCellLabel(i == size + 1 || j == size + 1, this), i, j, 1 ,1, Qt::AlignCenter);
            }

        }
    }

    connect(ui->undoButton, SIGNAL(clicked(bool)), this, SLOT(clickUndo()));

    QSize s = ui->verticalLayout->sizeHint();
    this->resize(s.width() +20, s.height() +40);
}

void GameWindow::refreshToken(int i, int j, char c) {
    
    QLayoutItem *item = ui->gridLayout->itemAtPosition(i, j);
    GridCellToken * cell = (GridCellToken *) item->widget();
    QWidget *button = cell->button;

    QPalette pal = button->palette();

    switch (c) {
    case '.':
        pal.setColor(QPalette::Button, QColor(Qt::gray));
        break;
    case 'W':
        pal.setColor(QPalette::Button, QColor(Qt::white));
        break;
    case 'B':
        pal.setColor(QPalette::Button, QColor(Qt::black));
        break;
    default:
        break;
    }

    button->setAutoFillBackground(true);
    button->setPalette(pal);
    cell->update();
}

void refreshCount(GridCellLabel * cell, int count) {
    cell->setCount(count);
    cell->update();
}

bool GameWindow::keepError(QGridLayout * gridLayout, int i, int j, int size) {
    if (_presenter == nullptr) {
        return false;
    }
    char currToken = _presenter->getCell(i, j);
    for (int k = -1; k < 2; ++k) {
        for (int l = -1; l < 2; ++l) {
            if (i + k == -1 || j + l == -1 || i + k == size || j + l == size || (k + l != -1 && k + l != 1)) {
                continue;
            }
            GridCellToken * cell = (GridCellToken *) gridLayout->itemAtPosition(i + k, j + l)->widget();
            if (cell->hasError() && _presenter->getCell(i + k, j + l) == currToken) {
                return true;
            }
        }
    }
    return false;
}

void GameWindow::refreshLine(int line, bool * errors, int size, int whiteLeft, int blackLeft) {
    refreshCount((GridCellLabel *) ui->gridLayout->itemAtPosition(line, size)->widget(), whiteLeft);
    refreshCount((GridCellLabel *) ui->gridLayout->itemAtPosition(line, size + 1)->widget(), blackLeft);
    for (int i = 0; i < size; ++i) {
        bool setError = true;
        if (!errors[i] && _presenter != nullptr) {
            char currToken = _presenter->getCell(line, i);
            for (int j = -1; j < 2; j += 2) {
                if (line + j == -1 || line + j == size) {
                    continue;
                }
                if (_presenter->getCell(line + j, i) == currToken && ((GridCellToken *) ui->gridLayout->itemAtPosition(line + j, i)->widget())->hasError()) {
                    setError = false;
                }
            }
        }
        if (setError) {
            GridCellToken * cell = (GridCellToken *) ui->gridLayout->itemAtPosition(line, i)->widget();
            cell->setError(errors[i]);
            cell->repaint();
        }
    }
}

void GameWindow::refreshColumn(int column, bool * errors, int size, int whiteLeft, int blackLeft) {
    refreshCount((GridCellLabel *) ui->gridLayout->itemAtPosition(size, column)->widget(), whiteLeft);
    refreshCount((GridCellLabel *) ui->gridLayout->itemAtPosition(size + 1, column)->widget(), blackLeft);
    for (int i = 0; i < size; ++i) {
        bool setError = true;
        if (!errors[i] && _presenter != nullptr) {
            char currToken = _presenter->getCell(i, column);
            for (int j = -1; j < 2; j += 2) {
                if (column + j == -1 || column + j == size) {
                    continue;
                }
                if (_presenter->getCell(i, column + j) == currToken && ((GridCellToken *) ui->gridLayout->itemAtPosition(i, column + j)->widget())->hasError()) {
                    setError = false;
                }
            }
        }
        if (setError) {
            GridCellToken * cell = (GridCellToken *) ui->gridLayout->itemAtPosition(i, column)->widget();
            cell->setError(errors[i]);
            cell->repaint();
        }
    }
}

void GameWindow::toggleUndoButton(bool enable) {
    ui->undoButton->setEnabled(enable);
}

void GameWindow::updateUndoCount(int undoCount) {
    QString base = "Nombre de retour en arrière : ";
    QString text;
    text = base + QString::number(undoCount);

    ui->undoLabel->setText(text);
}

void GameWindow::gameFinished(int undoCount, int seconds) {
    QMessageBox msgBox;
    QString s;
    s.append("Partie terminée\n\nTemps: ").append(QString::number(seconds)).append(" secondes\nNombre de retours en arrière: ").append(QString::number(undoCount));
    msgBox.setWindowTitle("Partie terminée");
    msgBox.setText(s);
    msgBox.exec();
    _presenter->goToMainMenu();
}

void GameWindow::clickToken() {
    int row;
    int col;
    int dump;
    ui->gridLayout->getItemPosition(ui->gridLayout->indexOf(static_cast<QWidget*>(sender()->parent())), &row, &col, &dump, &dump);
    _presenter->clickCell(row, col);
}

void GameWindow::clickUndo() {
    _presenter->undoLastAction();
}
