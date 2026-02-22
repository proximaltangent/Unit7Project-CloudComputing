#ifndef VIPUSER_H
#define VIPUSER_H

#include "User.h"

class VIPUser : public User {
public:
    VIPUser(const std::string& n, const std::string& e, const std::string& a, const std::string& p);

    double getDiscountRate() const override { return 0.20; }
    std::string getType() const override { return "VIP"; }
};

#endif