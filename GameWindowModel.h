#ifndef GAMEWINDOWMODEL_H
#define GAMEWINDOWMODEL_H

#include <QObject>
#include "GameWindowPresenter.h"
#include "GridsList.h"
#include <stack>
#include <utility>

class GameWindowPresenter;

class GameWindowModel : public QObject
{
    Q_OBJECT
public:
    GameWindowModel(GameWindowPresenter * gameWindowPresenter, const char * fileName, QObject *parent = nullptr);
    ~GameWindowModel();
    void initRandomGrid();
    Grid * getPlayerGrid();
    bool clickCell(int i, int j);
    int updatePlayTime();
    bool getRowErrors(bool * cellsErrors, int row, int * whiteCount, int * blackCount, bool * sameRows);
    bool getColumnErrors(bool * cellsErrors, int col, int * whiteCount, int * blackCount, bool * sameColumns);
    std::pair<int,int> undoLastClickCellAction();
    bool canUndo();
    int getUndoCount();
    int getTime();

private:
    GameWindowPresenter * _presenter;
    GridsList * _gridsList;
    Grid * _gameGrid;
    Grid * _playerGrid;
    int _seconds = 0;
    Grid * getGameGrid();
    std::stack<std::pair<int,int>> _clickCellActionsStack;
    int _undoCount = 0;

signals:

public slots:
};

#endif // GAMEWINDOWMODEL_H
