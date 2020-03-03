/*
* Auteur: Patrick Lainesse
* Cours: IFT1166 - A19 - Mardi 16h30
* Ressource utilisee: http://patorjk.com/software/taag/
* ticTacToe.h
* Fichier d'en-tete pour la classe du jeu de tic-tac-toe */

#include <iostream>

using namespace std;

class TicTacToe
{
private:
	int tour;
	char grille[3][3] = { ' ' };		// initialisee pour eviter l'avertissement a la compilation

public:
	TicTacToe();
	void jouer();
	void afficherTab()const;
	bool mouvValid(int x, int y)const;
	bool xOMouv(char symbolMouv);
	bool egal(int x1, int y1, int x2, int y2, int x3, int y3);
	enum class etat { VICTOIRE, EGALITE, CONTINUER };

	etat etatJeux();
	void recommencer();
};

/* Resultat d'execution:

d888888b d888888b  .o88b.      d888888b  .d8b.   .o88b.      d888888b  .d88b.  d88888b
`~~88~~'   `88'   d8P  Y8      `~~88~~' d8' `8b d8P  Y8      `~~88~~' .8P  Y8. 88'
   88       88    8P              88    88ooo88 8P              88    88    88 88ooooo
   88       88    8b              88    88~~~88 8b              88    88    88 88~~~~~
   88      .88.   Y8b  d8         88    88   88 Y8b  d8         88    `8b  d8' 88.
   YP    Y888888P  `Y88P'         YP    YP   YP  `Y88P'         YP     `Y88P'  Y88888P


1    |     |
 ----------------
2    |     |
 ----------------
3    |     |
  A     B     C


Joueur X, a vous de jouer. Entrez la lettre et le chiffre correspondant a la position ou vous voulez placer votre X (par exemple: a2) : b1

1    |  X  |
 ----------------
2    |     |
 ----------------
3    |     |
  A     B     C


Joueur O, a vous de jouer. Entrez la lettre et le chiffre correspondant a la position ou vous voulez placer votre O (par exemple: a2) : b2

1    |  X  |
 ----------------
2    |  O  |
 ----------------
3    |     |
  A     B     C


Joueur X, a vous de jouer. Entrez la lettre et le chiffre correspondant a la position ou vous voulez placer votre X (par exemple: a2) : c1

1    |  X  |  X
 ----------------
2    |  O  |
 ----------------
3    |     |
  A     B     C


Joueur O, a vous de jouer. Entrez la lettre et le chiffre correspondant a la position ou vous voulez placer votre O (par exemple: a2) : a1

1 O  |  X  |  X
 ----------------
2    |  O  |
 ----------------
3    |     |
  A     B     C


Joueur X, a vous de jouer. Entrez la lettre et le chiffre correspondant a la position ou vous voulez placer votre X (par exemple: a2) : c3

1 O  |  X  |  X
 ----------------
2    |  O  |
 ----------------
3    |     |  X
  A     B     C


Joueur O, a vous de jouer. Entrez la lettre et le chiffre correspondant a la position ou vous voulez placer votre O (par exemple: a2) : b3

1 O  |  X  |  X
 ----------------
2    |  O  |
 ----------------
3    |  O  |  X
  A     B     C


Joueur X, a vous de jouer. Entrez la lettre et le chiffre correspondant a la position ou vous voulez placer votre X (par exemple: a2) : c2

1 O  |  X  |  X
 ----------------
2    |  O  |  X
 ----------------
3    |  O  |  X
  A     B     C

Felicitations! X a gagne!

Nouvelle partie? (o/n): n

Sortie de C:\Users\Patrick\Desktop\Notes de cours\IFT1166\tp2\1110\tp2\Debug\tp2.exe (processus 5320) avec le code 0.
Pour fermer automatiquement la console quand le débogage s'arrête, activez Outils->Options->Débogage->Fermer automatiquement la console à l'arrêt du débogage.
Appuyez sur une touche pour fermer cette fenêtre.

*/