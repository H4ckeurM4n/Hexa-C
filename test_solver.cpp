#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <numeric>

int trouverPlusProcheVoisin(int villeActuelle, const std::vector<int>& villesRestantes, const std::vector<std::vector<int>>& distances) {
    int minDistance = std::numeric_limits<int>::max();
    int villePlusProche = -1;
    for (int ville : villesRestantes) {
        if (distances[villeActuelle][ville] < minDistance) {
            minDistance = distances[villeActuelle][ville];
            villePlusProche = ville;
        }
    }
    return villePlusProche;
}

int main() {
    // Exemple de matrice de distances entre les villes
    std::vector<std::vector<int>> distances = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    std::vector<int> villes(distances.size());
    std::iota(villes.begin(), villes.end(), 0); // Initialise les villes de 0 à N-1

    std::vector<int> chemin; // Chemin du voyageur
    chemin.push_back(0); // Commence toujours par la ville 0 pour cet exemple
    int distanceTotale = 0;

    while (chemin.size() < distances.size()) {
        int villeActuelle = chemin.back();
        std::vector<int> villesRestantes;
        std::copy_if(villes.begin(), villes.end(), std::back_inserter(villesRestantes),
                     [&chemin](int ville) { return std::find(chemin.begin(), chemin.end(), ville) == chemin.end(); });

        int villePlusProche = trouverPlusProcheVoisin(villeActuelle, villesRestantes, distances);
        chemin.push_back(villePlusProche);
        distanceTotale += distances[villeActuelle][villePlusProche];
    }

    // Ajouter la distance pour revenir à la ville de départ
    distanceTotale += distances[chemin.back()][chemin.front()];

    std::cout << "Chemin: ";
    for (int ville : chemin) {
        std::cout << ville << " ";
    }
    std::cout << "\nDistance totale: " << distanceTotale << std::endl;

    return 0;
}
