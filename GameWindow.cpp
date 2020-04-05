#include "GameWindow.h"
#include "ui_GameWindow.h"
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

}

GameWindow::~GameWindow()
{
    delete ui;
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

                ui->gridLayout->addWidget(tmp, i, j, 1 ,1, Qt::AlignCenter);

                connect(tmp, SIGNAL(clicked(bool)), this, SLOT(clickToken()));
            } else if (i >= size && j >= size) {
            } else {
                QLabel* tmp = new QLabel();
                tmp->setText(QString::number(size/2));
                ui->gridLayout->addWidget(tmp, i, j, 1 ,1, Qt::AlignCenter);
            }

        }
    }

    connect(ui->undoButton, SIGNAL(clicked(bool)), this, SLOT(clickUndo()));

}

void GameWindow::refreshToken(int i, int j, char c) {
    
    QLayoutItem *item = ui->gridLayout->itemAtPosition(i, j);
    QWidget *button = item->widget();

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
    button->update();
}

void GameWindow::refreshLine(int line, bool * errors, int whiteLeft, int blackLeft) {

}

void GameWindow::refreshColumn(int column, bool * errors, int whiteLeft, int blackLeft) {

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
    msgBox.setText(s);
    msgBox.exec();
    _presenter->goToMainMenu();
}

void GameWindow::clickToken() {
    int row;
    int col;
    int dump;
    ui->gridLayout->getItemPosition(ui->gridLayout->indexOf(static_cast<QWidget*>(sender())), &row, &col, &dump, &dump);
    _presenter->clickCell(row, col);
}

void GameWindow::clickUndo() {
    _presenter->undoLastAction();
}
