#include "Date.h"
#include <iostream>

Date::Date(int mois, int jours, int annee)
{   this->mois = mois;
	this->jours = jours;
	this->annee = annee;
}

bool Date::estbissextile(int annee)
{
    return (annee % 4 == 0 && (annee % 100 != 0 || annee % 400 == 0));
}



bool Date::estvalide(int jours, int mois, int annee) 
{
	int joursParMois[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
   if(jours < 1 || jours > 31 || mois < 1 || mois > 12 || annee > 2026)
		return false;
	if (mois == 2 && estbissextile(annee) && jours > 29)
		return false;
	return true;
}

bool Date::operator==(const Date& d) const
{
	return (this->jours == d.jours && this->mois == d.mois && this->annee == d.annee);
}

bool Date::operator<(const Date& d) const
{
    if (this->annee < d.annee) {
        return true; 
    }
    else if (this->annee > d.annee) {
        return false;
    }

    if (this->mois < d.mois) {
        return true; 
    }
    else if (this->mois > d.mois) {
        return false;
    }

   
    if (this->jours < d.jours) {
        return true; 
    }
    else {
        return false; 
    }
}

void Date::afficher() const
{
    std::cout << (jours < 10 ? "0" : "") << jours << "/"
        << (mois < 10 ? "0" : "") << mois << "/"
        << annee << std::endl;
}


Date::~Date()
{
}
