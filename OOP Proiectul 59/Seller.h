#ifndef SELLER_H
#define SELLER_H

#include "Participant.h"

class Seller : public Participant {
public:
    Seller(const string& name, const string& style);
    double adjustPrice(double& price) override; // Override adjustPrice for Selle
};

#endif 