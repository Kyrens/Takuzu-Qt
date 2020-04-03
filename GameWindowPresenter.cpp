#include "GameWindowPresenter.h"
#include <QTimer>

GameWindowPresenter::GameWindowPresenter(GameWindow * gameWindow, const char * fileName, QObject *parent) : QObject(parent) {

    _view = gameWindow;
    _model = new GameWindowModel(this, fileName, this);

    _view->showInitGrid(_model->getPlayerGrid()->getSize());

    bool* _errorsTmp = new bool[_model->getPlayerGrid()->getSize()];

    QTimer * timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeUpdate()));
}

void GameWindowPresenter::timeUpdate() {
    int t = _model->updatePlayTime();
    _view->setTime(t / 60, t % 60);
}

void GameWindowPresenter::updateCellErrors(int row, int col) {
    int whiteCount;
    int blackCount;
    _model->getRowErrors(_errorsTmp, row, &whiteCount, &blackCount);
}

void GameWindowPresenter::clickCell(int i, int j) {
    if (_model->clickCell(i, j)) {

    }
    else {
        //Impossible, blocked
    }
}

char GameWindowPresenter::getCell(int i, int j) {
    return _model->getPlayerGrid()->getCell(i, j);
}

