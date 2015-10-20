/*****************************************
** File:    Order.h
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:	10/16/2015
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
#include "Food.h"

class Order
{
public:
	Order(); //default constructor
	~Order();

	void setCustomerName(std::string name);
	void setAcceptPartical(bool partial);
	void setOrderComplete();
	bool isAcceptPartial();

	Food::FOOD_TYPE& getNextRequest();
	void addRequestToOrder(Food::FOOD_TYPE foodType);
	void addFoodToOrder(Food* food);
	Food* popFoodFromOrder();

	void printOrder(std::ofstream& list);
	std::string getCustomeName();
	std::vector<Food::FOOD_TYPE> getFoodTypes();
	std::queue<Food::FOOD_TYPE>getTypeQueue();
	std::string getCustomerName();
	
	
	void getFoodFromStore(Store& str);


	void setStoreforOrder(Store& str);


private:
	std::string m_sCustomerName;
	std::queue<Food::FOOD_TYPE> m_requests;
	bool m_bAcceptsPartialOrder;
	bool m_bOrderCompleted;
	std::queue<Food*> m_filledRequests;
	Food::FOOD_TYPE foodType;
	

	Food* food;
	std::vector<Food::FOOD_TYPE> types;

};

#endif

