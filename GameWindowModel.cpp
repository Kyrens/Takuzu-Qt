#include "GameWindowModel.h"
#include <stdlib.h>
#include <time.h>

GameWindowModel::GameWindowModel(GameWindowPresenter * gameWindowPresenter, const char * fileName, QObject *parent) : QObject(parent) {

    _presenter = gameWindowPresenter;
    _gridsList = new GridsList(fileName);
    srand(time(NULL));
    initRandomGrid();
}

GameWindowModel::~GameWindowModel() {
    delete[] _gridsList;
}

void GameWindowModel::initRandomGrid() {

    _gameGrid = _gridsList->_grids[rand() % _gridsList->_gridsCount];
    _playerGrid = new Grid(_gameGrid);
}

Grid * GameWindowModel::getPlayerGrid() {
    return _playerGrid;
}

Grid * GameWindowModel::getGameGrid() {
    return _gameGrid;
}
