// SOFIAN.TP1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Date.h"
#include "Livre.h"
#include "Bibliotheque.h"
using namespace std;

int main()
{
	Date d1(2, 29, 2020);
	Date d2(3, 1, 2020);
	if(d1 < d2)
		std::cout << "d1 est INFIRIEUR d2" << std::endl;
	else
		std::cout << "d1 SEPERIEUR d2" << std::endl;
	Date d3(2, 29, 2020);
	if(d1 == d3)
		std::cout << "d1 est EGAL d3" << std::endl;
	else
		std::cout << "d1 est DIFFERENT d3" << std::endl;

	Livre livre1("C++ ", "man", d1);
	Livre livre2(" Code", "Martin", d2);
	Livre livre3("Design ", " Four", d3);

	
	livre1.ajouterNote(18);
	livre1.ajouterNote(15);
	livre1.ajouterNote(19);

	livre2.ajouterNote(14);
	livre2.ajouterNote(16);

	std::cout << "Test des livres :" << std::endl;
	livre1.afficherlivre();
	livre2.afficherlivre();

	std::cout << "Nombre total d'instances de livres : " << Livre::nbinstans << std::endl;
	std::cout << std::endl;

	
	Bibliotheque maBiblio("Bibliotheque Universitaire", 10);

	
	maBiblio.ajouterLivre(livre1);
	maBiblio += livre2; 
	maBiblio += livre3;

	std::cout << "Nombre de livres dans la bibliotheque : " << maBiblio.nblivre << std::endl;
	std::cout << std::endl;

	
	
	std::cout << "Recherche par titre (' Code') :" << std::endl;
	maBiblio.rechercherParTitre("Code");

	std::cout << "\nRecherche par ID (ID = 1) :" << std::endl;
	maBiblio.rechercherParId(1);

	std::cout << "\nRecherche d'un livre inexistant :" << std::endl;
	maBiblio.rechercherParTitre("Python Avance");




	return 0;
}









// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
