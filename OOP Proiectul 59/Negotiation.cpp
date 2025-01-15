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

   
    buyer.adjustPrice(currentBuyerPrice);  
    seller.adjustPrice(currentSellerPrice);  
    currentRound++;

    return currentRound < maxRounds;
}

bool Negotiation::isAgreementReached() const {
    return currentBuyerPrice >= currentSellerPrice;
}