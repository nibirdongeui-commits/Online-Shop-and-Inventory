#include "../include/FileManager.h"
#include "../include/ShopException.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void FileManager::loadProducts(Inventory& inventory)
{
    ifstream file("products.txt");

    if (!file.is_open())
    {
        return;
    }

    string line;

    while (getline(file, line))
    {
        if (line.empty())
        {
            continue;
        }

        stringstream ss(line);

        int id;
        string name;
        double price;
        int quantity;

        string temp;

        getline(ss, temp, ',');
        id = stoi(temp);

        getline(ss, name, ',');

        getline(ss, temp, ',');
        price = stod(temp);

        getline(ss, temp, ',');
        quantity = stoi(temp);

        Product product(id, name, price, quantity);
        inventory.addProduct(product);
    }

    file.close();
}

void FileManager::saveProducts(Inventory& inventory) {
    ofstream file("products.txt");

    if (!file.is_open()) {
        throw ShopException("Could not open products.txt for saving.");
    }

    for (int i = 0; i < inventory.getProductCount(); i++) {
        Product product = inventory.getProductAt(i);

        file << product.getId() << ","
             << product.getName() << ","
             << product.getPrice() << ","
             << product.getQuantity() << endl;
    }

    file.close();
}

bool FileManager::validateLogin(
    const string& username,
    const string& password,
    const string& role)
{
    ifstream file("users.txt");

    if (!file.is_open())
    {
        return false;
    }

    string fileUsername;
    string filePassword;
    string fileRole;

    while (file >> fileUsername >> filePassword >> fileRole)
    {
        if (fileUsername == username &&
            filePassword == password &&
            fileRole == role)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void FileManager::saveOrder(const Order& order)
{
    ofstream file("orders.txt", ios::app);

    if (!file.is_open())
    {
        return;
    }

    file << order.toFileString() << endl;

    file.close();
}
