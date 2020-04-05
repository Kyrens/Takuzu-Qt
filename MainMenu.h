#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>
#include <QRadioButton>
#include "GridInfo.h"
#include "MainMenuPresenter.h"

class MainMenuPresenter;

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();
    QPushButton * getStartButton();
    QComboBox * getSizeComboBox();
    void activateDifficulty(Difficulty diff);
    void disableAllDifficulties();
    QRadioButton * getRadioButton(Difficulty diff);
    MainMenuPresenter * _presenter;

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
