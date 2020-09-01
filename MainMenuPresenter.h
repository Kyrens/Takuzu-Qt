/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

#ifndef MAINMENUPRESENTER_H
#define MAINMENUPRESENTER_H

#include <QObject>
#include "MainMenu.h"
#include "MainMenuModel.h"
#include "GridInfo.h"
#include <QString>

class MainMenu;
class MainMenuModel;

class MainMenuPresenter : public QObject
{
    Q_OBJECT
public:
    MainMenuPresenter(MainMenu * mainMenu);
    ~MainMenuPresenter();
    void refreshGrids(GridInfo ** grids, int gridsCount);
    GridInfo * getSelectedGrid();

signals:

public slots:
    void gameStarted();
    void sizeChanged(QString size);

private:
    MainMenu * _mainMenu;
    MainMenuModel * _model;
    GridInfo ** _grids = nullptr;
    int _gridsCount = 0;
};

#endif // MAINMENUPRESENTER_H
