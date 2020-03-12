#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "QPushButton"
#include "QComboBox"
#include "QRadioButton"
#include "GridInfo.h"

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

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
