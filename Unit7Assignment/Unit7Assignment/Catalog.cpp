#include <iostream>
#include <iomanip>
#include "Catalog.h"
#include "Product.h"

Catalog::Catalog() {
}

void Catalog::addProduct(const std::string& name,
    const std::string& description,
    double price,
    int stock)
{

    int id = static_cast<int>(products.size()) + 1;

    products.push_back(
        std::make_shared<Product>(id, name, description, price, stock)
    );
}

void Catalog::removeProduct(int id)
{
    if (id < 1 || id > static_cast<int>(products.size())) {
        std::cout << "Invalid product ID.\n";
        return;
    }

    products.erase(products.begin() + (id - 1));
}

const std::vector<std::shared_ptr<Product>>& Catalog::getProducts() const
{
    return products;
}

void Catalog::listProducts() const
{
    if (products.empty()) {
        std::cout << "\nNo products available.\n";
        return;
    }

    std::cout << "\n=== Product Catalog ===\n";

    for (size_t i = 0; i < products.size(); ++i) {
        auto& p = products[i];

        std::cout << (i + 1) << ". "
            << p->getName()
            << " - $" << std::fixed << std::setprecision(2) << p->getPrice()
            << " (" << p->getStock() << " in stock)\n";
    }
}