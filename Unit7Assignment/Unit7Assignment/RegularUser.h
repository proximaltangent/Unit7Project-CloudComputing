#ifndef REGULARUSER_H
#define REGULARUSER_H

#include "User.h"

class RegularUser : public User {
public:
    RegularUser(const std::string& n, const std::string& e, const std::string& a, const std::string& p);

    double getDiscountRate() const override { return 0.0; }
    std::string getType() const override { return "Regular"; }
};

#endif