/*****************************************
** File:    Store.h
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:	10/16/2015
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**
**
***********************************************/

#ifndef STORE_H
#define STORE_H
#include <vector>
#include <stack>
#include <string>
#include <fstream>
#include <iostream>
#include "Food.h"
#include "Sweet.h"
#include "Starch.h"
#include "Fruit.h"
#include "Meat.h"
#include "Vegetable.h"

class Store
{
public:
	Store();
	~Store();

	void addFood(Food* food);
	Food* getFoodByType(Food::FOOD_TYPE ftype);
	void stockStore(std::string filename);
	void printStore(std::ofstream& stream);



private:

	

	std::vector<std::stack<Food*> > m_bins;
	Food* food;
	//int meatCount, sweetCount, fruitCount, vegCount, starchCount;
	std::ifstream input;
	std::string foodName;
	std::string foodType;
	double cost;
	unsigned int foodCount;

	std::stack<Food*> sweet;
	std::stack<Food*> meat;
	std::stack<Food*> fruit;
	std::stack<Food*> veggie;
	std::stack<Food*> starch;

};

#endif
