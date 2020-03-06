#ifndef MAINMENUMODEL_H
#define MAINMENUMODEL_H

#include <QObject>
#include "MainMenuPresenter.h"

class MainMenuModel : public QObject
{
public:
    MainMenuModel(MainMenuPresenter * presenter);

public slots:
    void changeSize(int size);
    void changeDifficulty(int difficulty);

private:
    MainMenuPresenter * _presenter;
};

#endif // MAINMENUMODEL_H
