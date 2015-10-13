/*****************************************
** File:    Orders.cpp
** Project: CMSC 341 Project 2, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**
**
***********************************************/

#include "Orders.h"
#include <cstdlib>
#include <sstream>
#include <vector>
using namespace  std;

// default constructor
Orders::Orders()
{

}

void Orders::loadOrders(string filename)
{
	

	input.open(filename.c_str());
	if (input.fail()){
		cout << "\nCannot find input file!\n";
		exit(1);
	}
	else
	{
		vector<string> foodType;
		string accepts = "";
		string line = "";
		string skip = "";
		string name = "";
		string f = "";
		while (getline(input, line, '\n')) //delimeter is new line
		{
			if (line != ""){

				stringstream stream(line);

				while ( getline(getline(stream, skip, '"'), name, '"') >> accepts)
				{
					cout << "\nname " <<name << " accepts " << accepts << endl;
				}
			}
		}
	}

}


Orders::~Orders()
{
}
