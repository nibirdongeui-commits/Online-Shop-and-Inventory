#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "Inventory.h"
#include "Order.h"

using namespace std;

class FileManager
{
public:
    static void loadProducts(Inventory& inventory);
    static void saveProducts(const Inventory& inventory);

    static bool validateLogin(
        const string& username,
        const string& password,
        const string& role
    );

    static void saveOrder(const Order& order);
};

#endif
