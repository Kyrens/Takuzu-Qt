#include "GameWindow.h"
#include "ui_GameWindow.h"
#include <QPixmap>
#include <QPushButton>

GameWindow::GameWindow(const char * fileName, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
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

                ui->gridLayout->addWidget(tmp, i, j, 1 ,1, Qt::AlignCenter);
            } else if (i >= size && j >= size) {
            } else {
                QLabel* tmp = new QLabel();
                tmp->setText("0");
                ui->gridLayout->addWidget(tmp, i, j, 1 ,1, Qt::AlignCenter);
            }

        }
    }
}

void GameWindow::refreshToken(int i, int j, char c) {

}

void GameWindow::refreshLine(int line, int whiteLeft, int blackLeft) {

}

void GameWindow::refreshColumn(int column, int whiteLeft, int blackLeft) {

}

void GameWindow::refreshCellErrors(bool ** errors) {

}
