#include "Seller.h"

Seller::Seller(const string& name, const string& style)
    : Participant(name, style) {}

double Seller::adjustPrice(double& price) {
    double adjustment = price * (adjustmentRate / 100.0);
    price -= adjustment; // Seller will decrease the asking price
    return 0;
}