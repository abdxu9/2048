#include "Grille.h"

Grille::Grille():m_size(0), m_cells(nullptr){

}
Grille::Grille(int size) : m_size(size) {
    // Allouer un tableau de pointeurs pour chaque ligne
    m_cells = new Cellule * [m_size];


    for (int i = 0; i < m_size; i++) {
        // Allouer un tableau de Cellule pour chaque colonne
        m_cells[i] = new Cellule[m_size];

        // Initialiser chaque Cellule de la grille à 0
        for (int j = 0; j < m_size; j++) {
            m_cells[i][j].setVal(0);
        }
    }

    this->genererCaseAl();
}

void Grille::setSize(int size) {
    this->m_size = size;
    m_cells = new Cellule * [m_size];


    for (int i = 0; i < m_size; i++) {
        // Allouer un tableau de Cellule pour chaque colonne
        m_cells[i] = new Cellule[m_size];

        // Initialiser chaque Cellule de la grille à 0
        for (int j = 0; j < m_size; j++) {
            m_cells[i][j].setVal(0);
        }
    }

    this->genererCaseAl();

}

void Grille::genererCaseAl() {
    random_device rd;              // Générateur de nombres aléatoires pour une graine
    mt19937 gen(rd());             // Mersenne Twister pour générer des nombres aléatoires

    // Distribution de nombres pour les indices de la grille
    uniform_int_distribution<> dist(0, m_size - 1); // Plage [0, m_size-1]

    // Générer un indice aléatoire pour la ligne et la colonne
    int random_row = dist(gen);
    int random_col = dist(gen);
    cout << "Position aleatoire : (" << random_row << ", " << random_col << ")" << endl;

    // Mettre la valeur 2 dans la cellule aléatoire
    m_cells[random_row][random_col].setVal(2);
}

void Grille::deplacerHaut() {
    for (int i = m_size-2; i >= 0; i--) {  // Parcours à partir de la deuxième ligne
        for (int j = 0; j < m_size; j++) {
            // Fusionne la cellule actuelle avec celle située juste au-dessus
            m_cells[i][j].merge(m_cells[i+1][j]);
        }
    }
}

void Grille::deplacerDroite() {
    for (int i = 0; i < m_size; i++) {  // Parcours à partir de la deuxième ligne
        for (int j = m_size - 2; j >= 0; j--) {
            // Fusionne la cellule actuelle avec celle située juste au-dessus
            m_cells[i][j].merge(m_cells[i][j+1]);
        }
    }
}

void Grille::deplacerGauche() {
    for (int i = 0; i < m_size; i++) {  // Parcours à partir de la deuxième ligne
        for (int j = 0; j < m_size - 1; j++) {
            // Fusionne la cellule actuelle avec celle située juste au-dessus
            m_cells[i][j+1].merge(m_cells[i][j]);
        }
    }
}

void Grille::deplacerBas() {
    for (int i = 0; i < m_size - 1; i++) {
        for (int j = 0; j < m_size; j++) {
            m_cells[i + 1][j].merge(m_cells[i][j]);
        }
    }
}

bool Grille::empty() {
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            if (m_cells[i][j].getVal() == 0) {
                return false;
            }
        }
    }
    return true;
}

ostream& operator<<(ostream& o, const Grille& g) {
    for (int i = 0; i < g.m_size; i++) {
        for (int j = 0; j < g.m_size; j++) {  // Correction : j++ au lieu de i++
            o << g.m_cells[i][j] << "\t";  // Correction : "\t" au lieu de "/t"
        }
        o << endl;
    }
    return o;
}

