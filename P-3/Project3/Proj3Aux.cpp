/*****************************************
** File:    Proj3Aux.cpp
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

#include "Proj3Aux.h"
using namespace std;

// default constructor
Proj3Aux::Proj3Aux()
{

}


// prints command
void Proj3Aux::DoPrintCommand(std::string command, int depth)
{

}

// removes element from the BST
// returns 0 if deletion is not successful
int Proj3Aux::DoRemoveCommand(std::string command, int element)
{
	return 0;
}

// Returns the median (middle) element in the BST.  
// If the BST contains an even number of elements, 
// returns the smaller of the two medians.
int Proj3Aux::GetMedianCommand(std::string command)
{
	return 0;
}


// Returns the n-th element (starting from 1) of 
// the in-order traversal of the BST
int Proj3Aux::GetNthElementCommand(std::string command, int nthElement)
{
	return 0;
}

// Returns the “rank” of x. The rank of an element is its position
// (starting with 1) in an in - order traversal..
int Proj3Aux::GetRankCommand(std::string command, int element)
{
	return 0;
}

// returns resilduals
int Proj3Aux::GetResidualsCommand(std::string command)
{
	return 0;
}


// Returns true if BST is complete
// A binary tree in which every level (depth), 
// except possibly the deepest, is completely filled. 
// At depth n, the height of the tree, all nodes must be as far left as possible.
bool Proj3Aux::isComplete(std::string command)
{
	return false;
}

// Returns true if the tree is Perfect
// A binary tree with all leaf nodes at the same depth. 
// All internal nodes have degree 2
bool Proj3Aux::isPerfect(std::string command){
	return false;
}



// reads inputs from the input file
int Proj3Aux::ReadFromInputFile(char* input)
{
	
	return 1;
}



// reads input from command file 
int Proj3Aux::ReadFromCommandFile(char* commandFile)
{
	return 1;
}


Proj3Aux::~Proj3Aux()
{

}


// ***************************************************************************************

// ---------------For testting purposes------------------------------------------------
void Proj3Aux::insertNum(int numer){

	if (m_tree.insert(numer))
	{
		cout << "inserted " << numer << endl;		
	}
	else
	{
		cout << "Not inserted " << numer << endl;
	}
}

/*void Proj3Aux::findMin()
{
	BinaryNode<int>* temp = m_tree.findMin();

	cout << "\n min " <<temp->element;
}*/


