#include "Inventory.h"
#include "ShopException.h"

#include <iostream>

using namespace std;

Inventory::Inventory()
{
    productCount = 0;
}

bool Inventory::productExists(int productId)
{
    for (int i = 0; i < productCount; i++)
    {
        if (products[i].getId() == productId)
        {
            return true;
        }
    }

    return false;
}

void Inventory::addProduct(Product product)
{
    if (productCount >= 100)
    {
        throw ShopException("Inventory is full.");
    }

    if (product.getId() <= 0)
    {
        throw ShopException("Invalid product ID.");
    }

    if (productExists(product.getId()))
    {
        throw ShopException("Product ID already exists.");
    }

    if (product.getPrice() <= 0)
    {
        throw ShopException("Price must be greater than zero.");
    }

    if (product.getQuantity() < 0)
    {
        throw ShopException("Quantity cannot be negative.");
    }

    products[productCount] = product;
    productCount++;
}

void Inventory::removeProduct(int productId)
{
    int index = -1;

    for (int i = 0; i < productCount; i++)
    {
        if (products[i].getId() == productId)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        throw ShopException("Product not found.");
    }

    for (int i = index; i < productCount - 1; i++)
    {
        products[i] = products[i + 1];
    }

    productCount--;
}

void Inventory::updateStock(int productId, int quantity)
{
    if (quantity < 0)
    {
        throw ShopException("Quantity cannot be negative.");
    }

    for (int i = 0; i < productCount; i++)
    {
        if (products[i].getId() == productId)
        {
            products[i].setQuantity(quantity);
            return;
        }
    }

    throw ShopException("Product not found.");
}

void Inventory::updatePrice(int productId, double price)
{
    if (price <= 0)
    {
        throw ShopException("Price must be greater than zero.");
    }

    for (int i = 0; i < productCount; i++)
    {
        if (products[i].getId() == productId)
        {
            products[i].setPrice(price);
            return;
        }
    }

    throw ShopException("Product not found.");
}

Product Inventory::getProductById(int productId)
{
    for (int i = 0; i < productCount; i++)
    {
        if (products[i].getId() == productId)
        {
            return products[i];
        }
    }

    throw ShopException("Product not found.");
}

void Inventory::displayProducts()
{
    if (productCount == 0)
    {
        cout << "No products available." << endl;
        return;
    }

    for (int i = 0; i < productCount; i++)
    {
        products[i].display();
    }
}

int Inventory::getProductCount() const
{
    return productCount;
}

Product Inventory::getProductAt(int index)
{
    if (index < 0 || index >= productCount)
    {
        throw ShopException("Invalid product index.");
    }

    return products[index];
}

void Inventory::decreaseStock(int productId, int quantity)
{
    if (quantity <= 0)
    {
        throw ShopException("Invalid quantity.");
    }

    for (int i = 0; i < productCount; i++)
    {
        if (products[i].getId() == productId)
        {
            int currentQuantity = products[i].getQuantity();

            if (currentQuantity < quantity)
            {
                throw ShopException("Insufficient stock.");
            }

            products[i].setQuantity(currentQuantity - quantity);
            return;
        }
    }

    throw ShopException("Product not found.");
}
