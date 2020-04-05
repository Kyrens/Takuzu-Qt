#include "MainMenuPresenter.h"
#include "GameWindow.h"
#include <set>

MainMenuPresenter::MainMenuPresenter(MainMenu * mainMenu)
{
    _mainMenu = mainMenu;
    _model = new MainMenuModel(this);
}

GridInfo * MainMenuPresenter::getSelectedGrid() {
    int size = _mainMenu->getSelectedSize();
    int difficulty = -1;
    for (int d = EASY; d <= HARD; ++d) {
        if (_mainMenu->isDifficultySelected(static_cast<Difficulty>(d))) {
            difficulty = d;
            break;
        }
    }
    if (difficulty == -1) {
        return nullptr;
    }
    Difficulty diff = static_cast<Difficulty>(difficulty);
    for (int i = 0; i < _gridsCount; ++i) {
        if (size == _grids[i]->_size && diff == _grids[i]->_difficulty) {
            return _grids[i];
        }
    }
    return nullptr;
}

void MainMenuPresenter::gameStarted() {
    GridInfo * gridInfo = getSelectedGrid();
    if (gridInfo != nullptr) {
        _mainMenu->close();
        GameWindow * w = new GameWindow(gridInfo->_fileName);
        w->show();
    }
}

void MainMenuPresenter::sizeChanged(QString size) {
    if (_grids == nullptr) {
        return;
    }
    int s = size.toInt();
    std::set<Difficulty> diffList;
    for (int i = 0; i < _gridsCount; ++i) {
        if (s == _grids[i]->_size) {
            diffList.insert(_grids[i]->_difficulty);
        }
    }
    _mainMenu->disableAllDifficulties();
    for (std::set<Difficulty>::iterator it = diffList.begin(); it != diffList.end(); ++it) {
        _mainMenu->activateDifficulty(*it);
    }
}

MainMenuPresenter::~MainMenuPresenter() {
    delete _model;
}

void MainMenuPresenter::refreshGrids(GridInfo ** grids, int gridsCount) {
    _grids = grids;
    _gridsCount = gridsCount;
    std::set<int> sizeList;
    for (int i = 0; i < gridsCount; ++i) {
        sizeList.insert(grids[i]->_size);
    }
    for (std::set<int>::iterator it = sizeList.begin(); it != sizeList.end(); ++it) {
        _mainMenu->addSize(*it);
    }
}
