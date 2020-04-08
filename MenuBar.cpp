#include "MenuBar.h"

#include <cstdlib>
#include <QMessageBox>

MenuBar::MenuBar(GameWindowPresenter * presenter) {
    _presenter = presenter;
}

MenuBar::~MenuBar() {}

void MenuBar::newGame() {
    _presenter->goToMainMenu();
}

void MenuBar::quit() {
    std::exit(0);
}

void MenuBar::rules() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Règles du jeu");
    msgBox.setText("Le but du Takuzu est de remplir la grille avec des jetons noirs et blancs. Sur chaque ligne et chaque colonne, il doit y avoir un nombre égal de jetons blancs et noirs et un maximum de 2 jetons de la même couleur peuvent se suivre.\n\nInterface:\n- Des jetons entourés en rouge signifie que plus de 2 jetons de la même couleur sont à la suite\n- A droite et en dessous de la grille sont indiqués le nombre de jetons de la même couleur que le fond qu'il reste à placer. Un nombre en rouge signifie qu'il y a trop de jetons sur la ligne ou la colonne.\n- Cliquez gauche sur le jeton afin de changer sa couleur");
    msgBox.exec();
}

void MenuBar::about() {
    QMessageBox msgBox;
    msgBox.setText("Un programme pour jouer au Takuzu\n\nAuteurs: Ritchie Kichenassamy et Nicolas Virard");
    msgBox.exec();
}
