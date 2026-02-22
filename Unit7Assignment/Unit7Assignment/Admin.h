#ifndef ADMIN_H
#define ADMIN_H

#include <string>

class Admin {
private:
    std::string username;

public:
    Admin(const std::string& u) : username(u) {}

    std::string getUsername() const { return username; }
};

#endif