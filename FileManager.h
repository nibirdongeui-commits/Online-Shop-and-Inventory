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

    static void saveProducts(Inventory& inventory);

    static bool validateLogin(
        string username,
        string password,
        string role
    );

    static void saveOrder(Order& order);
};

#endif
