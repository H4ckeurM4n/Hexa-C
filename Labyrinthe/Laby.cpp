#include <iostream>
#include <vector>
#include <string>

using namespace std;

void afficherMap(const vector<vector<char>>& map) {
    cout << "+---+---+---+---+---+" << endl; // Bordure supérieure
    for (const auto& ligne : map) {
        cout << "| "; // Bordure gauche
        for (char caseMap : ligne) {
            cout << caseMap << " | "; // Séparateurs de cellule
        }
        cout << endl;
        cout << "+---+---+---+---+---+" << endl; // Séparateurs de ligne et bordure inférieure
    }
}

bool deplacerJoueur(vector<vector<char>>& map, int& posX, int& posY, const string& commande) {
    int nouvellePosX = posX;
    int nouvellePosY = posY;
    
    if (commande == "haut" && posX > 0) nouvellePosX--;
    else if (commande == "bas" && posX < map.size() - 1) nouvellePosX++;
    else if (commande == "gauche" && posY > 0) nouvellePosY--;
    else if (commande == "droite" && posY < map[0].size() - 1) nouvellePosY++;
    
    if (map[nouvellePosX][nouvellePosY] != 'X') {
        map[posX][posY] = ' ';
        posX = nouvellePosX;
        posY = nouvellePosY;
        map[posX][posY] = 'P';
        return true;
    } else {
        return false;
    }
}

int main() {
    vector<vector<char>> map = {
        {' ', ' ', ' ', 'X', ' '},
        {'X', 'X', ' ', 'X', 'X'},
        {' ', ' ', ' ', ' ', ' '},
        {' ', 'X', ' ', 'X', 'X'},
        {'X', 'X', ' ', ' ', 'P'}
    };

    int posX = 4, posY = 4;
    string commande;
    bool jeuEnCours = true;

    while (jeuEnCours) {
        afficherMap(map);
        cout << "Entrez une commande (haut, bas, droite, gauche) ou 'quitter' pour sortir: ";
        cin >> commande;

        if (commande == "quitter") break;

        if (!deplacerJoueur(map, posX, posY, commande)) {
            cout << "Vous ne pouvez pas traverser un mur!" << endl;
        }
    }

    return 0;
}
