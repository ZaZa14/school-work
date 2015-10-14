/*****************************************
** File:    Orders.cpp
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**
**
***********************************************/

#include "Orders.h"
#include <cstdlib>
#include <sstream>
#include <vector>
using namespace  std;

// default constructor
Orders::Orders()
{
	
}


void Orders::addOrder(Order* orders)
{

}

void Orders::loadOrders(string filename)
{
	input.open(filename.c_str());
	if (input.fail()){
		cout << "\nCannot find input file!\n";
		exit(1);
	}
	else
	{	
		string accepts = "";
		string line = "";		
		string customerName = "";
		
		string temp = "";
		int length = 0;

		string type = "";

		while (getline(input, line, '\n')) //delimeter is new line
		{
			if (line != ""){
				//cout << "line: " << line << endl;

				line = line.substr(1, line.size() - 1);
				temp = strchr(line.c_str(), '"');
				length = line.size() - temp.size();
				customerName = line.substr(0, length);
				//cout << "Changed: "<< customerName << " ";
				line = line.substr(length + 2, line.size() - 1);
				//cout << line << endl;
				istringstream secondHalf(line.c_str());				
				secondHalf >> accepts; // partial accept
				
				m_pCurrentOrder = new Order;
				
				m_pCurrentOrder->setCustomerName(customerName);

				if (accepts == "yes")
					m_pCurrentOrder->setAcceptPartical(true);
				else
					m_pCurrentOrder->setAcceptPartical(false);
				
				
				// gets only type of food in the food order 
				while (secondHalf >> type)
				{					
					if (type == "vegetable"){
						m_pCurrentOrder->addRequestToOrder(Food::VEGETABLE);
					}
					if (type == "sweet"){
						m_pCurrentOrder->addRequestToOrder(Food::SWEET);
					}
					if (type == "starch"){
						m_pCurrentOrder->addRequestToOrder(Food::STARCH);
					}
					if (type == "meat"){
						m_pCurrentOrder->addRequestToOrder(Food::MEAT);
					}
					if (type == "fruit"){
						m_pCurrentOrder->addRequestToOrder(Food::FRUIT);
					}

					//cout << " "<<type ;
				}

				//cout << endl << endl;

			}
		}
	}

}


// 
void Orders::printOrders(ofstream& stream){

	stream << "------------ Orders ------------" << endl;
}






Orders::~Orders()
{
	delete m_pCurrentOrder;
}
