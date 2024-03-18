#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string sha256(const std::string str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    
    std::string output;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        char buffer[3];
        sprintf(buffer, "%02x", hash[i]);
        output += buffer;
    }
    
    return output;
}

int main() {
    std::string input;
    std::cout << "Entrez une chaîne de caractères à hacher avec SHA-256: ";
    std::getline(std::cin, input);
    
    std::string output = sha256(input);
    std::cout << "La valeur de hachage SHA-256 pour \"" << input << "\" est : " << output << std::endl;
    
    return 0;
}
