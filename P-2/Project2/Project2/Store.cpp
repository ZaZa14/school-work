/*****************************************
** File:    Store.cpp
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:	10/16/2015
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
** 
**
***********************************************/

#include "Store.h"
#include <sstream>
#include <cstdlib>
//using namespace std;


//default constructor
Store::Store()
{

	m_bins.push_back(sweet);
	m_bins.push_back(starch);
	m_bins.push_back(meat);
	m_bins.push_back(veggie);
	m_bins.push_back(fruit);

}


/* Adds type of food to the specific stack*/
void Store::addFood(Food* food)
{
	switch (food->getType())
	{
	case Food::SWEET:
		m_bins[Food::SWEET].push(food);
		break;
	case Food::STARCH:
		m_bins[Food::STARCH].push(food);
		break;
	case Food::MEAT:
		m_bins[Food::MEAT].push(food);
		break;
	case Food::VEGETABLE:
		m_bins[Food::VEGETABLE].push(food);
		break;
	case Food::FRUIT:
		m_bins[Food::FRUIT].push(food);
		break;

	default: 
		std::cout << "Undefined type of food" << std::endl;
		break;
	}
}

/* Pops the food type from the stack and returns it;
 * if stack is empty NULL will be returned */
Food* Store::getFoodByType(Food::FOOD_TYPE ftype){

	switch (ftype)
	{
	case Food::SWEET:
		if (!m_bins[Food::SWEET].empty())
		{
			food = m_bins[Food::SWEET].top();
			m_bins[Food::SWEET].pop();
		}
		else
		{
			food = NULL;
		}		
		break;
	case Food::STARCH:
		if (!m_bins[Food::STARCH].empty())
		{
			food = m_bins[Food::STARCH].top();
			m_bins[Food::STARCH].pop();
		}
		else
		{
			food = NULL;
		}		
		break;
	case Food::MEAT:
		if (!m_bins[Food::MEAT].empty())
		{
			food = m_bins[Food::MEAT].top();
			m_bins[Food::MEAT].pop();
		}
		else
		{
			food = NULL;
		}	
		break;
	case Food::VEGETABLE:
		if (!m_bins[Food::VEGETABLE].empty())
		{
			food = m_bins[Food::VEGETABLE].top();
			m_bins[Food::VEGETABLE].pop();
		}
		else
		{
			food = NULL;
		}
		break;
	case Food::FRUIT:
		if (!m_bins[Food::FRUIT].empty())
		{
			food = m_bins[Food::FRUIT].top();
			m_bins[Food::FRUIT].pop();
		}
		else
		{
			food = NULL;
		}	
		break;
	default:
		std::cout << "Undefined type of food" << std::endl;
		break;
	}

	return food;
}

/* Created store by getting input and adding food type to the stack */
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
		Food* tempFood = NULL;
		
		while (std::getline(input, line, '\n')) //delimeter is new line
		{
			if (line != "")
			{
				std::stringstream stream(line);				
														
				while (std::getline(std::getline(stream, skip, '"'), foodName, '"') >> foodType >> cost) // gets rid of quotes
				{					
					//adding food to the stack				
					if (foodType == "vegetable"){
						tempFood = new Vegetable(foodName, cost);
					}
					if (foodType == "sweet"){
						tempFood = new Sweet(foodName, cost);
					}
					if (foodType == "starch"){
						tempFood = new Starch(foodName, cost);
					}
					if (foodType == "meat"){
						tempFood = new Meat(foodName, cost);
					}
					if (foodType == "fruit"){
						tempFood = new Fruit(foodName, cost);
					}

					addFood(tempFood); //

				}								
			}
		}
	}	

	input.close();
}

/* Prints the store into the results.txt file*/
void Store::printStore(std::ofstream& stream){
	std::stack<Food*> temp;
	Food* fd = NULL;
	std::string food = "";
	
	stream << "\n----------- Store -----------" << std::endl;
	for (unsigned int i = 0; i < m_bins.size(); i++)
	{
		if (!m_bins[i].empty())
		{
			if (m_bins[i].top()->getType() == Food::MEAT){
				food = "Meat";
			}
			else if (m_bins[i].top()->getType() == Food::FRUIT)
			{
				food = "Fruit";
			}
			else if (m_bins[i].top()->getType() == Food::VEGETABLE)
			{
				food = "Vegetable";
			}
			else if (m_bins[i].top()->getType() == Food::STARCH)
			{
				food = "Starch";
			}
			else if (m_bins[i].top()->getType() == Food::SWEET)
			{
				food = "Sweet";
			}			
		}
		else if (m_bins[i].empty()) // if stack is empty prints only name and size
		{
			switch (i)
			{
			case Food::SWEET:
				food = "Sweet"; 
				break;
			case Food::STARCH:
				food = "Starch";
				break;
			case Food::MEAT:
				food = "Meat";
				break;
			case Food::VEGETABLE:
				food = "Vegetable";
				break;
			case Food::FRUIT:
				food = "Fruit";
				break;
			default:
				break;
			}
		}

		stream << food << ": " << m_bins[i].size() << " ";
		
		if (!m_bins[i].empty())
		{
			fd = m_bins[i].top();
			stream << fd->getName();
			temp.push(fd);
			m_bins[i].pop();
		}

			while (!m_bins[i].empty())
			{
				fd = m_bins[i].top();
				stream << ", " << fd->getName();
				temp.push(fd);
				m_bins[i].pop();
			}						
		
		stream << "\n";


		while (!temp.empty())
		{
			m_bins[i].push(temp.top());
			temp.pop();
		}
	}	
}

/* Destructor */
Store::~Store()
{
	for (unsigned int i = 0; i < m_bins.size(); i++)
	{
		while (!m_bins[i].empty())
		{
			food = m_bins[i].top();
			m_bins[i].pop();

			delete food;
		}
	}
}
