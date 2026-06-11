#include "Customer.h"
#include "Product.h"
#include "Order.h"
#include "FileManager.h"
#include "ShopException.h"

static int orderCounter = 1;

Customer::Customer() : User() {
}

Customer::Customer(string username, string password) : User(username, password) {
}

void Customer::browseProducts(Inventory& inventory) {
    cout << "\n--- Available Products ---" << endl;
    inventory.displayProducts();
}

void Customer::addToCart(Inventory& inventory) {
    int id, quantity;

    cout << "\n--- Available Products ---" << endl;
    inventory.displayProducts();

    cout << "Enter product ID: ";
    cin >> id;

    Product product = inventory.getProductById(id);

    cout << "Enter quantity: ";
    cin >> quantity;

    if (quantity <= 0) {
        throw ShopException("Quantity must be greater than zero.");
    }

    if (quantity > product.getQuantity()) {
        throw ShopException("Not enough stock available.");
    }

    cart.addItem(product, quantity);
    cout << "Product added to cart successfully." << endl;
}
void Customer::removeFromCart() {
    int id;

    cout << "Enter product ID to remove from cart: ";
    cin >> id;

    cart.removeItem(id);

    cout << "Product removed from cart successfully." << endl;
}

void Customer::viewCart() {
    cout << "\n--- Your Cart ---" << endl;
    cart.displayCart();
    cout << "Total: " << cart.calculateTotal() << endl;
}

void Customer::placeOrder(Inventory& inventory) {
    if (cart.getItemCount() == 0) {
        throw ShopException("Cart is empty. Cannot place order.");
    }

    for (int i = 0; i < cart.getItemCount(); i++) {
        Product item = cart.getItemAt(i);
        int quantity = cart.getQuantityAt(i);

        Product inventoryProduct = inventory.getProductById(item.getId());

        if (quantity > inventoryProduct.getQuantity()) {
            throw ShopException("Not enough stock for product: " + item.getName());
        }
    }

    for (int i = 0; i < cart.getItemCount(); i++) {
        Product item = cart.getItemAt(i);
        int quantity = cart.getQuantityAt(i);

        inventory.decreaseStock(item.getId(), quantity);
    }

    Order order(orderCounter, username);
    order.createOrder(cart);

    cout << "\n--- Order Summary ---" << endl;
    order.displayOrder();

    FileManager::saveOrder(order);
    FileManager::saveProducts(inventory);

    cart.clearCart();
    orderCounter++;

    cout << "Order placed successfully." << endl;
}

void Customer::showMenu() {
    cout << "\n===== Customer Menu =====" << endl;
    cout << "1. View products" << endl;
    cout << "2. Add product to cart" << endl;
    cout << "3. Remove product from cart" << endl;
    cout << "4. View cart" << endl;
    cout << "5. Place order" << endl;
    cout << "6. Logout" << endl;
    cout << "Enter your choice: ";
}

string Customer::getRole() {
    return "Customer";
}