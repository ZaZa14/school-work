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
	Food::FOOD_TYPE type = Food::SWEET;
	Food::FOOD_TYPE type1 = Food::STARCH;
	Food::FOOD_TYPE meat = Food::MEAT;

	Food f("omelette", type1, 5.50);

	Sweet s("candy", type, 10.5);

	Starch st("starch", type1, 50.65);

	Meat m;
	m.setCost(25.48);
	m.setName("Lamb");




	

	cout << "\nprice of the " << s.getName() << " is " << s.getCost() << " and type is " << s.getType() << endl;
	cout << "\nprice of the " << f.getName() << " is " << f.getCost() << " and type is " << f.getType() << endl;

	cout << f;
	cout << s;
	cout << st;
	cout << m;

	Store str;

	str.stockStore("Sample1Store.txt");
	
	ofstream output;
	output.open("results.txt");


	if (output.fail()){
		cout << "Cannot output file!";
		exit(1);
	}
	else
	{
		str.printStore(output);
	}





	//open output file
	//outputFileStream.open("results.txt");
	//take in store and order files
	//Manager manager(argv[1], argv[2]);

	

	/*manager.printStatus(outputFileStream);

	manager.fillOrders(outputFileStream);

	manager.printStatus(outputFileStream);

	outputFileStream.close();*/

	system("pause");

	return EXIT_SUCCESS;
}

void printGreeting()
{
	cout << "Zafar Mamarakhimov, Section 05" << endl;
}


