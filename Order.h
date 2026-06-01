#ifndef ORDER_H
#define ORDER_H

#include <string>
#include "Cart.h"

using namespace std;

class Order {
private:
    int orderId;
    string customerName;

    Product orderedItems[50];
    int quantities[50];

    int itemCount;
    double totalAmount;

public:
    Order();
    Order(int orderId, string customerName);

    void createOrder(Cart& cart);
    void displayOrder();

    double getTotalAmount();
    int getOrderId();
    string getCustomerName();

    string toFileString();
};

#endif
