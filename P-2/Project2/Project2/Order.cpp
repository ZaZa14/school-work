/*****************************************
** File:    Order.cpp
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:
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
	m_requests.pop();
	return foodType;
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

//	prints the food order
void Order::printOrder(ofstream& list)
{

}



Order::~Order()
{
	delete food;
}
