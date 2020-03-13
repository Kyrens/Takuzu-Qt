#ifndef GAMEWINDOWMODEL_H
#define GAMEWINDOWMODEL_H

#include <QObject>
#include "GameWindowPresenter.h"
#include "GridsList.h"

class GameWindowPresenter;

class GameWindowModel : public QObject
{
    Q_OBJECT
public:
    GameWindowModel(GameWindowPresenter * gameWindowPresenter, const char * fileName, QObject *parent = nullptr);
    ~GameWindowModel();
    void initRandomGrid();
    Grid * getPlayerGrid();
    Grid * getGameGrid();

private:
    GameWindowPresenter * _presenter;
    GridsList * _gridsList;
    Grid * _gameGrid;
    Grid * _playerGrid;

signals:

public slots:
};

#endif // GAMEWINDOWMODEL_H
