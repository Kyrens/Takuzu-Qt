#ifndef GAMEWINDOWPRESENTER_H
#define GAMEWINDOWPRESENTER_H

#include <QObject>
#include "GameWindow.h"
#include "GameWindowModel.h"
#include <QTimer>

class GameWindow;
class GameWindowModel;

class GameWindowPresenter : public QObject
{
    Q_OBJECT
public:
    GameWindowPresenter(GameWindow * gameWindow, const char * fileName, QObject *parent = nullptr);
    ~GameWindowPresenter();
    void clickCell(int i, int j);
    char getCell(int i, int j);
    void undoLastAction();
    char getCellValue(int i, int j);

private:
    GameWindow * _view;
    GameWindowModel * _model;
    bool * _errorsTmp;
    void updateCellErrors(int row, int col);
    void refreshCell(int i, int j);
    bool * _linesValid;
    bool * _columnsValid;
    void verifyGrid();
    QTimer * _timer;

signals:

public slots:
    void timeUpdate();
    void goToMainMenu();
};

#endif // GAMEWINDOWPRESENTER_H
