###########################################################################
# Makefile for project 3
###########################################################################
CXX = g++
CXXFLAGS = -ansi -Wall -g


all: Proj3.o AugmentedBinarySearchTree.o BinarySearchTree.o Proj3Aux.o
	$(CXX) $(CXXFLAGS) Proj3.o AugmentedBinarySearchTree.o BinarySearchTree.o Proj3Aux.o -o Proj3

Proj3.o: Proj3.cpp
	$(CXX) $(CXXFLAGS) -c Proj3.cpp

AugmentedBinarySearchTree.o: AugmentedBinarySearchTree.cpp AugmentedBinarySearchTree.h
	$(CXX) $(CXXFLAGS) -c AugmentedBinarySearchTree.cpp

BinarySearchTree.o: BinarySearchTree.cpp
	$(CXX) $(CXXFLAGS) -c BinarySearchTree.cpp


Proj3Aux.o: Proj3Aux.cpp
	$(CXX) $(CXXFLAGS) -c Proj3Aux.cpp

run:
	./Proj3

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#