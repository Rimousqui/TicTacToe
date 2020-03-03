/*
* Auteur: Patrick Lainesse
* Cours: IFT1166 - A19 - Mardi 16h30
* Ressource utilisee: http://patorjk.com/software/taag/
* ticTacToe.h
* Jeu de tic-tac-toe */

#include "ticTacToe.h"

TicTacToe::TicTacToe()						// constructeur
{
	tour = 0;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			grille[i][j] = ' ';
}

void TicTacToe::jouer()						// demarre le jeu
{
	if (tour == 0)
	{


		cout	<< "\nd888888b d888888b  .o88b.      d888888b  .d8b.   .o88b.      d888888b  .d88b.  d88888b \n"
			<< "`~~88~~'   `88'   d8P  Y8      `~~88~~' d8' `8b d8P  Y8      `~~88~~' .8P  Y8. 88'     \n"
			<< "   88       88    8P              88    88ooo88 8P              88    88    88 88ooooo \n"
			<< "   88       88    8b              88    88~~~88 8b              88    88    88 88~~~~~ \n"
			<< "   88      .88.   Y8b  d8         88    88   88 Y8b  d8         88    `8b  d8' 88.     \n"
			<< "   YP    Y888888P  `Y88P'         YP    YP   YP  `Y88P'         YP     `Y88P'  Y88888P \n\n";
	}

	while (etatJeux() == TicTacToe::etat::CONTINUER)
	{
		afficherTab();

		if (tour % 2 == 0)
			while(!xOMouv('X'))
				cout << "Coordonnees invalides, recommencez.\n";
		else
			while(!xOMouv('O'))
				cout << "Coordonnees invalides, recommencez.\n";
		tour++;
	}

	afficherTab();
	if (etatJeux() == TicTacToe::etat::EGALITE)
		cout << "Partie nulle.\n";
	else if (etatJeux() == TicTacToe::etat::VICTOIRE && tour % 2 != 0)
		cout << "\nFelicitations! X a gagne!\n";
	else if (etatJeux() == TicTacToe::etat::VICTOIRE && tour % 2 == 0)
		cout << "\nFelicitations! O a gagne!\n";

	recommencer();
}

void TicTacToe::afficherTab()const				// affiche le tableau de jeu
{
	cout << "\n";

	for (int i = 0; i < 3; i++)
	{
		if (i == 1 || i == 2)
			cout << "\n ----------------\n";
		for (int j = 0; j < 3; j++)
		{
			switch (j)
			{
				case 0 : cout << i + 1 << " " << grille[i][j] << "  |";
					break;
				case 1: cout << "  " << grille[i][j] << "  |";
					break;
				default: cout << "  " << grille[i][j];
			}
		}
	}
	cout << "\n  A     B     C\n";
}

bool TicTacToe::mouvValid(int x, int y)const 		// determine si un mouvement est valide
{
	if (x < 0 || x > 2 || y < 0 || y > 2)
		return false;
	else if (grille[x][y] != ' ') 
	{
		return false;
	}
	else
		return true;
}

bool TicTacToe::xOMouv(char symbolMouv)			// donne la main au joueur actuel
{
	char abs;
	int ord, abscisse;
		
	cout << "\n\nJoueur " << symbolMouv << ", a vous de jouer. Entrez la lettre et le chiffre correspondant a la position ou vous voulez"
		<< " placer votre " << symbolMouv << " (par exemple: a2) : "; 

	cin >> abs >> ord;

	abs = toupper(abs);

	switch (abs)
	{
	case 'A': abscisse = 0;
		break;
	case 'B': abscisse = 1;
		break;
	default: abscisse = 2;
	}

	ord -= 1;

	if (mouvValid(ord, abscisse))
	{
		grille[ord][abscisse] = symbolMouv;
		return true;
	}
	else
		return false;
}

bool TicTacToe::egal(int x1, int y1, int x2, int y2, int x3, int y3) // simplifie l'ecriture de la verification pour etatJeux
{
	if (grille[x1][y1] == ' ') 			// une case vide ne peut faire partie d'une solution gagnante
		return false;
	else if (grille[x1][y1] == grille[x2][y2] && grille[x2][y2] == grille[x3][y3])
		return true;
	else
		return false;
}

TicTacToe::etat TicTacToe::etatJeux()				// determine l'etat actuel du jeu
{
	if (tour < 5)
		return TicTacToe::etat::CONTINUER;
	else if (egal(0, 0, 0, 1, 0, 2))
		return TicTacToe::etat::VICTOIRE;
	else if (egal(0, 0, 1, 0, 2, 0))
		return TicTacToe::etat::VICTOIRE;
	else if (egal(0, 0, 1, 1, 2, 2))
		return TicTacToe::etat::VICTOIRE;
	else if (egal(0, 1, 1, 1, 2, 1))
		return TicTacToe::etat::VICTOIRE;
	else if (egal(0, 2, 1, 1, 2, 0))
		return TicTacToe::etat::VICTOIRE;
	else if (egal(0, 2, 1, 2, 2, 2))
		return TicTacToe::etat::VICTOIRE;
	else if (egal(1, 0, 1, 1, 1, 2))
		return TicTacToe::etat::VICTOIRE;
	else if (egal(2, 0, 2, 1, 2, 2))
		return TicTacToe::etat::VICTOIRE;
	else if (tour == 9)
		return TicTacToe::etat::EGALITE;
	else
		return TicTacToe::etat::CONTINUER;
}

void TicTacToe::recommencer()
{
	char reponse;

	cout << "\nNouvelle partie? (o/n): ";
	cin >> reponse;

	if (toupper(reponse) != 'N')
	{
		tour = 0;

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				grille[i][j] = ' ';
		jouer();
	}
}

int main()
{
	TicTacToe jeu;

	jeu.jouer();

	return 0;
}

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
