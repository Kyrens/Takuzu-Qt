#include "MainMenu.h"
#include "MainMenuPresenter.h"
#include "GridInfo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    MainMenu w;
    w.show();

    return a.exec();
}
