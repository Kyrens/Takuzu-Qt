#include "GameWindow.h"
#include "ui_GameWindow.h"

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
