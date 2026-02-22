#include <iostream>
#include <limits>
#include <cstdlib>
#include "LoginSystem.h"
#include "UserDatabase.h"
#include "User.h"
#include "Admin.h"

std::shared_ptr<User> LoginSystem::loginUser(UserDatabase& db) {

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string email, password;

    std::cout << "\n=== Customer Login ===\n";

    std::cout << "Email: ";
    std::getline(std::cin, email);

    std::cout << "Password: ";
    std::getline(std::cin, password);

    auto user = db.authenticate(email, password);

    if (!user) {
        std::cout << "Invalid credentials.\n";
        system("pause");
        system("cls");
        return nullptr;
    }

    std::cout << "Login successful!\n";
    system("pause");
    system("cls");

    return user;
}

std::shared_ptr<Admin> LoginSystem::loginAdmin() {

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string username, password;

    std::cout << "\n=== Admin Login ===\n";

    std::cout << "Username: ";
    std::getline(std::cin, username);

    std::cout << "Password: ";
    std::getline(std::cin, password);

    if (username == "admin" && password == "admin123") {
        std::cout << "Admin login successful!\n";
        system("pause");
        system("cls");
        return std::make_shared<Admin>(username);
    }

    std::cout << "Invalid admin credentials.\n";
    system("pause");
    system("cls");
    return nullptr;
}