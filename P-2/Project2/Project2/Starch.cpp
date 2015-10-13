/*****************************************
** File:    Strach.cpp
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**
**
***********************************************/

#include "Starch.h"


//default constructor
Starch::Starch():Food()
{
	setType(STARCH);
}

//overloaded constructor
Starch::Starch(std::string name, FOOD_TYPE type, double cost)
	:Food(name, type, cost)
{
	
}

Starch::Starch(std::string name, double cost)
	: Food(name, Food::STARCH, cost)
{

}
/*Starch::~Starch()
{
}*/
