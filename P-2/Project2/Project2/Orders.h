/*****************************************
** File:    Orders.h
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:	10/16/2015
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**
**
***********************************************/

#ifndef ORDERS_H
#define ORDERS_H
#include"Order.h"
#include <cstring>

class Orders
{
public:
	Orders();
	~Orders();

	void addOrder(Order* orders);
	void completeOrder();
	Order* getCurrentOrder();
	void loadOrders(std::string filename);
	void printOrders(std::ofstream& stream);
	void setStore(Store* str);
	std::queue<Food::FOOD_TYPE> getFoodtypes();
	
	

private:
	std::queue <Order*> m_ordersUnfilled;
	std::queue<Order*> m_ordersCompleted;
	Order* m_pCurrentOrder;
	std::ifstream input;
	Store* store;
	//std::string getCustomerName(std::string& str);
	

};

#endif

