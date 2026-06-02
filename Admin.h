#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Inventory.h"

class Admin : public User {
public:
    Admin();
    Admin(string username, string password);

    void viewInventory(Inventory& inventory);
    void addProduct(Inventory& inventory);
    void updateStock(Inventory& inventory);
    void updatePrice(Inventory& inventory);
    void removeProduct(Inventory& inventory);

    void showMenu();
    string getRole();
};

#endif