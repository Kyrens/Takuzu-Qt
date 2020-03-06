#ifndef MAINMENUPRESENTER_H
#define MAINMENUPRESENTER_H

#include <QObject>
#include "MainMenu.h"

class MainMenuPresenter : public QObject
{
    Q_OBJECT
public:
    MainMenuPresenter(MainMenu * mainMenu);
    void connectGridSize();
    void connectGameDifficulty();

signals:
    void gridSizeChanged(int size);
    void gameDifficultyChanged(int difficulty);
public slots:

private:
    MainMenu * _mainMenu;
};

#endif // MAINMENUPRESENTER_H
