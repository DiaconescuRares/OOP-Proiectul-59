#ifndef BUYER_H
#define BUYER_H

#include "Participant.h"
#include <string>

class Buyer : public Participant {
private:
    string preferredCategory; 

public:
    Buyer(const string& name, const string& style, const string& preferredCategory);
    const std::string& getPreferredCategory() const; 
    double adjustPrice(double& price) override; 
};

#endif 