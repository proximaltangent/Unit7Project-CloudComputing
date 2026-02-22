#ifndef CUSTOMER_MENU_H
#define CUSTOMER_MENU_H

#include <memory>
#include "User.h"
#include "Catalog.h"

void customerMenu(std::shared_ptr<User> user, Catalog& catalog);

#endif