/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

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
    void activateDifficulty(Difficulty diff);
    void disableAllDifficulties();
    int getSelectedSize();
    bool isDifficultySelected(Difficulty diff);
    void addSize(int size);
    MainMenuPresenter * _presenter;

protected:
    void closeEvent(QCloseEvent * event);

private:
    Ui::MainMenu *ui;
    QRadioButton * getRadioButton(Difficulty diff);
};

#endif // MAINMENU_H
