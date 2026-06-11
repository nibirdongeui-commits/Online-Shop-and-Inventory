app: main.o User.o Customer.o Admin.o Product.o Inventory.o Cart.o Order.o FileManager.o
	g++ main.o User.o Customer.o Admin.o Product.o Inventory.o Cart.o Order.o FileManager.o -o app

main.o: src/main.cpp
	g++ -c src/main.cpp -Iinclude

User.o: src/User.cpp
	g++ -c src/User.cpp -Iinclude

Customer.o: src/Customer.cpp
	g++ -c src/Customer.cpp -Iinclude

Admin.o: src/Admin.cpp
	g++ -c src/Admin.cpp -Iinclude

Product.o: src/Product.cpp
	g++ -c src/Product.cpp -Iinclude

Inventory.o: src/Inventory.cpp
	g++ -c src/Inventory.cpp -Iinclude

Cart.o: src/Cart.cpp
	g++ -c src/Cart.cpp -Iinclude

Order.o: src/Order.cpp
	g++ -c src/Order.cpp -Iinclude

FileManager.o: src/FileManager.cpp
	g++ -c src/FileManager.cpp -Iinclude

clean:
	del *.o app.exe