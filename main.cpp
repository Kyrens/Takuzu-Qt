#include "MainMenu.h"
#include "MainMenuPresenter.h"
#include "GridInfo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu w;
    MainMenuPresenter mmp(&w);
    GridInfo("6_easy.txt");
    w.show();

    return a.exec();
}
