#include "ShoppingCart.h"

void ShoppingCart::addItem(std::shared_ptr<Product> product, int quantity) {
    items[product] += quantity;
}

void ShoppingCart::removeItem(std::shared_ptr<Product> product) {
    items.erase(product);
}

bool ShoppingCart::isEmpty() const {
    return items.empty();
}

double ShoppingCart::calculateTotal(double discountRate) const {
    double total = 0.0;
    for (const auto& pair : items) {
        total += pair.first->getPrice() * pair.second;
    }
    return total * (1.0 - discountRate);
}

const std::map<std::shared_ptr<Product>, int>& ShoppingCart::getItems() const {
    return items;
}

void ShoppingCart::clear() {
    items.clear();
}