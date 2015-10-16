/*****************************************
** File:    Orders.cpp
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:	10/16/2015
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

// adds order to the queue
void Orders::addOrder(Order* orders)
{
	m_ordersUnfilled.push(orders);	
}

void Orders::setStore(Store* str)
{
	store = str;	
}

// completeing orders
void Orders::completeOrder()
{
	int size = m_ordersUnfilled.size();
	
	Order* ord;	

	for (int i = 0; i < size; i++)
	{
		ord = m_ordersUnfilled.front();
		if (ord->isAcceptPartial()){
			ord->setOrderComplete();
			m_ordersCompleted.push(ord);
			m_ordersUnfilled.pop();
		}
		else
		{
			m_ordersCompleted.push(ord);
			m_ordersUnfilled.pop();
		}
	}
}

// returns current order
Order* Orders::getCurrentOrder(){

	if (!m_ordersUnfilled.empty()){

		m_pCurrentOrder = m_ordersUnfilled.front();
		m_ordersUnfilled.pop();
		return m_pCurrentOrder;
	}

	else
		return NULL;
}




//loading Orders 
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
				
				m_pCurrentOrder = new Order; // creating new object of type Order
				
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
					//cout <<"\ntype " <<type;
				}				
				addOrder(m_pCurrentOrder);
			}
		}
	}

}


// printing orders
void Orders::printOrders(ofstream& stream){
	int queueSize = m_ordersUnfilled.size();
	string food = "";
	vector<Food::FOOD_TYPE> type;

	Order* temp;
	

	stream << "------------ Orders ------------" << endl;
	
	for ( int i = 0; i < queueSize; i++)
	{
		temp = m_ordersUnfilled.front();
		type = temp->getFoodTypes();

		int vectSize = type.size();
		stream << temp->getCustomeName() << endl;
		stream << "Requests: ";

		
		for (int i = 0; i < vectSize; i++)
		{
			switch (type.at(i))
			{
			case Food::SWEET:
				food = "Sweet";
				break;
			case Food::STARCH:
				food = "Starch";
				break;
			case Food::MEAT:
				food = "Meat";
				break;
			case Food::VEGETABLE:
				food = "Vegetable";
				break;
			case Food::FRUIT:
				food = "Fruit";
				break;
			default:
				food = "Unnkown type";
				break;
			}

			stream << food << " ";
		}	
		
		stream << "\n-------" << endl;
		m_ordersUnfilled.pop();
		m_ordersUnfilled.push(temp);		
	}
}

Orders::~Orders()
{
	delete m_pCurrentOrder;
}
