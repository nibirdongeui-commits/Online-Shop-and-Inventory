#include <iostream>
#include <vector>
using namespace std;


class Product {
private:
    int id;
    string name;
    double price;

public:
    Product(int i, string n, double p) {
        id = i;
        name = n;
        price = p;
    }

    double getPrice() {
        return price;
    }

    void display() {
        cout << "ID: " << id
             << " Name: " << name
             << " Price: $" << price << endl;
    }
};


class Cart {
private:
    vector<Product> items;

public:
    void addToCart(Product p) {
        items.push_back(p);
    }

    double getTotal() {
        double total = 0;

        for (auto &p : items)
            total += p.getPrice();

        return total;
    }

    void showCart() {
        cout << "\nCart Items:\n";

        for (auto &p : items)
            p.display();

        cout << "Total = $" << getTotal() << endl;
    }
};

// ORDER CLASS
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

    Product p1(101, "Laptop", 800);
    Product p2(102, "Mouse", 20);

    Cart cart;

    cart.addToCart(p1);
    cart.addToCart(p2);

    cart.showCart();

    Order order(1, cart.getTotal());

    order.displayOrder();

    return 0;
}
