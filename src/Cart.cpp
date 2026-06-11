#include "Cart.h"
#include "ShopException.h"
#include <iostream>
using namespace std;

Cart::Cart() {
    itemCount = 0;
}

void Cart::addItem(Product product, int quantity) {
    if (quantity <= 0) {
        throw ShopException("Quantity must be greater than zero.");
    }

    for (int i = 0; i < itemCount; i++) {
        if (items[i].getId() == product.getId()) {
            quantities[i] += quantity;
            return;
        }
    }

    if (itemCount >= 50) {
        throw ShopException("Cart is full. Cannot add more items.");
    }

    items[itemCount] = product;
    quantities[itemCount] = quantity;
    itemCount++;
}

void Cart::removeItem(int productId) {
    for (int i = 0; i < itemCount; i++) {
        if (items[i].getId() == productId) {
            for (int j = i; j < itemCount - 1; j++) {
                items[j] = items[j + 1];
                quantities[j] = quantities[j + 1];
            }
            itemCount--;
            return;
        }
    }
    throw ShopException("Product ID not found in cart.");
}

void Cart::displayCart() {

    cout << "\n===== CART =====\n";

    for (int i = 0; i < itemCount; i++) {
        cout << items[i].getName()
             << " x" << quantities[i]
             << " = $" << items[i].getPrice() * quantities[i]
             << endl;
    }

    cout << "Total: $" << calculateTotal() << endl;
}

double Cart::calculateTotal() {

    double total = 0;

    for (int i = 0; i < itemCount; i++) {
        total += items[i].getPrice() * quantities[i];
    }

    return total;
}

void Cart::clearCart() {
    itemCount = 0;
}

int Cart::getItemCount() {
    return itemCount;
}
Product Cart::getItemAt(int index) {
    if (index < 0 || index >= itemCount) {
        throw ShopException("Invalid cart item index.");
    }

    return items[index];
}

int Cart::getQuantityAt(int index) {
    if (index < 0 || index >= itemCount) {
        throw ShopException("Invalid cart quantity index.");
    }

    return quantities[index];
}