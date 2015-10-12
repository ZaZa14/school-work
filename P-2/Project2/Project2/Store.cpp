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
#include<sstream>



//default constructor
Store::Store() :meatCount(0), fruitCount(0), vegCount(0), starchCount(0), sweetCount(0)
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
	input.open(filename);
	if (input.fail())
	{
		std::cout << "File is not found!";
		exit(1);
	}	
	else
	{
		/*std::string foodName = ""; std::string foodType = "";
		double cost;
		input >> foodName >> foodType >> cost;
		foodName = foodName.substr(1, foodName.size()-2);

		std::cout << foodName << " " << foodType << " " << cost << std::endl;
		input >> foodName >> foodType >> cost;
		foodName = foodName.substr(1, foodName.size() - 2);
		std::cout << foodName << " " << foodType << " " << cost << std::endl;

		input >> foodName >> foodType >> cost;
		//foodName = foodName.substr(1, foodName.size() - 2);
		std::cout << foodName << " " << foodType << " " << cost << std::endl;*/

		//infinite loop
		/*while (!input.eof())
		{
			input >> foodName >> foodType >> cost;
			std::cout << foodName << " " << foodType << " " << cost << std::endl;
		}*/

		std::string line = "";
		while (std::getline(input, line, '\n')) //delimeter is new line
		{
			if (line != "")
			{
				std::stringstream stream(line);
				std::string foodName = "";
				while (std::getline(stream, foodName, '"') || std::getline(stream, foodName, ' ')) //delimeter is space
				{					
					std::cout << "current word " << foodName << std::endl;
				}
			}
		}
	}


	input.close();


}

void Store::printStore(std::ofstream& stream){
	
	stream << "\n ---------- Store ----------" << std::endl;
}

Store::~Store()
{
}
