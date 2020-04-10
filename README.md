# Le projet

## Fonctionnalités implémentées
- Barre de menu pour créer une nouvelle partie, quitter, avoir de l'aide etc...
- Plusieurs choix de tailles et de difficultés (grilles de tailles 6x6, 8x8, 10x10, 14x14 et difficultés faciles ou difficiles)
- Possibilité d'ajouter des grilles personnalisées dans le dossier grids
- Chronomètre indiquant le temps de jeu
- Possbilité de revenir en arrière avec un compteur de retours en arrière
- Affichage d'erreurs si plus de 3 jetons de la même couleur se suivent
- Affichage des jetons restants à placer sur les côtés de la grille
- Affichage d'une erreur si 2 lignes ou 2 colonnes sont identiques
- Possibilité de changer le style des jetons
- Retour au menu principal possible à tout moment

## Fonctionnalités non implémentée
- Système de sauvegarde et chargement de parties
- Editeur de grille afin de faciliter l'implémentation de nouvelles grilles
- Importation de styles personnalisés
- Inteliligence artificielle afin de résoudre la grille et aider le joueur
- Tableau des scores


## Particularités de l'interface
- Interface simple, épurée, facile à comprendre
- Barre de menu pratique
- Adaptation de l'interface en fonction des fichiers grilles, de la taille etc...
- Indicateurs colorés intuitifs (vert pour bien, rouge pour mauvais)
- Menu principal séparé de la fenêtre de jeu
- Retours automatiques au menu principal

## Répartition du travail
Ritchie a travaillé sur l'interface, la présentation du jeu, la vue surtout et Nicolas a travaillé plutôt sur les modèles et les mécaniques de jeu. Cependant, si le travail était conséquent (trop de travail sur un composant), nous nous sommes facilement adaptés à la situation afin d'être le plus efficace possible.

## Choix effectués concernant l'ergonomie
Nous avons choisi de faire une interface simple et compréhensible. Pour cela, nous avons gardés des couleurs monochromes sauf pour les indicateurs d'erreurs et de réponses correctes où nous avons choisi des couleurs intuitives (vert et rouge). Nous avons implémenté une barre de menu afin de naviguer et obtenir de l'aide facilement.

## Choix de modélisation
Nous avons choisi le patron d'architecture Modèle-Vue-Présentation pour les deux fenêtres.

# Structure du projet

## Compilation
Afin de compiler le projet, il faut se placer dans le dossier du projet et faire:
```
qmake
```
puis:
```
make
```

L'éxecutable est alors nommé "Takuzu"

## Fichiers et dossiers

- **GameWindow.cpp et GameWindow.h**: Vue pour la fenêtre du jeu (celle où il ya la grille)
- **GameWindow.ui**: Interface de la vue du jeu
- **GameWindowModel.cpp et GameWindowMode.h**: Modèle pour la fenêtre de jeu
- **GameWindowPresenter.cpp et GameWindowPresenter.h**: Présentation pour la fenêtre du jeu
- **Grid.cpp** et **Grid.h**: Structure contenant une grille de Takuzu et ses cellules
- **GridCellLabel.cpp** et **GridCellLabel.h**: Widget qui gère l'affichage des jetons restants à placer
- **GridCellToken.cpp** et **GridCellToken.h**: Widget qui gère l'affichage des jetons dans la grille de jeu
- **GridInfo.cpp** et **GridInfo.h**: Structure contenant les informations d'un fichier texte de grille (fichier, taille et difficulté)
- **grids**: Dossier contenant les fichiers texte des grilles de Takuzu
- **GridsList.cpp** et **GridsList.h**: Structure contenant les informations d'un fichier de grilles ainsi que toutes les grilles de ce fichier
- **main.cpp**: Fichier source contenant la fonction main du programme
- **MainMenu.cpp** et **MainMenu.h**: Vue du menu principal
- **MainMenu.ui**: Interface du menu principal
- **MainMenuModel.cpp** et **MainMenuModel.h**: Modèle du menu principal
- **MainMenuPresenter.cpp** et **MainMenuPresenter.h**: Présentation du menu principal
- **MenuBar.cpp** et **MenuBar.h**: Fichier source contenant les fonctions pour la barre de menu des fenêtres
- **Takuzu.pro**: Fichier contenant les informations sur le projet QtCreator
