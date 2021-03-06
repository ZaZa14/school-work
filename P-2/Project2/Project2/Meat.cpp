/*****************************************
** File:    Meat.cpp
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:	10/16/2015
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**
**
***********************************************/

#include "Meat.h"

Meat::Meat() :Food()
{
	setType(MEAT);
}

Meat::Meat(std::string name, FOOD_TYPE type, double cost)
	: Food(name, type, cost)
{
	
}

Meat::Meat(std::string name, double cost)
	: Food(name, Food::MEAT, cost)
{

}
