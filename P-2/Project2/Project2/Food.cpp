/*****************************************
** File:    Food.cpp
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**
**
***********************************************/
#include "Food.h"


// default constructor
Food::Food() :m_dCost(0), m_sName("no-name")
{

}

//overloaded constructor
Food::Food(std::string name, FOOD_TYPE type, double price){

	m_sName = name;
	m_eType = type;
	m_dCost = price;

}

void Food::setType(FOOD_TYPE type){
	m_eType = type;
}


Food::FOOD_TYPE Food::getType()
{
	return m_eType;
}

//setting cost of the food
void Food::setCost(double cost){
	m_dCost = cost;
}

//getting the cost of food
double Food::getCost() const{
	return m_dCost;
}

//setting the name of the food
void Food::setName(std::string name){
	m_sName = name;
}

//getting the name of the food
std::string Food::getName(){
	return m_sName;
}


//overloaded cout for testing purposes
std::ostream& operator <<(std::ostream& outs, Food& food){

	outs << "\n Name: " << food.getName()  << std::endl;
	outs << " type: " << food.getType() << std::endl;
	outs << " cost: " << food.getCost() << std::endl;

	return outs;
}

/*	void setName(std::string name);
	std::string getName(*/
 
 

/*Food::~Food()
{
}
*/