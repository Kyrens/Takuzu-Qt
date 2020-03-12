#ifndef MAINMENUPRESENTER_H
#define MAINMENUPRESENTER_H

#include <QObject>
#include "MainMenu.h"
#include "MainMenuModel.h"
#include "GridInfo.h"
#include <QString>

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
