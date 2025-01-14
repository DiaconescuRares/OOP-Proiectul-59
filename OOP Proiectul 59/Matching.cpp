#include "Matching.h"

bool Matching::findMatch(const Buyer& buyer, const Seller& seller, const Product& product) {
    return buyer.getPreferredCategory() == product.getCategory();
}