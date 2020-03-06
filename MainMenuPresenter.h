#ifndef MAINMENUPRESENTER_H
#define MAINMENUPRESENTER_H

#include <QObject>
#include "MainMenu.h"
#include "MainMenuModel.h"

class MainMenuModel;

class MainMenuPresenter : public QObject
{
    Q_OBJECT
public:
    MainMenuPresenter(MainMenu * mainMenu);
    ~MainMenuPresenter();
    void connectGridSize();
    void connectGameDifficulty();
    void connectGameStart();

signals:
    void gridSizeChanged(int size);
    void gameDifficultyChanged(int difficulty);

public slots:
    void gameStarted();

private:
    MainMenu * _mainMenu;
    MainMenuModel * _model;
};

#endif // MAINMENUPRESENTER_H
