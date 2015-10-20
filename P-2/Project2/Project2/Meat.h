/*****************************************
** File:    Meat.h
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:	10/16/2015
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**
**
***********************************************/

#ifndef MEAT_H
#define MEAT_H

#include "Food.h"
class Meat :
	public Food
{
public:
	Meat();
	Meat(std::string name, FOOD_TYPE type, double cost);
	Meat(std::string name, double cost);
	
};

#endif