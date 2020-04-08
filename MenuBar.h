#ifndef MENUBAR_H
#define MENUBAR_H

#include <QObject>
#include "GameWindowPresenter.h"

class MenuBar : public QObject
{
    Q_OBJECT
public:
    MenuBar(GameWindowPresenter * presenter = nullptr);
    ~MenuBar();

private:
    GameWindowPresenter * _presenter;

public slots:
    void newGame();
    void quit();
    void rules();
    void about();
};

#endif // MENUBAR_H
