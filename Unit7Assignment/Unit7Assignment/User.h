#ifndef USER_H
#define USER_H

#include <string>
#include "ShoppingCart.h"

class User {
protected:
    std::string name;
    std::string email;
    std::string address;
    std::string password;
    ShoppingCart cart;

public:
    User(const std::string& n, const std::string& e, const std::string& a, const std::string& p);

    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
    std::string getAddress() const { return address; }
    std::string getPassword() const { return password; }

    ShoppingCart& getCart() { return cart; }

    virtual double getDiscountRate() const = 0;
    virtual std::string getType() const = 0;

    virtual ~User() = default;
};

#endif