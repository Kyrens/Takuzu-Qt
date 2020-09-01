/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

#ifndef MAINMENUMODEL_H
#define MAINMENUMODEL_H

#include <QObject>
#include "MainMenuPresenter.h"
#include "GridInfo.h"

class MainMenuPresenter;

class MainMenuModel : public QObject
{
public:
    MainMenuModel(MainMenuPresenter * presenter);
    ~MainMenuModel();


public slots:
    void changeSize(int size);
    void changeDifficulty(int difficulty);

private:
    MainMenuPresenter * _presenter;
    void loadGrids();
    GridInfo ** _grids;
    int _gridsCount;
};

#endif // MAINMENUMODEL_H
