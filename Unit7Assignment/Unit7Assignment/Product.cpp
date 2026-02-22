#include "Product.h"

Product::Product(int id, const std::string& n, const std::string& d, double p, int s)
    : id(id), name(n), description(d), price(p), stock(s) {
}

void Product::reduceStock(int amount) {
    stock -= amount;
}