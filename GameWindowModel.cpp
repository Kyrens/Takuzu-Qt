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

bool lineErrors(Grid * grid, int line, bool isRow, bool * cellsError, int * whiteCount, int * blackCount) {
    bool error = false;
    char last = '.';
    int cumul = 0;
    int halfSize = grid->getSize() / 2;
    (*blackCount) = 0;
    (*whiteCount) = 0;
    for (int i = 0; i < grid->getSize(); ++i) {
        char c;
        if (isRow) {
            c = grid->getCell(line, i);
        }
        else {
            c = grid->getCell(i, line);
        }
        if (c != '.') {
            if (c == 'B') {
                (*blackCount)++;
            }
            else if (c == 'W') {
                (*whiteCount)++;
            }
            if (*blackCount > halfSize || *whiteCount > halfSize) {
                error = true;
            }
            if (last == c) {
                cumul++;
            }
            if (cumul == 3) {
                cellsError[i] = true;
                cellsError[i - 1] = true;
                cellsError[i - 2] = true;
            }
            else if (cumul > 3) {
                cellsError[i] = true;
            }
        }
        else {
            error = true;
        }
    }
    return error;
}

bool GameWindowModel::getRowErrors(bool * cellsErrors, int row, int * whiteCount, int * blackCount) {
    return lineErrors(_playerGrid, row, true, cellsErrors, whiteCount, blackCount);
}

bool GameWindowModel::getColumnErrors(bool * cellsErrors, int col, int * whiteCount, int * blackCount) {
    return lineErrors(_playerGrid, col, false, cellsErrors, whiteCount, blackCount);
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
