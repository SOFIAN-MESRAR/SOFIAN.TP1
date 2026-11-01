#pragma once
class Date
{
private:
	int mois;
	int jours;
	int annee;
public:
	Date(int , int , int );
	static bool estbissextile(int annee);
	static bool estvalide(int, int, int) ;
	bool operator==(const Date& d) const;
	bool operator<(const Date& d) const;
	void afficher() const;
	~Date();
};

