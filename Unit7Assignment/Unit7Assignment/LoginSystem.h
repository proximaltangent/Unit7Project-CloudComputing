#ifndef LOGINSYSTEM_H
#define LOGINSYSTEM_H

#include <memory>
#include <string>
#include "UserDatabase.h"
#include "Admin.h"

class LoginSystem {
public:
    static std::shared_ptr<User> loginUser(UserDatabase& db);
    static std::shared_ptr<Admin> loginAdmin();
};

#endif