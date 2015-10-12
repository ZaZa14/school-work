/*****************************************
** File:    Store.cpp
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
** 
**
***********************************************/

#include "Store.h"
#include <sstream>
#include <cstdlib>



//default constructor
Store::Store() :meatCount(0), sweetCount(0), fruitCount(0), vegCount(0), starchCount(0)
{

}

void Store::addFood(Food* food)
{
	
}

Food* Store::getFoodByType(Food::FOOD_TYPE ftype){



	return foodList;
}


void Store::stockStore(std::string filename)
{
	input.open(filename.c_str());
	if (input.fail())
	{
		std::cout << "File is not found!";
		exit(1);
	}	
	else
	{		
		std::string line = "";
		std::string skip = "";
		
		while (std::getline(input, line, '\n')) //delimeter is new line
		{
			if (line != "")
			{
				std::stringstream stream(line);				
														
				while (std::getline(std::getline(stream, skip, '"'), foodName, '"') >> foodType >> cost) // gets rid of quotes
				{					
					std::cout << "food " << foodName << " "<< foodType << " " <<cost <<  std::endl;
					foodCount++; //total amount of food in the store
				}
			}
		}
	}

	std::cout << "size if the vector ";
	
	input.close();
}

void Store::printStore(std::ofstream& stream){
	
	stream << "\n ---------- Store ----------" << std::endl;
}

Store::~Store()
{
}
