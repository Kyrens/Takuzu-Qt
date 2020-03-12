#include "GameWindowModel.h"

GameWindowModel::GameWindowModel(GameWindowPresenter * gameWindowPresenter, const char * fileName, QObject *parent) : QObject(parent) {

    _presenter = gameWindowPresenter;
    _gridsList = new GridsList(fileName);
}

GameWindowModel::~GameWindowModel() {
    delete[] _gridsList;
}
