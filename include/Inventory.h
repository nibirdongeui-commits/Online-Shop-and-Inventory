#ifndef INVENTORY_H
#define INVENTORY_H

#include "Product.h"

class Inventory
{
private:
    Product products[100];
    int productCount;

public:
    Inventory();

    void addProduct(Product product);
    void removeProduct(int productId);

    void updateStock(int productId, int quantity);
    void updatePrice(int productId, double price);

    Product getProductById(int productId);

    bool productExists(int productId);

    void displayProducts();

    int getProductCount() const;
    Product getProductAt(int index);

    void decreaseStock(int productId, int quantity);
};

#endif
