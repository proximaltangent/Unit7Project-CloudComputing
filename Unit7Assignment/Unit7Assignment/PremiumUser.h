#ifndef PREMIUMUSER_H
#define PREMIUMUSER_H

#include "User.h"

class PremiumUser : public User {
public:
    PremiumUser(const std::string& n, const std::string& e, const std::string& a, const std::string& p);

    double getDiscountRate() const override { return 0.10; }
    std::string getType() const override { return "Premium"; }
};

#endif