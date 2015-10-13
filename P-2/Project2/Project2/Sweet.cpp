/*****************************************
** File:    Sweet.cpp
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**
**
***********************************************/

#include "Sweet.h"


// default constuctor
Sweet::Sweet():Food()
{
	setType(SWEET);
}

//overloaded constructor will call parent class
Sweet::Sweet(std::string name, FOOD_TYPE type, double cost)
	:Food(name, type, cost)
{

}

Sweet::Sweet(std::string name, double cost)
	: Food(name, Food::SWEET ,cost)
{
	//setType(SWEET);
}


/*Sweet::~Sweet()
{
}*/
