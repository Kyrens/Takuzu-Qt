#include "GameWindowPresenter.h"
#include <QTimer>

GameWindowPresenter::GameWindowPresenter(GameWindow * gameWindow, const char * fileName, QObject *parent) : QObject(parent) {

    _view = gameWindow;
    _model = new GameWindowModel(this, fileName, this);

    _view->showInitGrid(_model->getPlayerGrid()->getSize());

    QTimer * timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeUpdate()));
}

void GameWindowPresenter::timeUpdate() {
    int t = _model->updatePlayTime();
    _view->setTime(t / 60, t % 60);
}
