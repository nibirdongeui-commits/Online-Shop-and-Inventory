#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "Cart.h"
#include "Inventory.h"

class Customer : public User {
private:
    Cart cart;

public:
    Customer();
    Customer(string username, string password);

    void browseProducts(Inventory& inventory);
    void addToCart(Inventory& inventory);
    void removeFromCart();
    void viewCart();
    void placeOrder(Inventory& inventory);

    void showMenu();
    string getRole();
};

#endif