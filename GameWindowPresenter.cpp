#include "GameWindowPresenter.h"
#include "MainMenu.h"
#include <QTimer>
#include <utility>

GameWindowPresenter::GameWindowPresenter(GameWindow * gameWindow, const char * fileName, QObject *parent) : QObject(parent) {

    _view = gameWindow;
    _model = new GameWindowModel(this, fileName, this);

    int size = _model->getPlayerGrid()->getSize();
    _view->showInitGrid(size);
    _view->toggleUndoButton(false);
    _view->updateUndoCount(0);

    _errorsTmp = new bool[_model->getPlayerGrid()->getSize()]();
    _linesValid = new bool[_model->getPlayerGrid()->getSize()]();
    _columnsValid = new bool[_model->getPlayerGrid()->getSize()]();

    for (int i = 0; i < size; ++i) {
        int whiteCount = 0;
        int blackCount = 0;
        for (int j = 0; j < size; ++j) {
            char c = _model->getPlayerGrid()->getCell(i, j);
            if (c == 'W') whiteCount++;
            else if (c == 'B') blackCount++;
            _view->refreshToken(i, j, c);
        }
        _view->refreshLine(i, _errorsTmp, whiteCount, blackCount);
    }
    for (int i = 0; i < size; ++i) {
        int whiteCount = 0;
        int blackCount = 0;
        for (int j = 0; j < size; ++j) {
            char c = _model->getPlayerGrid()->getCell(j, i);
            if (c == 'W') whiteCount++;
            else if (c == 'B') blackCount++;
        }
        _view->refreshColumn(i, _errorsTmp, whiteCount, blackCount);
    }

    QTimer * timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeUpdate()));
}

GameWindowPresenter::~GameWindowPresenter() {
    delete _model;
    delete[] _errorsTmp;
    delete[] _linesValid;
    delete[] _columnsValid;
}

void GameWindowPresenter::timeUpdate() {
    int t = _model->updatePlayTime();
    _view->setTime(t / 60, t % 60);
}

void GameWindowPresenter::verifyGrid() {
    for (int i = 0; i < _model->getPlayerGrid()->getSize(); ++i) {
        if (!_linesValid[i] || !_columnsValid) {
            return;
        }
    }
    _view->gameFinished(_model->getUndoCount(), _model->getTime());
}

void GameWindowPresenter::updateCellErrors(int row, int col) {
    int whiteCount;
    int blackCount;
    int size = _model->getPlayerGrid()->getSize();
    _linesValid[row] =!_model->getRowErrors(_errorsTmp, row, &whiteCount, &blackCount);
    _view->refreshLine(row, _errorsTmp, size - whiteCount, size - blackCount);
    _columnsValid[col] = _model->getColumnErrors(_errorsTmp, col, &whiteCount, &blackCount);
    _view->refreshColumn(col, _errorsTmp, size - whiteCount, size - blackCount);
    verifyGrid();
}

void GameWindowPresenter::refreshCell(int i, int j) {
    _view->refreshToken(i, j, _model->getPlayerGrid()->getCell(i, j));
    updateCellErrors(i, j);
}

void GameWindowPresenter::clickCell(int i, int j) {
    if (_model->clickCell(i, j)) {
        refreshCell(i, j);
        _view->toggleUndoButton(true);
    }
    else {
        //Impossible, blocked
    }
}

char GameWindowPresenter::getCell(int i, int j) {
    return _model->getPlayerGrid()->getCell(i, j);
}

void GameWindowPresenter::undoLastAction() {
    std::pair<int,int> cell = _model->undoLastClickCellAction();
    if (cell.first != -1) {
        refreshCell(cell.first, cell.second);
        _view->updateUndoCount(_model->getUndoCount());
    }
    _view->toggleUndoButton(_model->canUndo());
}

void GameWindowPresenter::goToMainMenu() {
    _view->close();
    static_cast<MainMenu*>(_view->parent())->show();
    delete _view;
}
