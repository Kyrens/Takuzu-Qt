/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

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
    delete _gridsList;
    delete _playerGrid;
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
        cellsError[i] = false;
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
            else {
                cumul = 0;
            }
            if (cumul == 2) {
                cellsError[i] = true;
                cellsError[i - 1] = true;
                cellsError[i - 2] = true;
                error = true;
            }
            else if (cumul > 2) {
                cellsError[i] = true;
            }
        }
        else {
            error = true;
        }
        last = c;
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
    _clickCellActionsStack.push(std::make_pair(i, j));

    return true;
}

int GameWindowModel::updatePlayTime() {
    return ++_seconds;
}

bool GameWindowModel::canUndo() {
    return !_clickCellActionsStack.empty();
}

std::pair<int,int> GameWindowModel::undoLastClickCellAction() {
    if (_clickCellActionsStack.empty()) {
        return std::make_pair(-1, -1);
    }
    _undoCount++;
    std::pair<int,int> cell = _clickCellActionsStack.top();
    _clickCellActionsStack.pop();
    int i = cell.first;
    int j = cell.second;
    char c = _playerGrid->getCell(i, j);
    switch (c) {
        case 'B':
            _playerGrid->setCell(i, j, '.');
            break;
        case 'W':
            _playerGrid->setCell(i, j, 'B');
            break;
        default:
            _playerGrid->setCell(i, j, 'W');
            break;
    }
    return cell;
}

int GameWindowModel::getUndoCount() {
    return _undoCount;
}

int GameWindowModel::getTime() {
    return _seconds;
}

bool GameWindowModel::areTwoLinesIdentical() {
    int size = _playerGrid->getSize();
    for (int i = 0; i < size - 1; ++i) {
        bool dontCheckLine = false;
        for (int j = i + 1; j < size; ++j) {
            int k;
            for (k = 0; k < size; ++k) {
                char cell = _playerGrid->getCell(i, k);
                if (cell == '.') {
                    dontCheckLine = true;
                    break;
                }
                if (cell != _playerGrid->getCell(j, k)) {
                    break;
                }
            }
            if (dontCheckLine) {
                break;
            }
            if (k == size) {
                return true;
            }
        }
    }
    for (int i = 0; i < size - 1; ++i) {
        bool dontCheckLine = false;
        for (int j = i + 1; j < size; ++j) {
            int k;
            for (k = 0; k < size; ++k) {
                char cell = _playerGrid->getCell(k, i);
                if (cell == '.') {
                    dontCheckLine = true;
                    break;
                }
                if (_playerGrid->getCell(k, i) != _playerGrid->getCell(k, j)) {
                    break;
                }
            }
            if (dontCheckLine) {
                break;
            }
            if (k == size) {
                return true;
            }
        }
    }
    return false;
}
