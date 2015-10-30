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
#include <fstream>
using namespace std;

// default constructor
Proj3Aux::Proj3Aux()
{

}


// prints command
void Proj3Aux::DoPrintCommand(string command, int depth)
{
	cout << "Print Levels" << endl;
	m_tree.PrintLevels(depth);	
}

// removes element from the BST
// returns 0 if deletion is not successful
int Proj3Aux::DoRemoveCommand(std::string command, int element)
{
	int temp = 0;		
	temp = m_tree.remove(element);
		
		if(temp != 0)
			{
				cout << "REMOVE " << element << ": SUCCESS " << endl;
			}
		else
			{
			cout << "REMOVE " << element << ": FAILED " << endl;			
			
			cerr << "Node Not Found Exception: BST does not contain element "
			 << element << " to remove " << endl; 	
			}
				
	
	return temp;
	//return 0;
}

// Returns the median (middle) element in the BST.  
// If the BST contains an even number of elements, 
// returns the smaller of the two medians.
int Proj3Aux::GetMedianCommand(std::string command)
{
		int result = 0;
		
		result = m_tree.Median();
		
		if(result != -1)
			
			{cout << "MEDIAN: " << result << endl;}
		else
			{
			cout << "MEDIAN: " << result << endl;
			cerr << "NULL Argument Exception: No median value for a tree of zero size." << endl;
			}
			
		return 0;
}


// Returns the n-th element (starting from 1) of 
// the in-order traversal of the BST
int Proj3Aux::GetNthElementCommand(std::string command, int nthElement)
{
	int result = 0;
		
		result = m_tree.NthElement(nthElement);
		
		//cout << "GetNthElementCommand: " << endl;
		
		if(result != -1){
					
			cout << "NTH " <<
		
			nthElement << ": " << result << endl;
		
		}
		else
		{ 	//print to terminal
			cout << "NTH " <<
		
			nthElement << ": " << result << endl;
		
		
			//print to errors.txt
			cerr <<  "Item Not Found Exception: There does not exist an: "
			<<  nthElement 
			<<  "nth element in the BST."
			<<  endl;
		
		}

		return result;		
}

// Returns the “rank” of x. The rank of an element is its position
// (starting with 1) in an in - order traversal..
int Proj3Aux::GetRankCommand(std::string command, int element)
{
	int result = 0;
		
		result = m_tree.Rank(element);
		
		if(result != -1){
			
			cout << "RANK " << element << ": " << result << endl;
			return 0;
			
		}	
		else{
			cout << "RANK " << element << ": " << result << endl;
			cerr << "Node Not Found Exception: BST does not contain element"<< element << endl;
			return 0;
		}
}

// returns resilduals
int Proj3Aux::GetResidualsCommand(std::string command)
{	
	cout << "RESIDUALS\n";
	return 0;
}


// Returns true if BST is complete
// A binary tree in which every level (depth), 
// except possibly the deepest, is completely filled. 
// At depth n, the height of the tree, all nodes must be as far left as possible.
bool Proj3Aux::isComplete(std::string command)
{
	cout << "COMPLETE: " << endl;
	return false;
}

// Returns true if the tree is Perfect
// A binary tree with all leaf nodes at the same depth. 
// All internal nodes have degree 2
bool Proj3Aux::isPerfect(std::string command){
	cout << "isPerfect function\n";
	return false;
}



// reads inputs from the input file
int Proj3Aux::ReadFromInputFile(char* inputFile)
{	
		string line = "";
		
		int number = 0;
		
		 inFile.open(inputFile);					//open file for reading
		 
		 if (inFile.fail())
		{
			cout << "The Input File was not successfully open." << endl;
			//exit(1); // ends ENTIRE program!!!
			return 0;			
		}
		else
		{	
			while(inFile >> number)
			{				
				m_tree.insert(number);				
				//cout  << num << " Has been inserted to BST" << endl;		
			}
			
			inFile.close();						
			
			return 1;		
		}
}


// reads input from command file 
int Proj3Aux::ReadFromCommandFile(char* commandFile)
{
	
	

	streambuf *tempBuff, *backup;
  	ofstream filestr;
  	filestr.open ("errors.txt");
  	
 	backup = std::cerr.rdbuf();     // back up cout's streambuf
  	
  	tempBuff = filestr.rdbuf();        // get file's streambuf
  	std::cerr.rdbuf(tempBuff);         // assign streambuf to cout
  								// close file stream

	
	 string line = "";
	 string command = "";
	 int num = 0;
	 char ch;
	 inFile.open(commandFile);
		 
		 if (inFile.fail())
		{
			cout << "The Command File was not successfully open." << endl;
			//exit(1); // ends ENTIRE program!!!
			return 0;
			
		}
		else{
		
			while (getline(inFile, line, '\n')) //delimeter is new line
			{
				ch = line.at(0);
				
				if(ch!='#'){
					
				num = 0;
				
				istringstream iss (line.c_str());
				
				while(iss >> command ){
				
					iss >> num;
							
					if (command == "NTH"){
						GetNthElementCommand(command, num);
					}
					else if (command == "PRINT"){
						DoPrintCommand(command, num);
					}
					else if (command == "RESIDUALS"){
						GetResidualsCommand(command);
					}
					else if (command == "MEDIAN"){
						GetMedianCommand(command);
					}
					else if (command == "REMOVE"){
						DoRemoveCommand(command, num);
					}
					else if (command == "RANK"){
						GetRankCommand(command, num);
					}
					else if (command == "COMPLETE"){
						isComplete(command);
					}
					else if (command == "PERFECT"){
						isPerfect(command);
					}
					else{
					
						cerr << "Invalid Command Exception: "
						<< command
						<< " is not a valid command"
						<< endl;
					
					}
		
				}
			     }
	
			}
			
			cerr.rdbuf(backup);         // assign streambuf to cout
			
			filestr.close();

			inFile.close();
			
			return 1;
		
		}
}


Proj3Aux::~Proj3Aux()
{

}
