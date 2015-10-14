/*****************************************
** File:    Manager.cpp
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**
**
***********************************************/

#include "Manager.h"
#include <cstdlib>

const std::string Manager::outputFile = "results.txt";

// Default constructor
Manager::Manager()
{
	
}

/* Overloaded constructor Gets filename from the user 
 * and creates orders ann stores */
Manager::Manager(char* store, char* order)
{

	createStore(store);
	createOrders(order);
}


// Creates store from input file
void Manager::createStore(std::string filename)
{
	m_store.stockStore(filename);
	
}



// Creates orders from input file
void Manager::createOrders(std::string filename)
{
	m_orders.loadOrders(filename);
}

// fills orders
void Manager::fillOrders(std::ofstream& stream)
{
	// this shoudl be changed
	stream.open("results.txt", std::ios_base::app);
	if (stream.fail()){
		std::cout << "Cannot output file!";
		exit(1);
	}
	else
	{
		m_orders.printOrders(stream);
	}

}

// prints out the status for every transaction
void Manager::printStatus(std::ofstream& stream)
{
	m_store.printStore(stream);
}

/*Manager::~Manager()
{
}*/
