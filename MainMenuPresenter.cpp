#include "MainMenuPresenter.h"
#include "GameWindow.h"

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

    _mainMenu->close();
    GameWindow * w = new GameWindow;
    w->show();
}

MainMenuPresenter::~MainMenuPresenter() {
    delete _model;
}
