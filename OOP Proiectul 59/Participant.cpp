#include "Participant.h"

Participant::Participant(const std::string& name, const std::string& style)
    : name(name), negotiationStyle(style) {
    if (style == "Conservative") {
        adjustmentRate = 5.0 + generateRandomPercentage(0, 5);
    }
    else if (style == "Moderate") {
        adjustmentRate = 10.0 + generateRandomPercentage(0, 5);
    }
    else if (style == "Flexible") {
        adjustmentRate = 15.0 + generateRandomPercentage(0, 5);
    }
}

double Participant::generateRandomPercentage(double min, double max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    return dis(gen);
}

const std::string& Participant::getName() const {
    return name;
}

const std::string& Participant::getStyle() const {
    return negotiationStyle;
}

double Participant::adjustPrice(double& price) {
    double adjustment = price * (adjustmentRate / 100.0);
    price += adjustment; // Base behavior, can be overridden
    return 0;
}
