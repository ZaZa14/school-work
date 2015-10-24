/*****************************************
** File:    Manager.cpp
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:	10/16/2015
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**
**
***********************************************/

#include "Manager.h"
#include <cstdlib>
#include <queue>
#include <string>

using namespace std;

// Default constructor
Manager::Manager()
{
	
}

/* Overloaded constructor Gets filename from the user 
 * and creates orders ann stores */
Manager::Manager(char* store, char* order)
{

	createStore(store);
	createOrders(order);
}


// Creates store from input file
void Manager::createStore(std::string filename)
{
	m_store.stockStore(filename);
	
}


// Creates orders from input file
void Manager::createOrders(std::string filename)
{
	m_orders.loadOrders(filename);
}

// fills orders
void Manager::fillOrders(std::ofstream& stream)
{

	m_orders.setStore(&m_store);	
	
	m_orders.printOrders(stream);

	
	Order* tempOrder = new Order();
	queue <Food::FOOD_TYPE> foodTypes;
	Food::FOOD_TYPE tempFoodType;
	Food* tempFood = new Food();
	string type = "";
	double totalCost = 0;
	
	stream << "------------ Orders ------------\n";

	// printing and calculating
	while ((tempOrder = m_orders.getCurrentOrder()))
	{	
		foodTypes = tempOrder->getTypeQueue();

		if (tempOrder->isAcceptPartial())
		{
			vector<Food*> foodVector;
			vector<Food*> partial;
			
			while (!foodTypes.empty())
			{				
				tempFoodType = foodTypes.front();
				
				foodTypes.pop();

				tempFood = m_store.getFoodByType(tempFoodType);
				if (tempFood == NULL) //if the there is no such food null is returned
				{
					
					tempFood = new Food();
					tempFood->setName("no-name");					
					tempFood->setType(tempFoodType);  
					partial.push_back(tempFood);
					
				}
				else
				{					
					foodVector.push_back(tempFood);
				}
				 
			}
			
			//---------------------------------------------------------------------------------
			// printing out the food
			if (partial.size() != 0)
			{
				stream << tempOrder->getCustomeName() << "  (Partial)" << endl;
				stream << "Unfilled Requests: ";

				for (unsigned int i = 0; i < partial.size(); i++)
				{
					//stream << "getting from partial " << partial[i]->getName() << endl;
					switch (partial[i]->getType())
					{
					case Food::SWEET:
						type = "Sweet";
						break;
					case Food::STARCH:
						type = "Starch";
						break;
					case Food::MEAT:
						type = "Meat";
						break;
					case Food::VEGETABLE:
						type = "Vegetable";
						break;
					case Food::FRUIT:
						type = "Fruit";
						break;
					default:
						type = "Unnkown type";
						break;
					}					

					stream << type <<" ";
				}			
				
				stream << "\nItems:\n";

				
			}
			else
			{
				stream << tempOrder->getCustomeName() << "  " << endl;
				stream << "Items:\n";
			}
			//getting the cost adding them together
			for (unsigned int i = 0; i < foodVector.size(); i++)		
			{
				stream << foodVector[i]->getName() << " $" << foodVector[i]->getCost() << endl;
				totalCost += foodVector[i]->getCost();
			}
			stream << "***Total: $" << totalCost << endl;
			totalCost = 0;
			stream << "-----"<<endl;
		}
		else if (!(tempOrder->isAcceptPartial())) // if customer does not accept partial order
		{
			vector<Food*> foodVector;
			string type = "";
			
			while (!foodTypes.empty())
			{
				
				tempFoodType = foodTypes.front();
				foodTypes.pop();

				tempFood = m_store.getFoodByType(tempFoodType);

				if (tempFood == NULL)
				{
					tempFood = new Food();
					tempFood->setType(tempFoodType);
					//stream << "\ntype " << tempFoodType << " is null\n";
				}					
				else
				{
					//stream << *tempFood << endl;						
				}

				foodVector.push_back(tempFood);
				//stream << "vectore size " << foodVector.size();
				//stream << tempFoodType << endl;
			}

			stream << tempOrder->getCustomeName() << " - Unable to complete order\n";
			stream << "Unfilled Requests: ";
			for (unsigned int i = 0; i < foodVector.size(); i++)
			{
				switch (foodVector[i]->getType())
				{
				case Food::SWEET:
					type = "Sweet";
					break;
				case Food::STARCH:
					type = "Starch";
					break;
				case Food::MEAT:
					type = "Meat";
					break;
				case Food::VEGETABLE:
					type = "Vegetable";
					break;
				case Food::FRUIT:
					type = "Fruit";
					break;
				default:
					type = "Unnkown type";
					break;
				}

				stream << type << " ";

				if (foodVector[i]->getName() != "no-name")
				{
					m_store.addFood(foodVector[i]);
				}
			}

			stream << "\n-----"<< endl;
			
		}
		
	}
	
}

// prints out the status for every transaction
void Manager::printStatus(std::ofstream& stream)
{
	m_store.printStore(stream);
}
