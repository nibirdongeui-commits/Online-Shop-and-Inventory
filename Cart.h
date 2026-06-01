#ifndef CART_H
#define CART_H

#include "Product.h"

class Cart {
private:
    Product items[50];
    int quantities[50];
    int itemCount;

public:
    Cart();

    void addItem(Product product, int quantity);
    void removeItem(int productId);
    void displayCart();
    double calculateTotal();
    void clearCart();

    int getItemCount();
    Product getItemAt(int index);
    int getQuantityAt(int index);
};

#endif
