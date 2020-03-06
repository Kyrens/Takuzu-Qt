#include "MainMenu.h"
#include "ui_MainMenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

QPushButton * MainMenu::getStartButton() {
    return ui->_startButton;
}

MainMenu::~MainMenu()
{
    delete ui;
}
