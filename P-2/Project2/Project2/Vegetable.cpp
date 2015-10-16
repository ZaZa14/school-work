/*****************************************
** File:    Vegetable.cpp
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:	10/16/2015
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**
**
***********************************************/

#include "Vegetable.h"

//default constructor will set the type of the food
Vegetable::Vegetable() : Food()
{
	setType(VEGETABLE); 
}

//overloaded constructor
Vegetable::Vegetable(std::string name, FOOD_TYPE type, double cost)
	: Food(name, type, cost)
{

}

Vegetable::Vegetable(std::string name, double cost)
	: Food(name, Food::VEGETABLE, cost)
{

}

