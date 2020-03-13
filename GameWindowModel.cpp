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

bool GameWindowModel::validateRowOrColumn(int index, bool row) {

    char last = 0;
    int occ;
    int blackCount = 0;
    int whiteCount = 0;
    for (int i = 0; i < _playerGrid->getSize(); ++i) {
        char c;
        if (row) {
            c = _playerGrid->getCell(index, i);
        }
        else {
            c = _playerGrid->getCell(i, index);
        }
        if (c == 'B') {
            blackCount++;
        }
        else if (c == 'W') {
            whiteCount++;
        }
        if (last != c) {
            occ = 1;
            last = c;
        }
        else if (last != '.') {
            occ++;
            if (occ > 2) {
                return false;
            }
        }
    }
    if (blackCount + whiteCount == _playerGrid->getSize()) {
        return blackCount == whiteCount;
    }
    return true;
}

bool GameWindowModel::isRowValid(int line) {

    return validateRowOrColumn(line, true);
}

bool GameWindowModel::isColumnValid(int column) {

    return validateRowOrColumn(column, false);
}

bool GameWindowModel::clickCell(int i, int j) {

    if (i < 0 || j < 0 || i >= _playerGrid->getSize() || j >= _playerGrid->getSize()) {
        return false;
    }
    if (_gameGrid->getCell(i, j) != '.') {
        return false;
    }
    char c = _playerGrid->getCell(i, j);
    switch (c) {
        case 'B':
            _playerGrid->setCell(i, j, 'W');
            break;
        case 'W':
            _playerGrid->setCell(i, j, '.');
            break;
        default:
            _playerGrid->setCell(i, j, 'B');
            break;
    }
    return true;
}

int GameWindowModel::updatePlayTime() {
    return ++_seconds;
}
