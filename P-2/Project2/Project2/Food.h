/*****************************************
** File:    Food.h
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
** Header file for Food class
**
***********************************************/
#include<fstream>
#include<string>
#ifndef FOOD_H
#define FOOD_H



class Food
{
public:
	enum FOOD_TYPE{ SWEET, STARCH, MEAT, VEGETABLE, FRUIT}; //no type for initilizing the defualt constructor

	Food();
	Food(std::string name, FOOD_TYPE type, double price);
	//Food(std::string name, double price);

	
	Food::FOOD_TYPE getType();

	void printFood(std::ofstream& output);
	void setType(FOOD_TYPE type);


	//accessors and mutators
	void setCost(double cost);
	double getCost() const;

	void setName(std::string name);
	std::string getName();

	//oveloaded cout
	friend std::ostream& operator <<(std::ostream& outs, Food& food);

	

private:
	std::string m_sName;
	Food::FOOD_TYPE m_eType;
	double m_dCost;




	//~Food();
};

#endif
