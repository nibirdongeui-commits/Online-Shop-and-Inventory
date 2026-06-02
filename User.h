#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string username;
    string password;

public:
    User();
    User(string username, string password);

    string getUsername();
    bool checkPassword(string pass);

    virtual void showMenu() = 0;
    virtual string getRole() = 0;

    virtual ~User();
};

#endif