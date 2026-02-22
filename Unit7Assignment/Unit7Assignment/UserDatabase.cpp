#include "UserDatabase.h"

void UserDatabase::addUser(std::shared_ptr<User> user) {
    users.push_back(user);
}

std::shared_ptr<User> UserDatabase::authenticate(const std::string& email, const std::string& password) {
    for (auto& user : users) {
        if (user->getEmail() == email && user->getPassword() == password) {
            return user;
        }
    }
    return nullptr;
}