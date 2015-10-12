/*****************************************
** File:    Order.h
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**
**
***********************************************/

#ifndef _ORDER_H
#define _ORDER_H
#include<queue>
#include"Store.h"

class Order
{
public:
	Order(); //default constructor
	~Order();

	void setCustomerName(std::string name);
	void setAcceptPartical(bool partical);
	void setOrderComplete(bool complete);
	bool isAcceptPartial();

	Food::FOOD_TYPE& getNextRequest();
	void addRequestToOrder(Food::FOOD_TYPE foodType);
	void addFoodToOrder(Food* food);
	Food* popFoodFromOrder();

	void printOrder(std::ofstream& list);



private:
	std::string m_sCustomerName;
	std::queue<Food::FOOD_TYPE> m_requests;
	bool m_bAcceptsCompleted;
	std::queue<Food*> m_filledRequests;

};

#endif

