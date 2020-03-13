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

private:
    GameWindow * _view;
    GameWindowModel * _model;

signals:

public slots:
    void timeUpdate();
};

#endif // GAMEWINDOWPRESENTER_H
