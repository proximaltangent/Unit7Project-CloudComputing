#ifndef USERDATABASE_H
#define USERDATABASE_H

#include <vector>
#include <memory>
#include <string>
#include "User.h"

class UserDatabase {
private:
    std::vector<std::shared_ptr<User>> users;

public:
    void addUser(std::shared_ptr<User> user);
    std::shared_ptr<User> authenticate(const std::string& email, const std::string& password);
};

#endif