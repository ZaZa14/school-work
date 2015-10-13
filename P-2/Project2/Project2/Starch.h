/*****************************************
** File:    Starch.h
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**
**
***********************************************/

#ifndef STARCH_H
#define STARCH_H

#include "Food.h"
class Starch :
	public Food
{
public:
	Starch();
	Starch(std::string name, FOOD_TYPE type, double cost);
	Starch(std::string name, double cost);

	//~Starch();
};

#endif