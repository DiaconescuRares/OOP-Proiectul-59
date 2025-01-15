#include "Buyer.h"
#include "Utils.h"

Buyer::Buyer(const string& name, const string& style, const string& category)
    : Participant(name, style) {}

const std::string& Buyer::getPreferredCategory() const {
    return preferredCategory; // Return preferred category
}

double Buyer::adjustPrice(double& offer)   {
    double adjustment = offer * (adjustmentRate / 100.0);
    offer += adjustment; // Buyer will increase his offer
    return 0;
}