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

bool GameWindowModel::getRowsOrColumnsErrors(bool ** cells, bool row, bool initCellsAtFalse, int ** count) {
    bool error = false;
    char last = '.';
    int cumul = 0;
    int halfSize = _playerGrid->getSize() / 2;
    for (int i = 0; i < _playerGrid->getSize(); ++i) {
        count[i][0] = 0;
        count[i][1] = 0;
        for (int j = 0; j < _playerGrid->getSize(); ++j) {
            if (initCellsAtFalse) {
                if (row) {
                    cells[i][j] = false;
                }
                else {
                    cells[j][i] = false;
                }
            }
            char c;
            if (row) {
                c = _playerGrid->getCell(i, j);
            }
            else {
                c = _playerGrid->getCell(j, i);
            }
            if (c != '.') {
                if (c == 'B') {
                    count[i][0]++;
                }
                else if (c == 'W') {
                    count[i][1]++;
                }
                if (count[i][0] > halfSize || count[i][1] > halfSize) {
                    error = true;
                }
                if (last == c) {
                    cumul++;
                }
                else {
                    if (cumul > 2) {
                        for (int k = 0; k < cumul; ++k) {
                            if (row) {
                                cells[i - k][j] = true;
                            }
                            else {
                                cells[j][i - k] = true;
                            }
                            error = true;
                        }
                    }
                    last = c;
                    cumul = 1;
                }
            }
            else {
                error = true;
            }
        }
    }
    return error;
}

bool GameWindowModel::getErrors(bool ** cells, int ** lineCount, int ** columnCount) {
    return getRowsOrColumnsErrors(cells, true, true, lineCount) || getRowsOrColumnsErrors(cells, false, false, columnCount);
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
