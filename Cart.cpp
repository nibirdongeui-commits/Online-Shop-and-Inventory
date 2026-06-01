#include "Cart.h"
#include <iostream>
using namespace std;

Cart::Cart() {
    itemCount = 0;
}

void Cart::addItem(Product product, int quantity) {

    for (int i = 0; i < itemCount; i++) {
        if (items[i].getId() == product.getId()) {
            quantities[i] += quantity;
            return;
        }
    }

    if (itemCount < 50) {
        items[itemCount] = product;
        quantities[itemCount] = quantity;
        itemCount++;
    }
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
    return items[index];
}

int Cart::getQuantityAt(int index) {
    return quantities[index];
}
