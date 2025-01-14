#ifndef DATALOADER_H
#define DATALOADER_H

#include "Buyer.h"
#include "Seller.h"
#include "Product.h"
#include <vector>
#include <string>

class DataLoader {
public:
    static void loadFromFile(const string& filename, vector<Buyer>& buyers, vector<Seller>& sellers, vector<Product>& products);
};

#endif 