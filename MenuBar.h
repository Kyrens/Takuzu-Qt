#ifndef MENUBAR_H
#define MENUBAR_H

#include <QObject>

class MenuBar : public QObject
{
    Q_OBJECT

public slots:
    void newGame();
    void quit();
    void rules();
    void about();
};

#endif // MENUBAR_H
