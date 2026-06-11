#include "Admin.h"
#include "Product.h"
#include "FileManager.h"
#include "ShopException.h"

Admin::Admin() : User()
{
}

Admin::Admin(string username, string password) : User(username, password)
{
}

void Admin::viewInventory(Inventory &inventory)
{
    cout << "\n--- Inventory List ---" << endl;
    inventory.displayProducts();
}

void Admin::addProduct(Inventory& inventory) {
    int id, quantity;
    string name;
    double price;

    cout << "Enter product ID: ";
    cin >> id;

    if (id <= 0) {
        throw ShopException("Invalid product ID.");
    }

    if (inventory.productExists(id)) {
        throw ShopException("Product ID already exists.");
    }

    cout << "Enter product name: ";
    cin >> name;

    cout << "Enter product price: ";
    cin >> price;

    if (price <= 0) {
        throw ShopException("Price must be greater than zero.");
    }

    cout << "Enter product quantity: ";
    cin >> quantity;

    if (quantity < 0) {
        throw ShopException("Quantity cannot be negative.");
    }

    Product product(id, name, price, quantity);
    inventory.addProduct(product);
    FileManager::saveProducts(inventory);

    cout << "Product added successfully." << endl;
}
void Admin::updateStock(Inventory& inventory) {
    int id, quantity;

    cout << "Enter product ID: ";
    cin >> id;

    if (!inventory.productExists(id)) {
        throw ShopException("Product not found.");
    }

    cout << "Enter new stock quantity: ";
    cin >> quantity;

    if (quantity < 0) {
        throw ShopException("Stock quantity cannot be negative.");
    }

    inventory.updateStock(id, quantity);
    FileManager::saveProducts(inventory);

    cout << "Stock updated successfully." << endl;
}

void Admin::updatePrice(Inventory& inventory) {
    int id;
    double price;

    cout << "Enter product ID: ";
    cin >> id;

    if (!inventory.productExists(id)) {
        throw ShopException("Product not found.");
    }

    cout << "Enter new price: ";
    cin >> price;

    if (price <= 0) {
        throw ShopException("Price must be greater than zero.");
    }

    inventory.updatePrice(id, price);
    FileManager::saveProducts(inventory);

    cout << "Price updated successfully." << endl;
}
void Admin::removeProduct(Inventory &inventory)
{
    int id;

    cout << "Enter product ID to remove: ";
    cin >> id;

    inventory.removeProduct(id);
    FileManager::saveProducts(inventory);

    cout << "Product removed successfully." << endl;
}

void Admin::showMenu()
{
    cout << "\n===== Admin Menu =====" << endl;
    cout << "1. View inventory" << endl;
    cout << "2. Add product" << endl;
    cout << "3. Update stock" << endl;
    cout << "4. Update price" << endl;
    cout << "5. Remove product" << endl;
    cout << "6. Logout" << endl;
    cout << "Enter your choice: ";
}

string Admin::getRole()
{
    return "Admin";
}