#include "GameWindow.h"
#include "ui_GameWindow.h"
#include <iostream>

GameWindow::GameWindow(const char * fileName, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    std::cout << fileName << std::endl;
}

GameWindow::~GameWindow()
{
    delete ui;
}
