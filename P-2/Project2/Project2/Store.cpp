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
//using namespace std;


//default constructor
Store::Store() :meatCount(0), sweetCount(0), fruitCount(0), vegCount(0), starchCount(0)
{

}


/* Adds type of food to the specific stack*/
void Store::addFood(Food* food)
{
	switch (food->getType())
	{
	case Food::SWEET:
		sweet.push(food);		
		break;
	case Food::STARCH:
		starch.push(food);
		break;
	case Food::MEAT:
		meat.push(food);
		break;
	case Food::VEGETABLE:
		veggie.push(food);
		break;
	case Food::FRUIT:
		fruit.push(food);
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
		if (!m_bins[0].empty())
		{
			food = m_bins[0].top();			
			m_bins[0].pop();
		}
		else
		{
			food = NULL;
		}		
		break;
	case Food::STARCH:
		if (!m_bins[1].empty())
		{
			food = m_bins[1].top();
			m_bins[1].pop();
		}
		else
		{
			food = NULL;
		}		
		break;
	case Food::MEAT:
		if (!m_bins[2].empty())
		{
			food = m_bins[2].top();
			m_bins[2].pop();
		}
		else
		{
			food = NULL;
		}	
		break;
	case Food::VEGETABLE:
		if (!m_bins[3].empty())
		{
			food = m_bins[3].top();
			m_bins[3].pop();
		}
		else
		{
			food = NULL;
		}
		break;
	case Food::FRUIT:
		if (!m_bins[4].empty())
		{
			food = m_bins[4].top();
			m_bins[4].pop();
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
					//std::cout << "food " << foodName << " "<< foodType << " " <<cost <<  std::endl;
					foodCount++; //total amount of food in the store
					
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
	// adding stack to the vector
	m_bins.push_back(sweet);
	m_bins.push_back(starch);
	m_bins.push_back(meat);
	m_bins.push_back(veggie);
	m_bins.push_back(fruit);
	
	/*std::cout << "\nsize of sweet " << sweet.size() << std::endl;
	std::cout << "size of starch " << starch.size() << std::endl;
	std::cout << "size of meat " << meat.size() << std::endl;
	std::cout << "size of veggie " << veggie.size() << std::endl;
	std::cout << "size of fruit " << fruit.size() << std::endl;
	std::cout << "size of vector " << m_bins.size() << std::endl;*/	

	input.close();
	
	/*Food* f = getFoodByType(Food::SWEET);
	std::cout << "getting food from the getFoodbyType " << *f << std::endl;


	Food* a = getFoodByType(Food::SWEET);
	std::cout << "getting food from the vector " << *a << std::endl;


	Food* b = getFoodByType(Food::SWEET);
	if (b == NULL)
		std::cout << "it is null";
	else
	{
		std::cout << "getting food from the vector " << *b << std::endl;
	}*/


	

	/*std::cout << "\n-----------------------------------------\n" ;
	Food* s;
	s = new Sweet("candy", 25.5);	
	std::cout << *s << std::endl <<"type is " << s->getType();
	sweet.push(s);
	std::cout << "\nsize if the vector " << sweet.size() << std::endl;

	s = new Meat("chicken", 23.6);
	std::cout << *s;
	sweet.push(s);
	std::cout << "\nsize if the vector " << sweet.size() << std::endl;

	s = new Fruit("Banana", 12.5);
	std::cout << *s;
	sweet.push(s);
	std::cout << "\nsize if the vector " << sweet.size() << std::endl;

	s = new Starch("bread", 10.0);
	std::cout << *s;
	sweet.push(s);
	std::cout << "\nsize if the vector " << sweet.size() << std::endl;

	s = new Vegetable("potato", 10.0);
	std::cout << *s;
	sweet.push(s);
	std::cout << "\nsize if the vector " << sweet.size() << std::endl;*/

}

/* Prints the store into the results.txt file*/
void Store::printStore(std::ofstream& stream){
	std::stack<Food*> temp;
	Food* fd = NULL;
	std::string food = "";


	stream << "Zafar Mamarakhimov, Section 05\n";
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
		else if (m_bins[i].empty()) // if stack is empty 
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

	
	stream.close();
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
