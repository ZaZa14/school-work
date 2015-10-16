/*****************************************
** File:    Order.cpp
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:	10/16/2015
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**
**
***********************************************/

#include "Order.h"
using namespace std;

// default constructor
Order::Order() : m_sCustomerName("")
{

}


// sets customer name
void Order::setCustomerName(string name)
{
	m_sCustomerName = name;
	//cout << name << endl;
}

string Order::getCustomerName(){
	return m_sCustomerName;
}

// sets partial order
void Order::setAcceptPartical(bool partial)
{
	m_bAcceptsPartialOrder = partial;
}

// sets final order
void Order::setOrderComplete()
{
	m_bOrderCompleted = true;
}

// checks if the partial order is accepted or not
bool Order::isAcceptPartial()
{
	return m_bAcceptsPartialOrder;
}

// adds food to the order
void Order::addFoodToOrder(Food* food)
{
	m_filledRequests.push(food);
}

// gets next request in the order
Food::FOOD_TYPE& Order::getNextRequest()
{
	foodType = m_requests.front();
	cout << "\nfood type " <<foodType << endl;
	m_requests.pop();
	//requests.push(foodType);
	return foodType;
}

vector<Food::FOOD_TYPE> Order::getFoodTypes()
{
	int size = m_requests.size();
	for (int i = 0; i < size; i++)
	{
		foodType = m_requests.front();
		m_requests.pop();
		types.push_back(foodType);
		m_requests.push(foodType);
	}

	return types;
}

// adds food type to the order
void Order::addRequestToOrder(Food::FOOD_TYPE foodType)
{
	m_requests.push(foodType); //adds food type to the queue	
}

Food* Order:: popFoodFromOrder()
{
	food = m_filledRequests.front();
	m_filledRequests.pop();
	return food;
}

queue<Food::FOOD_TYPE> Order::getTypeQueue()
{
	return m_requests;
}
 
// returns name of the customer
string Order::getCustomeName()
{
	return m_sCustomerName;
}

// will get list foods from the store and put them into queue
/*void Order::getFoodFromStore(Store& str)
{
	int size = m_requests.size();
	Food* temp;
	cout << "size of queue " << size <<endl;
	for (int i = 0; i < size; i++)
	{
		temp = str.getFoodByType(getNextRequest());
		cout << *temp;

		addFoodToOrder(temp);
	}
}*/

//	prints the food order
void Order::printOrder(ofstream& list)
{
	//getFoodFromStore();
	list << "\n------------ Orders ------------\n";


	//if the order is complete print whole order
	if (m_bOrderCompleted && isAcceptPartial())
	{
	
	}
	else if (!m_bOrderCompleted && isAcceptPartial())
	{

	}

	// if order is not complete print partial order

}



Order::~Order()
{
	delete food;
}
