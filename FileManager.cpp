#include "FileManager.h"
#include "ShopException.h"

#include <fstream>
#include <iostream>

using namespace std;

void FileManager::loadProducts(Inventory& inventory)
{
    ifstream file("products.txt");

    if (!file.is_open())
    {
        throw ShopException("File could not open.");
    }

    int id;
    string name;
    double price;
    int quantity;

    while (file >> id >> name >> price >> quantity)
    {
        try
        {
            Product product(id, name, price, quantity);
            inventory.addProduct(product);
        }
        catch (ShopException& e)
        {
            cout << "Error loading product: "
                 << e.what()
                 << endl;
        }
    }

    file.close();
}

void FileManager::saveProducts(Inventory& inventory)
{
    ofstream file("products.txt");

    if (!file.is_open())
    {
        throw ShopException("File could not open.");
    }

    for (int i = 0; i < inventory.getProductCount(); i++)
    {
        Product product = inventory.getProductAt(i);

        file
            << product.getId() << " "
            << product.getName() << " "
            << product.getPrice() << " "
            << product.getQuantity()
            << endl;
    }

    file.close();
}

bool FileManager::validateLogin(
    string username,
    string password,
    string role
)
{
    ifstream file("users.txt");

    if (!file.is_open())
    {
        throw ShopException("File could not open.");
    }

    string fileUsername;
    string filePassword;
    string fileRole;

    while (
        file
        >> fileUsername
        >> filePassword
        >> fileRole
    )
    {
        if (
            fileUsername == username &&
            filePassword == password &&
            fileRole == role
        )
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void FileManager::saveOrder(Order& order)
{
    ofstream file(
        "orders.txt",
        ios::app
    );

    if (!file.is_open())
    {
        throw ShopException("File could not open.");
    }

    file << order.toFileString();

    file.close();
}
