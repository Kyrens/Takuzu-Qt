#include "MainMenuPresenter.h"

MainMenuPresenter::MainMenuPresenter(MainMenu * mainMenu)
{
    _mainMenu = mainMenu;
    connectGridSize();
    connectGameDifficulty();
    connectGameStart();
    _model = new MainMenuModel(this);
}

void MainMenuPresenter::connectGridSize() {

}

void MainMenuPresenter::connectGameDifficulty() {

}

void MainMenuPresenter::connectGameStart() {
    connect(_mainMenu->getStartButton(), SIGNAL(clicked(bool)), this, SLOT(gameStarted()));
}

void MainMenuPresenter::gameStarted() {

    /*MainMenu w;
    MainMenuPresenter mmp(&w);
    GridInfo("6_easy.txt");
    w.show();*/
}

MainMenuPresenter::~MainMenuPresenter() {
    delete _model;
}
