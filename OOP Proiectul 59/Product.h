#ifndef PRODUCT_H
#define PRODUCT_H
using namespace std;
#include "Seller.h"
#include <iostream>
#include <string>

class Product {
private:
    string name;
    double price;
    Seller* owner; 
    string category; 

public:
    Product(const string& name, double price, Seller* owner, const string& category);
    const string& getName() const;
    double getPrice() const;
    Seller* getOwner() const;
    const string& getCategory() const; 
};

#endif 