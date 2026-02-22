#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "Checkout.h"

bool checkout(User& user) {
    ShoppingCart& cart = user.getCart();

    if (cart.isEmpty()) {
        std::cout << "\nYour cart is empty.\n";
        return false;
    }

    double discount = user.getDiscountRate();
    double total = cart.calculateTotal(discount);

    std::cout << "\n=== Checkout for " << user.getName()
        << " (" << user.getType() << ") ===\n";

    int index = 1;
    for (const auto& pair : cart.getItems()) {
        auto product = pair.first;
        int qty = pair.second;

        std::cout << index++ << ". "
            << product->getName()
            << " - Qty: " << qty
            << " - $" << product->getPrice() << " each\n";
    }

    std::cout << "\nTotal after discount: $" << total << "\n";
    std::cout << "Confirm purchase (yes/no): ";

    std::string input;
    std::cin >> input;

    if (input != "yes") {
        std::cout << "Checkout canceled.\n";
        return false;
    }

    for (const auto& pair : cart.getItems()) {
        pair.first->reduceStock(pair.second);
    }

    std::cout << "Purchase complete! Returning to menu...\n";
    cart.clear();

    Sleep(1500);
    system("cls");

    return true;
}