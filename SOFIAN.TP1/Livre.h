#pragma once
#include <iostream>
#include "Date.h"
using namespace std;
class Livre
{ private:
	const int id;
	string titre;
	string auteur;
	Date parution;
	int* note;
	int nbnote;
	static int compteur;
	public:
    static int nbinstans;
public:
	Livre(string, string, Date);
	Livre(const Livre& l);
	Livre operator=(const Livre& l);
	double calculermoyenne() const;
	void afficherlivre() const;
	void ajouterNote(int);
	bool estCeQueTitreEst(string t) const;
	bool estCeQueIdEst(int idRecherche) const;

	~Livre();
};

