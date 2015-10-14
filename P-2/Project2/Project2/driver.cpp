/*****************************************
** File:    driver.cpp
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:   
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**   This file contains the main driver program for Project 2.
**
**
***********************************************/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "Manager.h"
#include "Sweet.h"
#include "Meat.h"

void printGreeting(); // prints greeting
using namespace std;


int main(int argc, char* argv[]) {
	
	cout << "\nThis is test" << endl;	

	

	// actual code for driver class
	std::ofstream outputFileStream;	

	//print greeting	
	printGreeting();
	cout << endl;


	
	Manager manager("Sample1Store.txt","Sample2Orders.txt");

	//open output file
	outputFileStream.open("results.txt");
	//take in store and order files
	//Manager manager(argv[1], argv[2]);	

	manager.printStatus(outputFileStream);

	manager.fillOrders(outputFileStream);

	//manager.printStatus(outputFileStream);

	//outputFileStream.close();

	system("pause");

	return EXIT_SUCCESS;
}

void printGreeting()
{
	cout << "Zafar Mamarakhimov, Section 05" << endl;
}


