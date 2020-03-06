#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "QPushButton"

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

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
