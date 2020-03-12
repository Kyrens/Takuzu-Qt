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
