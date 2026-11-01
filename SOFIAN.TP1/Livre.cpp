#include "Livre.h"
int Livre::compteur = 1;
int Livre::nbinstans = 0;
Livre::Livre(string titre, string auteur, Date parution)
	:id(compteur++),titre(titre),auteur(auteur),parution(parution),nbnote(0)
{
	this->note = new int[10];
	Livre::nbinstans++;
}

Livre::Livre(const Livre& l)
	:id(compteur++), titre(l.titre), auteur(l.auteur), parution(l.parution), nbnote(l.nbnote)
{
	this->note = new int[l.nbnote];
	for (int i = 0; i < l.nbnote; i++) {
		note[i] = l.note[i];
	}
	Livre::nbinstans++;
}

Livre Livre::operator=(const Livre& l)
{
	if (this != &l) {
		delete[] note; 

		this->titre = l.titre;
		this->auteur = l.auteur;
		this->parution = l.parution;
		this->nbnote = l.nbnote;

		this->note = new int[l.nbnote];
		for (int i = 0; i < l.nbnote; i++) {
			note[i] = l.note[i];
		}
	}
	return *this;
}
double Livre::calculermoyenne() const
{
	if (nbnote == 0) return 0;
	double somme = 0;
	for (int i = 0; i < nbnote; i++) {
		somme += note[i];
	}
	return somme/nbnote;
}

void Livre::afficherlivre() const
{
	std::cout << "Livre ID: " << id << "  Titre: " << titre
		<< "  Auteur: " << auteur << "  Parution: ";
	parution.afficher();
	std::cout << "Moyenne des notes: " << calculermoyenne()
		<< " (Nombre de notes: " << nbnote << ")" << std::endl;
}
void Livre::ajouterNote(int noteValue) {
    if (noteValue >= 0 && noteValue <= 20) {
        if (nbnote < 10) {
            note[nbnote++] = noteValue;
        } else {
            std::cerr << "Erreur : Nombre maximum de notes atteint." << std::endl;
        }
    }
    
}

bool Livre::estCeQueTitreEst(std::string t) const {
	return (this->titre == t);
}

bool Livre::estCeQueIdEst(int idRecherche) const {
	return (this->id == idRecherche);
}

Livre::~Livre()
{
	delete[] note;
Livre::nbinstans--;
}
