CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

TARGET = shop.exe
SRC = src/main.cpp src/User.cpp src/Customer.cpp src/Admin.cpp src/Product.cpp src/Inventory.cpp src/Cart.cpp src/Order.cpp src/FileManager.cpp
OBJ = main.o User.o Customer.o Admin.o Product.o Inventory.o Cart.o Order.o FileManager.o

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp

User.o: src/User.cpp
	$(CXX) $(CXXFLAGS) -c src/User.cpp

Customer.o: src/Customer.cpp
	$(CXX) $(CXXFLAGS) -c src/Customer.cpp

Admin.o: src/Admin.cpp
	$(CXX) $(CXXFLAGS) -c src/Admin.cpp

Product.o: src/Product.cpp
	$(CXX) $(CXXFLAGS) -c src/Product.cpp

Inventory.o: src/Inventory.cpp
	$(CXX) $(CXXFLAGS) -c src/Inventory.cpp

Cart.o: src/Cart.cpp
	$(CXX) $(CXXFLAGS) -c src/Cart.cpp

Order.o: src/Order.cpp
	$(CXX) $(CXXFLAGS) -c src/Order.cpp

FileManager.o: src/FileManager.cpp
	$(CXX) $(CXXFLAGS) -c src/FileManager.cpp

clean:
	del /Q *.o *.exe