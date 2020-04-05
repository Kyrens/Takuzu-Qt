#include "MainMenu.h"
#include "ui_MainMenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    _presenter = new MainMenuPresenter(this);
}

QPushButton * MainMenu::getStartButton() {
    return ui->_startButton;
}

QComboBox * MainMenu::getSizeComboBox() {
    return ui->_sizeComboBox;
}

void MainMenu::activateDifficulty(Difficulty diff) {
    getRadioButton(diff)->setEnabled(true);
}

QRadioButton * MainMenu::getRadioButton(Difficulty diff) {
    switch (diff) {
        case EASY:
            return ui->_easyRadioButton;
        case HARD:
            return ui->_hardRadioButton;
    }
    return nullptr;
}

void MainMenu::disableAllDifficulties() {
    ui->_easyRadioButton->setAutoExclusive(false);
    ui->_easyRadioButton->setChecked(false);
    ui->_easyRadioButton->setAutoExclusive(true);
    ui->_hardRadioButton->setAutoExclusive(false);
    ui->_hardRadioButton->setChecked(false);
    ui->_hardRadioButton->setAutoExclusive(true);
    ui->_easyRadioButton->setDisabled(true);
    ui->_hardRadioButton->setDisabled(true);
}

MainMenu::~MainMenu()
{
    delete ui;
}
