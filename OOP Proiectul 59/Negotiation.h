#ifndef NEGOTIATION_H
#define NEGOTIATION_H
using namespace std;
#include "Buyer.h"
#include "Seller.h"
#include <random>

class Negotiation {
private:
    Buyer& buyer;
    Seller& seller;
    double initialBuyerPrice;
    double initialSellerPrice;
    double currentBuyerPrice;
    double currentSellerPrice;
    int maxRounds;
    int currentRound;
    double failureProbability; // Between 0.01 and 0.1

    bool shouldFailEarly();

public:
    Negotiation(Buyer& buyer, Seller& seller, double buyerPrice, double sellerPrice, int maxRounds, double failureProbability);

    bool conductRound();
    bool isAgreementReached() const;
};

#endif 