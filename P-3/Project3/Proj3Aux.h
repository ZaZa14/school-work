/*****************************************
** File:    Proj3Aux.h
** Project: CMSC 341 Project 3, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**  C++ file:	
**	This is a header file for Proj3Aux.cpp
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
	void DoPrintCommand(std::string command, int depth);
	int DoRemoveCommand(std::string command, int element);
	int GetMedianCommand(std::string command);
	int GetNthElementCommand(std::string command, int nthElement);
	int GetRankCommand(std::string command, int element);
	int GetResidualsCommand(std::string command);
	bool isComplete(std::string command);
	bool isPerfect(std::string command);
	int ReadFromInputFile(char* inputFile);
	int ReadFromCommandFile(char* commandFile);

	// ------------------------------------------------------

	// ******this is my own method for testing purposes********
	void insertNum(int numer);
	void findMin();




private:

	AugmentedBinarySearchTree<int> m_tree; //it will be tree
	ifstream inFile;					   // input file
	//ofstream outputFile;
};

#endif // !_PROJ3AUX_H
