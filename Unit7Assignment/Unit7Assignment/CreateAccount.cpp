#include <iostream>
#include <limits>
#include "CreateAccount.h"
#include "RegularUser.h"

void createAccount(UserDatabase& db) {

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string name, email, address, password;

    std::cout << "\n=== Create Account ===\n";

    std::cout << "Name: ";
    std::getline(std::cin, name);

    std::cout << "Email: ";
    std::getline(std::cin, email);

    std::cout << "Address: ";
    std::getline(std::cin, address);

    std::cout << "Password: ";
    std::getline(std::cin, password);

    auto newUser = std::make_shared<RegularUser>(name, email, address, password);
    db.addUser(newUser);

    std::cout << "Account created successfully!\n";
}