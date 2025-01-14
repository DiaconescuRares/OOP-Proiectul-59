#include "DataLoader.h"
#include "NegotiationManager.h"
#include <vector>
using namespace std;

int main() {
    vector<Buyer> buyers;
    vector<Seller> sellers;
    vector<Product> products;

    // Load data from file
    DataLoader::loadFromFile("data.txt", buyers, sellers, products);

    // Display menu and start the application
    NegotiationManager::displayMenu(buyers, sellers, products);

    return 0;
}