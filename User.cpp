#include "User.h"

User::User() {
    username = "";
    password = "";
}

User::User(string username, string password) {
    this->username = username;
    this->password = password;
}

string User::getUsername() {
    return username;
}

bool User::checkPassword(string pass) {
    return password == pass;
}

User::~User() {
}