#include <iostream>
using namespace std;


class Order {
private:
    int orderId;
    double totalAmount;

public:
    Order(int id, double total) {
        orderId = id;
        totalAmount = total;
    }

    void displayOrder() {
        cout << "\n===== ORDER DETAILS =====" << endl;
        cout << "Order ID: " << orderId << endl;
        cout << "Total Amount: $" << totalAmount << endl;
    }
};
int main() {
    Order order(1, 820.0);
    order.displayOrder();

    return 0;
}
