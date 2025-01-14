#include "Buyer.h"
#include "Utils.h"

Buyer::Buyer(const string& name, const string& style, const string& category)
    : Participant(name, style) {}

const std::string& Buyer::getPreferredCategory() const {
    return preferredCategory; // Return preferred category
}

double Buyer::adjustPrice(double& offer)   {
    double adjustment = 0.0;
    if (negotiationStyle == "Conservative") {
        adjustment = generateRandomPercentage(0.01, 0.05); // 1-5%
    }
    else if (negotiationStyle == "Moderate") {
        adjustment = generateRandomPercentage(0.05, 0.10); // 5-10%
    }
    else if (negotiationStyle == "Flexible") {
        adjustment = generateRandomPercentage(0.10, 0.15); // 10-15%
    }
    return offer * (1 - adjustment); // Scade oferta
}