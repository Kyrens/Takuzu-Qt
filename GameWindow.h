/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "GridInfo.h"
#include "GameWindowPresenter.h"
#include <QGridLayout>
#include "MenuBar.h"
#include "GridCellToken.h"

class MenuBar;

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
    void refreshToken(int i, int j, char c);
    void refreshLine(int line, bool * errors, int size, int whiteLeft, int blackLeft);
    void refreshColumn(int column, bool * errors, int size, int whiteLeft, int blackLeft);
    void toggleUndoButton(bool enable);
    void updateUndoCount(int undoCount);
    void updateStatus(bool error);
    void gameFinished(int undoCount, int seconds);

protected:
    void closeEvent(QCloseEvent * event);

private:
    Ui::GameWindow *ui;
    GameWindowPresenter * _presenter = nullptr;
    bool keepError(QGridLayout * gridLayout, int i, int j, int size);
    MenuBar * _menuBar;
    void refreshTokensStyle(int size, TokenStyle style);

private slots:
    void clickToken();
    void clickUndo();

    void styleCircle();
    void styleSquare();
};

#endif // GAMEWINDOW_H
