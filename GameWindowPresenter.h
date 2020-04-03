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
    void getErrors(bool ** cells, int ** whiteCount, int ** blackCount);

private:
    GameWindow * _view;
    GameWindowModel * _model;
    int ** whiteCount;
    int ** blackCount;

signals:

public slots:
    void timeUpdate();
};

#endif // GAMEWINDOWPRESENTER_H
