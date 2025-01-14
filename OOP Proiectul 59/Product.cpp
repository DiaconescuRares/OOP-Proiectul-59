#include "Product.h"
#include "Seller.h"

Product::Product(const string& name, double price, Seller* owner, const string& category)
    : name(name), price(price), owner(owner), category(category) {}

const string& Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

Seller* Product::getOwner() const {
    return owner;
}

const string& Product::getCategory() const {
    return category; // Return the category of the product
}