#include <iostream>
#include <string>

#include "User.h"
#include "Customer.h"
#include "Admin.h"
#include "Inventory.h"
#include "FileManager.h"
#include "ShopException.h"

using namespace std;

void runUserSession(User* currentUser, Inventory& inventory);

int main() {
    Inventory inventory;

    try {
        FileManager::loadProducts(inventory);
    }
    catch (const ShopException& e) {
        cout << "Warning: " << e.what() << endl;
        cout << "Program will continue with empty inventory." << endl;
    }

    int choice;

    do {
        cout << "\n===== Online Shop & Inventory Management =====" << endl;
        cout << "1. Login as Customer" << endl;
        cout << "2. Login as Admin" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            string username, password, role;

            cout << "Enter username: ";
            cin >> username;

            cout << "Enter password: ";
            cin >> password;

            if (choice == 1) {
                role = "customer";
            }
            else {
                role = "admin";
            }

            try {
                bool validLogin = FileManager::validateLogin(username, password, role);

                if (!validLogin) {
                    cout << "Invalid username or password." << endl;
                    continue;
                }

                User* currentUser = nullptr;

                if (role == "customer") {
                    currentUser = new Customer(username, password);
                    cout << "\nLogin successful as Customer." << endl;
                }
                else {
                    currentUser = new Admin(username, password);
                    cout << "\nLogin successful as Admin." << endl;
                }

                runUserSession(currentUser, inventory);

                delete currentUser;
                currentUser = nullptr;
            }
            catch (const ShopException& e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 3) {
            try {
                FileManager::saveProducts(inventory);
            }
            catch (const ShopException& e) {
                cout << "Error while saving products: " << e.what() << endl;
            }

            cout << "Program ended. Thank you." << endl;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}

void runUserSession(User* currentUser, Inventory& inventory) {
    int choice;

    do {
        /*
            Runtime polymorphism happens here.

            currentUser is a User pointer.
            But it may point to either:
            - Customer object
            - Admin object

            Because showMenu() is virtual,
            the correct menu is shown at runtime.
        */
        currentUser->showMenu();
        cin >> choice;

        try {
            if (currentUser->getRole() == "Customer") {
                Customer* customer = dynamic_cast<Customer*>(currentUser);

                if (customer == nullptr) {
                    throw ShopException("Invalid customer object.");
                }

                switch (choice) {
                case 1:
                    customer->browseProducts(inventory);
                    break;

                case 2:
                    customer->addToCart(inventory);
                    break;

                case 3:
                    customer->removeFromCart();
                    break;

                case 4:
                    customer->viewCart();
                    break;

                case 5:
                    customer->placeOrder(inventory);
                    break;

                case 6:
                    cout << "Logging out from customer account." << endl;
                    break;

                default:
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            else if (currentUser->getRole() == "Admin") {
                Admin* admin = dynamic_cast<Admin*>(currentUser);

                if (admin == nullptr) {
                    throw ShopException("Invalid admin object.");
                }

                switch (choice) {
                case 1:
                    admin->viewInventory(inventory);
                    break;

                case 2:
                    admin->addProduct(inventory);
                    break;

                case 3:
                    admin->updateStock(inventory);
                    break;

                case 4:
                    admin->updatePrice(inventory);
                    break;

                case 5:
                    admin->removeProduct(inventory);
                    break;

                case 6:
                    FileManager::saveProducts(inventory);
                    cout << "Logging out from admin account." << endl;
                    break;

                default:
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
        }
        catch (const ShopException& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 6);
}