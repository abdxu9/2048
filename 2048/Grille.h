#pragma once
#include "Cellule.h"
#include<iostream>
#include <random>
using namespace std;
class Grille
{
private:
	int m_size;
	Cellule** m_cells;
public: 
	Grille();
	Grille(int size);
	void setSize(int size);
	void deplacerHaut();
	void deplacerBas();
	void deplacerDroite();
	void deplacerGauche();
	bool empty();
	void genererCaseAl();
	friend ostream& operator<<(ostream& o, const Grille& g);


};

