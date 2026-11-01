#pragma once
#include <iostream>
using namespace std;
#include "Livre.h"
class Bibliotheque
{
private:
	string nom;
	Livre** livres;
	int capacite;
public:
	int nblivre;
	static int nbibliotheque;
public:
	Bibliotheque(string, int);
	Bibliotheque(const Bibliotheque& b);
	Bibliotheque operator=(const Bibliotheque& b);
	bool ajouterLivre(const Livre& l);
	Bibliotheque& operator+=(const Livre& l);
	void rechercherParTitre(string titre) const;
	void rechercherParId(int id) const;
	~Bibliotheque();
};

