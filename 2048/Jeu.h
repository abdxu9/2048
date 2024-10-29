#pragma once
#include<iostream>
using namespace std;
#include "Grille.h"
class Jeu
{
private:
	Grille m_grille;
	int score;
public:
	Jeu();
	void start();
	void movePlayer();

};

