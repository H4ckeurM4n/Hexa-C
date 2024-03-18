#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Fonction pour afficher la carte
void afficherMap(const vector<vector<char>>& map) {
    for (const auto& ligne : map) {
        for (char caseMap : ligne) {
            cout << caseMap << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> map = {
        {' ', ' ', ' ', 'X', ' '},
        {' ', 'X', ' ', 'X', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', 'X', ' ', 'X', ' '},
        {' ', ' ', ' ', ' ', 'P'} // Position initiale du joueur
    };

    int posX = 4; // Position initiale X du joueur
    int posY = 4; // Position initiale Y du joueur

    string commande;
    bool jeuEnCours = true;

    while (jeuEnCours) {
        afficherMap(map);
        cout << "Entrez une commande (haut, bas, droite, gauche) ou 'quitter' pour sortir: ";
        cin >> commande;

        if (commande == "quitter") {
            jeuEnCours = false;
            continue;
        }

        // Mise à jour de la position en fonction de l'input
        int nouvellePosX = posX;
        int nouvellePosY = posY;

        if (commande == "haut" && posX > 0) nouvellePosX--;
        else if (commande == "bas" && posX < map.size() - 1) nouvellePosX++;
        else if (commande == "gauche" && posY > 0) nouvellePosY--;
        else if (commande == "droite" && posY < map[0].size() - 1) nouvellePosY++;

        // Vérifier si la nouvelle position est un mur
        if (map[nouvellePosX][nouvellePosY] == 'X') {
            cout << "Vous ne pouvez pas traverser un mur!" << endl;
            continue;
        }

        // Mise à jour de la carte avec la nouvelle position du joueur
        map[posX][posY] = ' ';
        posX = nouvellePosX;
        posY = nouvellePosY;
        map[posX][posY] = 'P';
    }

    return 0;
}
