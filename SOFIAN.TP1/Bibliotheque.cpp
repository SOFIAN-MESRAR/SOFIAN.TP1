#include "Bibliotheque.h"
int Bibliotheque::nbibliotheque = 0;

Bibliotheque::Bibliotheque(std::string nom, int capacite)
    : nom(nom), nblivre(0), capacite(capacite) {
    livres = new Livre * [capacite]; 
    nbibliotheque++;
}

Bibliotheque::Bibliotheque(const Bibliotheque& b)
    : nom(b.nom), nblivre(b.nblivre), capacite(b.capacite) {
    livres = new Livre * [capacite];
    for (int i = 0; i < nblivre; ++i) {
     
        livres[i] = new Livre(*(b.livres[i]));
    }
    nbibliotheque++;
}


Bibliotheque Bibliotheque::operator=(const Bibliotheque& b) {
    if (this != &b) {
        
        for (int i = 0; i < nblivre; ++i) {
            delete livres[i];
        }
        delete[] livres;

       
        nom = b.nom;
        nblivre = b.nblivre;
        capacite = b.capacite;

        livres = new Livre * [capacite];
        for (int i = 0; i < nblivre; ++i) {
            livres[i] = new Livre(*(b.livres[i]));
        }
    }
    return *this;
}


bool Bibliotheque::ajouterLivre(const Livre& l) {
    if (nblivre < capacite) {
        livres[nblivre++] = new Livre(l); 
        return true;
    }
    std::cerr << "Erreur : La bibliotheque est pleine !" << std::endl;
    return false;
}

Bibliotheque& Bibliotheque::operator+=(const Livre& l) {
    ajouterLivre(l);
    return *this;
}

void Bibliotheque::rechercherParTitre(std::string titreRecherche) const {
    bool trouve = false;
    for (int i = 0; i < nblivre; ++i) {
       
        if (livres[i]->estCeQueTitreEst(titreRecherche)) {
            std::cout << "Livre trouve par titre :" << std::endl;
            livres[i]->afficherlivre();
            trouve = true;
        }
    }
    if (!trouve) {
        std::cout << "Aucun livre trouve avec le titre : " << titreRecherche << std::endl;
    }
}


void Bibliotheque::rechercherParId(int idRecherche) const {
    for (int i = 0; i < nblivre; ++i) {
        
        if (livres[i]->estCeQueIdEst(idRecherche)) {
            std::cout << "Livre trouve par ID :" << std::endl;
            livres[i]->afficherlivre();
            return;
        }
    }
    std::cout << "Aucun livre trouve avec l'ID : " << idRecherche << std::endl;
}
Bibliotheque::~Bibliotheque() {
    for (int i = 0; i < nblivre; ++i) {
        delete livres[i];
    }
    delete[] livres;
    nbibliotheque--;
}