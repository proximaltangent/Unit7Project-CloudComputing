#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <map>
#include <memory>
#include "Product.h"

class ShoppingCart {
private:
    std::map<std::shared_ptr<Product>, int> items;

public:
    void addItem(std::shared_ptr<Product> product, int quantity);
    void removeItem(std::shared_ptr<Product> product);
    bool isEmpty() const;
    double calculateTotal(double discountRate) const;

    const std::map<std::shared_ptr<Product>, int>& getItems() const;

    void clear();
};

#endif