#include "MainMenuModel.h"

MainMenuModel::MainMenuModel(MainMenuPresenter * presenter) {
    _presenter = presenter;
    connect(_presenter, SIGNAL(gridSizeChanged(int)), this, SLOT(changeSize(int)));
    connect(_presenter, SIGNAL(gameDifficultyChanged(int)), this, SLOT(changeDifficulty(int)));
}

void MainMenuModel::changeSize(int size) {

}

void MainMenuModel::changeDifficulty(int difficulty) {

}
