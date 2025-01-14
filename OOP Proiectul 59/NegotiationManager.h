#ifndef NEGOTIATIONMANAGER_H
#define NEGOTIATIONMANAGER_H

#include "Buyer.h"
#include "Seller.h"
#include "Product.h"
#include <vector>

class NegotiationManager {
public:
    static void displayMenu(const vector<Buyer>& buyers, const vector<Seller>& sellers, const vector<Product>& products);
    static void startNegotiation(const Buyer& buyer, const Seller& seller, const Product& product);
};

#endif 