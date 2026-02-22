#ifndef CATALOG_H
#define CATALOG_H

#include <vector>
#include <memory>
#include <string>
#include "Product.h"

class Catalog {
private:
    std::vector<std::shared_ptr<Product>> products;

public:

    Catalog();

    void addProduct(const std::string& name,
        const std::string& description,
        double price,
        int stock);

    void removeProduct(int id);

    const std::vector<std::shared_ptr<Product>>& getProducts() const;

    void listProducts() const;
};

#endif