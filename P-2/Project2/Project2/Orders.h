/*****************************************
** File:    Orders.h
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**
**
***********************************************/

#ifndef ORDERS_H
#define ORDERS_H
#include"Order.h"

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

private:
	std::queue <Order*> m_ordersUnfilled;
	std::queue<Order*> m_ordersCompleted;
	Order* m_pCurrentOrder;

};

#endif

