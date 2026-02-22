#include <iostream>
#include <limits>
#include "CustomerMenu.h"
#include "Checkout.h"

void customerMenu(std::shared_ptr<User> user, Catalog& catalog) {
    int choice;

    do {
        std::cout << "\n=== Customer Menu (" << user->getType() << ") ===\n";
        std::cout << "1. View Catalog\n";
        std::cout << "2. Add Item to Cart\n";
        std::cout << "3. Remove Item from Cart\n";
        std::cout << "4. Checkout\n";
        std::cout << "5. Exit\n";

        std::cout << "Choice: ";

        while (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number: ";
        }

        if (choice == 1) {
            catalog.listProducts();
        }

        else if (choice == 2) {
            auto list = catalog.getProducts();

            if (list.empty()) {
                std::cout << "No products available.\n";
                continue;
            }

            std::cout << "\n=== Select a Product ===\n";

            for (size_t i = 0; i < list.size(); ++i) {
                std::cout << (i + 1) << ". "
                    << list[i]->getName()
                    << " - $" << list[i]->getPrice()
                    << " (" << list[i]->getStock() << " in stock)\n";
            }

            std::cout << "0. Cancel\n";
            std::cout << "Choose a product (0-" << list.size() << "): ";

            int selection;

            while (!(std::cin >> selection) ||
                selection < 0 ||
                selection > static_cast<int>(list.size())) {

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Invalid choice. Enter a number between 0 and "
                    << list.size() << ": ";
            }

            if (selection == 0) {
                std::cout << "Canceled.\n";
                continue;
            }

            auto product = list[selection - 1];

            int qty;
            std::cout << "Quantity (0 to cancel): ";

            while (!(std::cin >> qty) || qty < 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid quantity. Enter 0 or a positive number: ";
            }

            if (qty == 0) {
                std::cout << "Canceled.\n";
                continue;
            }

            user->getCart().addItem(product, qty);
            std::cout << "Added to cart.\n";
        }

        else if (choice == 3) {
            auto& items = user->getCart().getItems();

            if (items.empty()) {
                std::cout << "\nYour cart is empty.\n";
                continue;
            }

            std::cout << "\n=== Remove Item ===\n";

            std::vector<std::shared_ptr<Product>> list;
            for (const auto& pair : items) {
                list.push_back(pair.first);
            }

            for (size_t i = 0; i < list.size(); ++i) {
                std::cout << (i + 1) << ". "
                    << list[i]->getName()
                    << " (Qty: " << items.at(list[i]) << ")\n";
            }

            std::cout << "0. Cancel\n";
            std::cout << "Choose an item to remove (0-" << list.size() << "): ";

            int selection;

            while (!(std::cin >> selection) ||
                selection < 0 ||
                selection > static_cast<int>(list.size())) {

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Invalid choice. Enter a number between 0 and "
                    << list.size() << ": ";
            }

            if (selection == 0) {
                std::cout << "Canceled.\n";
                continue;
            }

            auto productToRemove = list[selection - 1];
            user->getCart().removeItem(productToRemove);

            std::cout << "Item removed.\n";
        }

        else if (choice == 4) {
            checkout(*user);
        }

        else if (choice == 5) {
            std::cout << "Logging out...\n";
        }

        else {
            std::cout << "Invalid choice.\n";
        }

    } while (choice != 5);
}