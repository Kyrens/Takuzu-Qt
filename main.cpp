/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

#include "MainMenu.h"
#include "MainMenuPresenter.h"
#include "GridInfo.h"
#include <QApplication>
#include <sys/types.h>
#include <sys/stat.h>
#include <QMessageBox>

#ifdef _WIN32
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

using namespace std;

std::string get_current_dir() {
   char buff[FILENAME_MAX];
   GetCurrentDir( buff, FILENAME_MAX);
   string current_working_dir(buff);
   return current_working_dir;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    struct stat info;
    if(stat("grids", &info) != 0 || !(info.st_mode & S_IFDIR)) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Erreur - Dossier non trouvé");
        msgBox.setText(QString("Le dossier grids n'a pas été trouvé dans le dossier du programme: ").append(QString::fromStdString(get_current_dir())));
        msgBox.exec();
    }
    else {
        a.setQuitOnLastWindowClosed(false);
        MainMenu w;
        w.show();
        return a.exec();
    }

    return 1;
}
