/*****************************************
** File:    Proj3Aux.h
** Project: CMSC 341 Project 3, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**  C++ file:
**	Breif Description of the file
**
**
**
*******************************************/

#ifndef _PROJ3AUX_H
#define _PROJ3AUX_H
#include <iostream>
#include <string>
#include <fstream>

#include "BinarySearchTree.h"
#include "AugmentedBinarySearchTree.h"
class Proj3Aux
{
public:
	Proj3Aux();
	~Proj3Aux();

	void ReadFromInputFile(std::string input);

private:

	AugmentedBinarySearchTree<int> tree; //it will be tree
	ifstream inpuFile;
	ofstream outputFile;
};




#endif // !_PROJ3AUX_H
