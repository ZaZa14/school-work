/*****************************************
** File:    Fruit.h
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**
**
***********************************************/

#ifndef FRUIT_H
#define FRUIT_H

#include "Food.h"
class Fruit :
	public Food
{
public:
	Fruit();
	Fruit(std::string name, FOOD_TYPE type, double cost);
	Fruit(std::string name, double cost);


	//~Fruit();
};

#endif
