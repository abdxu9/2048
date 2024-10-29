#include "Jeu.h"

Jeu::Jeu() {
	m_grille.setSize(6);
	score = 0;
}


void Jeu::movePlayer() {
	string m;
	for(int i = 0; i < 15; i++){
		cout << this->m_grille << endl;
		cin >> m;
		if(m=="G"){
			m_grille.deplacerGauche();
			m_grille.genererCaseAl();
		}
		if (m == "D"){
			m_grille.deplacerDroite();
			m_grille.genererCaseAl();
		}
		if (m == "H") {
			m_grille.deplacerHaut();
			m_grille.genererCaseAl();
		}
		if (m == "B") {
			m_grille.deplacerBas();
			m_grille.genererCaseAl();
		}
	}
}