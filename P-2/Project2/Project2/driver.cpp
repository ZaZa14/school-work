/*****************************************
** File:    driver.cpp
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:   10/16/2015
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


void printGreeting(); // prints greeting
using namespace std;


int main(int argc, char* argv[]) {

	std::ofstream outputFileStream;

	//print greeting	
	printGreeting();
	
	Manager manager("Sample3Store.txt","Sample3Orders.txt");

	//open output file
	outputFileStream.open("results.txt", ios::app);

	//Manager manager(argv[1], argv[2]);	

	manager.printStatus(outputFileStream);

	manager.fillOrders(outputFileStream);	

	manager.printStatus(outputFileStream);

	outputFileStream.close();

	system("pause");

	return EXIT_SUCCESS;
}

// printing greeting to the file
void printGreeting()
{
	ofstream stream;
	stream.open("results.txt");
	if (stream.fail())
	{
		cout << "Cannot output greeting";
	}
	else
	{
		stream << "Zafar Mamarakhimov, Section 05" << endl;
	}	
	
}


