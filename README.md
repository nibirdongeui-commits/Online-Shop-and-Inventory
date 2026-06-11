Online Shop and Inventory Management System
OOP II Final Project using C++

Project Topic
Topic 4: Online Shop and Inventory Management

This is a CLI-based system where customers can browse products, add products to cart, remove products from cart, view cart, and place orders. Admins can manage the inventory by adding products, updating stock, updating price, removing products, and viewing inventory.

Main Features

Customer Features
- Login as customer
- View available products
- Add product to cart
- Remove product from cart
- View cart
- Place order

Admin Features
- Login as admin
- View inventory
- Add product
- Update product stock
- Update product price
- Remove product
- Save inventory

OOP Concepts Used

Classes and Objects
The system is divided into classes such as User, Customer, Admin, Product, Inventory, Cart, Order, FileManager, and ShopException.

Encapsulation
Class data members are kept private or protected. Public functions are used to access and update data safely.

Inheritance
Customer and Admin inherit from the User class.

Abstraction
User is an abstract class because it contains pure virtual functions:
- showMenu()
- getRole()

Runtime Polymorphism
The program uses a User pointer:

User* currentUser;

This pointer can point to either a Customer object or an Admin object. When showMenu() is called, the correct menu is shown depending on the actual object type.

Composition
- Customer has a Cart
- Inventory has Products
- Cart has Products
- Order has Products

Exception Handling
The project uses a custom exception class called ShopException to handle errors like invalid product ID, invalid quantity, empty cart, not enough stock, and file errors.

File I/O
The project uses text files to save and load data:
- products.txt
- users.txt
- orders.txt

Team Role Division

Team Leader: Fardin_20244161
Responsible for:
- Project structure
- UML class diagram(https://app.diagrams.net/#G1RJloo_nOhEuhmih4eKgkr8KUCdMudOKg#%7B%22pageId%22%3A%22zT96hbVSgQXTfI3tT45N%22%7D)
- User class
- Customer class
- Admin class
- Main program flow
- Runtime polymorphism
- README

Member 2
Responsible for:
- Product class
- Inventory class
- Product CRUD operations

Member 3
Responsible for:
- Cart class
- Order class
- Cart and order management

Member 4
Responsible for:
- FileManager class
- ShopException class
- Text files
- Testing

File Structure

main.cpp

User.h
User.cpp
Customer.h
Customer.cpp
Admin.h
Admin.cpp

Product.h
Product.cpp
Inventory.h
Inventory.cpp

Cart.h
Cart.cpp
Order.h
Order.cpp

FileManager.h
FileManager.cpp
ShopException.h

products.txt
users.txt
orders.txt

README.md
UML_Diagram.drawio
UML_Diagram.png

Sample Login Data

admin admin123 admin
fardin 123 customer

Sample Product Data

1 Mouse 500 20
2 Keyboard 1500 10
3 Laptop 90000 5

How to compile:

g++ -std=c++17 src/*.cpp -Iinclude -o shop.exe

How to run:

.\shop.exe


Notes
This project is completely CLI-based. It does not use GUI or database. Data is stored using text files.
