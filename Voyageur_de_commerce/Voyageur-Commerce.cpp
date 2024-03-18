#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <numeric>
#include <chrono>

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
        auto start = std::chrono::high_resolution_clock::now();

std::vector<std::vector<int>> distances = {
    {0, 10, 20, 30, 40, 50, 60, 70, 80, 90},
    {10, 0, 15, 25, 35, 45, 55, 65, 75, 85},
    {20, 15, 0, 10, 20, 30, 40, 50, 60, 70},
    {30, 25, 10, 0, 10, 20, 30, 40, 50, 60},
    {40, 35, 20, 10, 0, 10, 20, 30, 40, 50},
    {50, 45, 30, 20, 10, 0, 10, 20, 30, 40},
    {60, 55, 40, 30, 20, 10, 0, 10, 20, 30},
    {70, 65, 50, 40, 30, 20, 10, 0, 10, 20},
    {80, 75, 60, 50, 40, 30, 20, 10, 0, 10},
    {90, 85, 70, 60, 50, 40, 30, 20, 10, 0}
};

    std::vector<int> villes(distances.size());
    std::iota(villes.begin(), villes.end(), 0);

    std::vector<int> chemin;
    chemin.push_back(0); 
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


    distanceTotale += distances[chemin.back()][chemin.front()];

    std::cout << "Chemin: ";
    for (int ville : chemin) {
        std::cout << ville << " ";
    }
    std::cout << "\nDistance totale: " << distanceTotale << std::endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    
    std::cout << "Temps d'exécution: " << duration.count() << " millisecondes" << std::endl;
    return 0;
}
