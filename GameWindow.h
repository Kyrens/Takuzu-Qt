#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "GridInfo.h"
#include "GameWindowPresenter.h"

namespace Ui {
class GameWindow;
}

class GameWindowPresenter;

class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    GameWindow(const char * fileName, QWidget *parent = nullptr);
    ~GameWindow();
    void setTime(int min, int sec);
    void showInitGrid(int size);

private:
    Ui::GameWindow *ui;
    GameWindowPresenter * _presenter;
};

#endif // GAMEWINDOW_H
