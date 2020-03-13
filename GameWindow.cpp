#include "GameWindow.h"
#include "ui_GameWindow.h"
#include <QPixmap>

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

void GameWindow::showInitGrid(int size) {
    for(int i = 0; i < size + 2; i++) {
        for(int j = 0; j < size + 2; j++) {
            if (i < size && j < size) {

                QLabel* tmp = new QLabel();
                tmp->setText("Jeton");

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
