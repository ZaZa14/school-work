###########################################################################
# Makefile for project 2
###########################################################################

CXX = g++
CXXFLAGS = -ansi -Wall -g

all: driver.o Food.o Manager.o Store.o Orders.o Order.o Sweet.o Fruit.o Meat.o Starch.o Vegetable.o
	$(CXX) $(CXXFLAGS) driver.o Food.o Manager.o Store.o Orders.o Order.o Sweet.o Fruit.o Meat.o Starch.o Vegetable.o -o driver.out

driver.o: driver.cpp
	$(CXX) $(CXXFLAGS) -c driver.cpp

Manager.o:Manager.cpp
	$(CXX) $(CXXFLAGS) -c Manager.cpp
	
Store.o: Store.cpp
	$(CXX) $(CXXFLAGS) -c Store.cpp
	
Orders.o:
	$(CXX) $(CXXFLAGS) -c Orders.cpp
	
Order.o:
	$(CXX) $(CXXFLAGS) -c Order.cpp

Sweet.o:
	$(CXX) $(CXXFLAGS) -c Sweet.cpp
	
Fruit.o:
	$(CXX) $(CXXFLAGS) -c Fruit.cpp
	
Meat.o:
	$(CXX) $(CXXFLAGS) -c Meat.cpp
	
Starch.o:
	$(CXX) $(CXXFLAGS) -c Starch.cpp
	
Vegetable.o:
	$(CXX) $(CXXFLAGS) -c Vegetable.cpp
	
run:
	./driver.out $(STORE) $(ORDERS)
	
clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#
	
