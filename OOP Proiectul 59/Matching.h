#ifndef MATCHING_H
#define MATCHING_H

#include "Buyer.h"
#include "Seller.h"
#include "Product.h"
#include <vector>

class Matching {
public:
    static bool findMatch(const Buyer& buyer, const Seller& seller, const Product& product);
};

#endif 