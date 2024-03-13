#include <iostream>
#include <string>

unsigned int hashFunction(const std::string& input) {
    const unsigned int prime = 31; // Un nombre premier pour le hachage polynomial
    unsigned int hashValue = 0;
    
    for (char c : input) {
        hashValue = hashValue * prime + c;
    }
    
    return hashValue;
}

int main() {
    std::string input;
    std::cout << "Entrez une chaîne de caractères à hacher : ";
    std::getline(std::cin, input);
    
    unsigned int hashValue = hashFunction(input);
    std::cout << "La valeur de hachage pour \"" << input << "\" est : " << hashValue << std::endl;
    
    return 0;
}
