#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    int id;
    std::string name;
    std::string description;
    double price;
    int stock;

public:
    Product(int id, const std::string& n, const std::string& d, double p, int s);

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    double getPrice() const { return price; }
    int getStock() const { return stock; }

    void reduceStock(int amount);
};

#endif