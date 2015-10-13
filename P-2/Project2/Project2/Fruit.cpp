/*****************************************
** File:    Fruit.cpp
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**
**
***********************************************/

#include "Fruit.h"


//Default constructor
Fruit::Fruit() : Food()
{
	setType(FRUIT);
}


//Overloaded constructor
Fruit::Fruit(std::string name, FOOD_TYPE type, double cost)
	:Food(name, type, cost)
{

}

Fruit::Fruit(std::string name, double cost)
	: Food(name, Food::FRUIT, cost)
{

}

/*Fruit::~Fruit()
{
}*/
