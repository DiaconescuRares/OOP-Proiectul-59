#ifndef PARTICIPANT_H
#define PARTICIPANT_H
using namespace std;
#include <string>
#include <random>

class Participant {
protected:
    string name;
    string negotiationStyle; // "Conservative", "Moderate", "Flexible"
    double adjustmentRate; // Percentage adjustment per round

    double generateRandomPercentage(double min, double max);

public:
    Participant(const string& name, const string& style);
    const string& getName() const;
    const string& getStyle() const;
    virtual double adjustPrice(double& price); // Virtual method for price adjustment
};

#endif 