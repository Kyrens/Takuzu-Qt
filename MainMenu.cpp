#include "MainMenu.h"
#include "ui_MainMenu.h"
#include "MenuBar.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    _presenter = new MainMenuPresenter(this);

    connect(ui->_startButton, SIGNAL(clicked(bool)), _presenter, SLOT(gameStarted()));
    connect(ui->_sizeComboBox, SIGNAL(currentIndexChanged(QString)), _presenter, SLOT(sizeChanged(QString)));
    _presenter->sizeChanged(ui->_sizeComboBox->currentText());

    MenuBar * menuBar = new MenuBar(parent);
    connect(ui->actionQuitter, SIGNAL(triggered(bool)), menuBar, SLOT(quit()));
    connect(ui->actionRegles_du_jeu, SIGNAL(triggered(bool)), menuBar, SLOT(rules()));
    connect(ui->actionApropos, SIGNAL(triggered(bool)), menuBar, SLOT(about()));
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

int MainMenu::getSelectedSize() {
    return ui->_sizeComboBox->currentText().toInt();
}

bool MainMenu::isDifficultySelected(Difficulty diff) {
    return getRadioButton(diff)->isChecked();
}

void MainMenu::addSize(int size) {
    ui->_sizeComboBox->addItem(QString::number(size));
}

MainMenu::~MainMenu()
{
    delete ui;
    delete _presenter;
}
