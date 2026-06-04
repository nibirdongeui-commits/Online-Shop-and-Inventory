#include "Product.h"
#include <iostream>

using namespace std;

Product::Product()
{
    id = 0;
    name = "";
    price = 0.0;
    quantity = 0;
}

Product::Product(int id, string name, double price, int quantity)
{
    this->id = id;
    this->name = name;
    this->price = price;
    this->quantity = quantity;
}

int Product::getId() const
{
    return id;
}

string Product::getName() const
{
    return name;
}

double Product::getPrice() const
{
    return price;
}

int Product::getQuantity() const
{
    return quantity;
}

void Product::setName(string name)
{
    this->name = name;
}

void Product::setPrice(double price)
{
    this->price = price;
}

void Product::setQuantity(int quantity)
{
    this->quantity = quantity;
}

void Product::display() const
{
    cout << "ID: " << id
         << " | Name: " << name
         << " | Price: " << price
         << " | Quantity: " << quantity
         << endl;
}
