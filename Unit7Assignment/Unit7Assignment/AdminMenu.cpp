#include <iostream>
#include <limits>
#include "AdminMenu.h"
#include "Catalog.h"

void adminMenu(Catalog& catalog) {

    int choice;

    do {
        std::cout << "\n=== Admin Menu ===\n";
        std::cout << "1. View Catalog\n";
        std::cout << "2. Add Product\n";
        std::cout << "3. Remove Product\n";
        std::cout << "4. Exit\n";
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
            std::string name, description;
            double price;
            int stock;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Name: ";
            std::getline(std::cin, name);

            std::cout << "Description: ";
            std::getline(std::cin, description);

            std::cout << "Price: ";
            while (!(std::cin >> price) || price < 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid price. Enter a positive number: ";
            }

            std::cout << "Stock: ";
            while (!(std::cin >> stock) || stock < 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid stock. Enter a positive number: ";
            }

            catalog.addProduct(name, description, price, stock);
            std::cout << "Product added.\n";
        }

        else if (choice == 3) {
            int id;

            std::cout << "Enter product ID to remove: ";

            while (!(std::cin >> id)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Enter a numeric ID: ";
            }

            catalog.removeProduct(id);
            std::cout << "Product removed.\n";
        }

        else if (choice == 4) {
            std::cout << "Exiting admin menu...\n";
        }

        else {
            std::cout << "Invalid choice.\n";
        }

    } while (choice != 4);
}