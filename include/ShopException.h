#ifndef SHOPEXCEPTION_H
#define SHOPEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class ShopException : public exception
{
private:
    string message;

public:
    ShopException(string message)
    {
        this->message = message;
    }

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

#endif
