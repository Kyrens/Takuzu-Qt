/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

#ifndef MENUBAR_H
#define MENUBAR_H

#include <QObject>
#include <QWidget>
#include "GameWindowPresenter.h"

class GameWindowPresenter;

class MenuBar : public QObject
{
    Q_OBJECT
public:
    MenuBar(QWidget * parent, GameWindowPresenter * presenter = nullptr);
    ~MenuBar();

private:
    QWidget * _parent;
    GameWindowPresenter * _presenter;

public slots:
    void newGame();
    void quit();
    void rules();
    void about();

};

#endif // MENUBAR_H
