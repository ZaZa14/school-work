/*****************************************
** File:    Sweet.h
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**
**
***********************************************/

#ifndef SWEET_H
#define SWEET_H


#include "Food.h"
class Sweet :
	public Food
{
public:
	Sweet();
	Sweet(std::string name, FOOD_TYPE type, double cost);

private:
	//FOOD_TYPE sweet = FOOD_TYPE::SWEET;



	//~Sweet();
};

#endif

