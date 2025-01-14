#include "Negotiation.h"

#include "Negotiation.h"

Negotiation::Negotiation(Buyer& buyer, Seller& seller, double buyerPrice, double sellerPrice, int maxRounds, double failureProbability)
    : buyer(buyer), seller(seller), initialBuyerPrice(buyerPrice), initialSellerPrice(sellerPrice),
    currentBuyerPrice(buyerPrice), currentSellerPrice(sellerPrice), maxRounds(maxRounds),
    currentRound(0), failureProbability(failureProbability) {}

bool Negotiation::shouldFailEarly() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);
    return dis(gen) < failureProbability;
}

bool Negotiation::conductRound() {
    if (shouldFailEarly()) {
        return false;  // Negotiation fails early
    }

    // Apelăm metodele corecte pentru Buyer și Seller
    buyer.adjustPrice(currentBuyerPrice);  // Polimorfism: apelăm metoda ajustării prețului pentru Buyer
    seller.adjustPrice(currentSellerPrice);  // Polimorfism: apelăm metoda ajustării prețului pentru Seller
    currentRound++;

    return currentRound < maxRounds;
}

bool Negotiation::isAgreementReached() const {
    return currentBuyerPrice >= currentSellerPrice;
}