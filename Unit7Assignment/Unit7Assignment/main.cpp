#include <iostream>
#include <limits>
#include <cstdlib>
#include "LoginSystem.h"
#include "UserDatabase.h"
#include "CustomerMenu.h"
#include "AdminMenu.h"
#include "Catalog.h"
#include "CreateAccount.h"

int main() {
    LoginSystem loginSystem;
    UserDatabase userDB;
    Catalog catalog;

    catalog.addProduct("Laptop", "High performance laptop", 999.99, 10);
    catalog.addProduct("Headphones", "Noise cancelling headphones", 199.99, 25);
    catalog.addProduct("Mouse", "Wireless mouse", 49.99, 50);

    int choice;

    do {
        std::cout << "\n=== Main Menu ===\n";
        std::cout << "1. Login\n";
        std::cout << "2. Create Account\n";
        std::cout << "3. Admin Login\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";

        while (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number: ";
        }

        if (choice == 1) {
            auto user = loginSystem.loginUser(userDB);

            if (user) {
                system("cls");
                customerMenu(user, catalog);
                system("cls");
            }
        }

        else if (choice == 2) {
            createAccount(userDB);
        }

        else if (choice == 3) {
            auto admin = loginSystem.loginAdmin();

            if (admin) {
                system("cls");
                adminMenu(catalog);
                system("cls");
            }
        }

        else if (choice == 4) {
            std::cout << "Exiting program...\n";
        }

        else {
            std::cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}