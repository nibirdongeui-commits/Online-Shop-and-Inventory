#include "Order.h"
#include "ShopException.h"
#include <iostream>
#include <sstream>

using namespace std;

Order::Order() {
    orderId = 0;
    customerName = "";
    itemCount = 0;
    totalAmount = 0;
}

Order::Order(int orderId, string customerName) {
    this->orderId = orderId;
    this->customerName = customerName;
    itemCount = 0;
    totalAmount = 0;
}

void Order::createOrder(Cart& cart) {

    if (cart.getItemCount() == 0) {
        throw ShopException("Cart is empty!");
    }

    itemCount = cart.getItemCount();

    for (int i = 0; i < itemCount; i++) {
        orderedItems[i] = cart.getItemAt(i);
        quantities[i] = cart.getQuantityAt(i);
    }

    totalAmount = cart.calculateTotal();
}

void Order::displayOrder() {

    cout << "\n===== ORDER SUMMARY =====\n";
    cout << "Order ID: " << orderId << endl;
    cout << "Customer: " << customerName << endl;

    for (int i = 0; i < itemCount; i++) {

        cout << orderedItems[i].getName()
             << " x" << quantities[i]
             << " = $"
             << orderedItems[i].getPrice() * quantities[i]
             << endl;
    }

    cout << "Total Amount: $" << totalAmount << endl;
}

double Order::getTotalAmount() {
    return totalAmount;
}

int Order::getOrderId() {
    return orderId;
}

string Order::getCustomerName() {
    return customerName;
}

string Order::toFileString() {

    stringstream ss;

    ss << orderId << ","
       << customerName << ","
       << totalAmount << "\n";

    for (int i = 0; i < itemCount; i++) {

        ss << orderedItems[i].getId() << ","
           << orderedItems[i].getName() << ","
           << quantities[i] << ","
           << orderedItems[i].getPrice()
           << "\n";
    }

    return ss.str();
}
