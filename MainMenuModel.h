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
