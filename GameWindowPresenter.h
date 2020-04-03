#ifndef GAMEWINDOWPRESENTER_H
#define GAMEWINDOWPRESENTER_H

#include <QObject>
#include "GameWindow.h"
#include "GameWindowModel.h"

class GameWindow;
class GameWindowModel;

class GameWindowPresenter : public QObject
{
    Q_OBJECT
public:
    GameWindowPresenter(GameWindow * gameWindow, const char * fileName, QObject *parent = nullptr);
    void clickCell(int i, int j);
    char getCell(int i, int j);
    void undoLastAction();

private:
    GameWindow * _view;
    GameWindowModel * _model;
    bool * _errorsTmp;
    void updateCellErrors(int row, int col);
    void refreshCell(int i, int j);

signals:

public slots:
    void timeUpdate();
};

#endif // GAMEWINDOWPRESENTER_H
