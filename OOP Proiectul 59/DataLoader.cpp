#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

void DataLoader::loadFromFile(const std::string& filename, std::vector<Buyer>& buyers, std::vector<Seller>& sellers, std::vector<Product>& products) {
    std::ifstream file(filename);
    std::string line;
    enum Section { NONE, SELLERS, BUYERS, PRODUCTS } currentSection = NONE;

    if (!file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        // Ignoră liniile goale
        if (line.empty()) continue;

        // Identifică începutul unei secțiuni
        if (line[0] == '#') {
            if (line.find("Sellers") != std::string::npos) {
                currentSection = SELLERS;
            }
            else if (line.find("Buyers") != std::string::npos) {
                currentSection = BUYERS;
            }
            else if (line.find("Products") != std::string::npos) {
                currentSection = PRODUCTS;
            }
            continue; // Nu procesa această linie ca date
        }

        // Procesează datele în funcție de secțiunea curentă
        std::istringstream ss(line);

        if (currentSection == SELLERS) {
            std::string name, style;
            std::getline(ss, name, ',');
            std::getline(ss, style);
            sellers.emplace_back(name, style);
            std::cout << "Loaded Seller: " << name << " with style: " << style << std::endl;

        }
        else if (currentSection == BUYERS) {
            std::string name, style, category;
            std::getline(ss, name, ',');
            std::getline(ss, style, ',');
            std::getline(ss, category);
            buyers.emplace_back(name, style, category);
            std::cout << "Loaded Buyer: " << name << " with style: " << style << " and preferred category: " << category << std::endl;

        }
        else if (currentSection == PRODUCTS) {
            std::string name, category, ownerName;
            double price;

            std::getline(ss, name, ',');
            ss >> price;
            ss.ignore(); // Ignoră delimitatorul pentru a trece la următorul câmp
            std::getline(ss, ownerName, ',');
            std::getline(ss, category);

            // Găsește vânzătorul proprietar
            Seller* owner = nullptr;
            for (auto& seller : sellers) {
                if (seller.getName() == ownerName) {
                    owner = &seller;
                    break;
                }
            }

            if (owner) {
                products.emplace_back(name, price, owner, category);
                std::cout << "Loaded Product: " << name << " with price: " << price << " owned by: " << ownerName << " in category: " << category << std::endl;
            }
            else {
                std::cout << "Warning: Seller " << ownerName << " not found for product " << name << std::endl;
            }
        }
    }

    file.close();
}