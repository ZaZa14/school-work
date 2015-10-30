/*****************************************
** File:    AugmentedBinarySearchTree.cpp
** Project: CMSC 341 Project 3, Fall 2015
** Author:  Zafar Mamarakhimov
** Date:	10/28/2015
** Section: 5
** E-mail:  mzafar2@umbc.edu
**
**  C++ file:
**	This file contains implementation of 
**	augmented of binary search tree. 
**
*******************************************/


#ifndef _AUGMENTED_BINARY_SEARCH_TREE_CPP
#define _AUGMENTED_BINARY_SEARCH_TREE_CPP

#include <queue>
#include "AugmentedBinarySearchTree.h"
#include <string>
#include <cmath>
//#include "BinarySearchTree.h"

using namespace std;

// default constructor makes root NULL
template <class Comparable>
AugmentedBinarySearchTree<Comparable>::
AugmentedBinarySearchTree() : root(NULL)
{

}

// overloaded constructor
template <class Comparable>
AugmentedBinarySearchTree<Comparable>::
AugmentedBinarySearchTree(const AugmentedBinarySearchTree<Comparable> & rhs) : root(NULL)
{

}


// Destructor calls makeEmpty() function
template <class Comparable>
AugmentedBinarySearchTree<Comparable>::~AugmentedBinarySearchTree()
{
	makeEmpty();
}

// removes element from the tree
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>:: 
remove(const Comparable & x)
{	
	  int num =   remove(x, root);	
	  return num;
}

// returns true if tree is perfect
template <class Comparable>
bool AugmentedBinarySearchTree<Comparable>::
IsPerfect()
{
	return false;	// by default it is false
}

// returns true if tree is complete
template <class Comparable>
bool AugmentedBinarySearchTree<Comparable>::
IsComplete()
{
	return false; // by default it is false
}

// prints levels of the tree using level order traverse
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::
PrintLevels(int numlevels)
{
	queue < BinaryNode<Comparable>* > nodeQueue;
	nodeQueue.push(root);
	PrintLevels(nodeQueue, numlevels);
}

// removes all elements from a tree
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::
makeEmpty()
{
	makeEmpty(root);
}

// removes residue from a tree
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::RemoveResidue()
{
	return 0;
}

// returns n-th element in BST 
template <class Comparable>
const Comparable& AugmentedBinarySearchTree<Comparable>::
NthElement(int n)
{		
	int* visited = new int(1);
	BinaryNode<Comparable>* num =  NthElement(root, visited, n);
	
		if (num != NULL)
		{
			return num->element;	
		}

	num = new BinaryNode<Comparable>();
	return num->element;
	
}

// returns the position of the element in BST
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::
Rank(const Comparable& x)
{
	//int initValue = x;
	//int number = 1;
	int initSize = root->m_size;

	if (root != NULL)
	{
		int* rank = new int(1);
		Rank(x, root, rank);

		*rank = root->m_size - initSize;	
		root->m_size = initSize;

		// if the element is not in the tree rank is -1 
		if(0 == *rank)
		{
			*rank = -1; 
		}

		return *rank;
	}else{
		return  0; // if the root no element in the tree return 0
	}
	
	
}
//===============================================================
// returns middle element from the BST
//===============================================================
template <class Comparable>
const Comparable& AugmentedBinarySearchTree<Comparable>::Median()
{
	BinaryNode<Comparable>* temp = new BinaryNode<Comparable>();

	if (root != NULL)
	{
		int medium = 0;

		if((root->m_size % 2) == 0)
		{
			medium = root->m_size / 2;
			//temp = NthElement(medium);
			temp->element = NthElement(medium);

		}else
		{
			medium = (root->m_size+1)/2;
			//temp = NthElement(medium);
			temp->element =  NthElement(medium);
		}
	}

	
	return temp->element;

}

// returns minimum node in BST
template <class Comparable>
BinaryNode<Comparable>* AugmentedBinarySearchTree<Comparable>::
findMin(BinaryNode<Comparable> *t) const
{	

	if (t == NULL)
		return NULL;
	if (t->left == NULL){
		cout << "minimum element is " << t->element << endl;
		return t;
	}
	return findMin(t->left);

}

// inserts element into the BST 
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::
insert(const Comparable & x) // ------------->>>>>>>>> why it returns int
{
	return (insert(x, root));
}

// inserts element into the BST, starting point is root
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::
insert(const Comparable & x, BinaryNode<Comparable>* & t) const
{
	int num ;
	if (t == NULL)
	{
		t = new BinaryNode<Comparable>(x, NULL, NULL, 1);	// if new the node is inserted 
		//cout << "insert " << x <<endl;		
		return 1;
	}
	else if (x == t->element)
	{  // If Duplicate is found don`t insert it
		cout << "Duplicate\n";		
		return 0;
	}	
	else if (x < t->element)
	{
		//cout << "go left" << endl;
		// if there is no duplicate incrementn, insert new element
		// and increment m_size of the parent node of the new element by 1
		if (insert(x, t->left)){
			t->m_size = t->m_size + 1;
			//cout << "weight" << t->m_size <<endl;
			num = 1;			
			
		}
		else
			num = 0; // duplicate is found, don`t insert		
	}
	else if (x > t->element)
	{
		//cout << "go right" << endl;
		// if there is no duplicate incrementn, insert new element
		// and increment m_size of the parent node of the new element by 1
		if(insert(x, t->right)){
			t->m_size = t->m_size + 1;
			//cout << "weight" << t->m_size <<endl;
			num = 1;			
		}
		else
			num = 0; // duplicate is found, don`t insert
	}

	return num;
	
}

//--------------------------------------------------------
// removes an element from a tree
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::
remove(const Comparable & x, BinaryNode<Comparable> * & t) const
{
	int result = 0;
	if (t == NULL)
		return result  = 0;   // if the root is null do nothing
	if (x < t->element){
		if(remove(x, t->left)){
			--t->m_size;			//this is m_size
			result = 1;			
		}
	}
	else if ( x > t->element){
		if (remove(x, t->right)){
			--t->m_size;
			result = 1;			
		}
	}
	else if (t->left != NULL && t->right != NULL) // Two children
	{
		// it it has two children, find the minimum of the right side 
		// and replaced it with root
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
		--t->m_size;
	}
	else
	{	// removing the node
		BinaryNode <Comparable> *oldNode = t;		
		t = (t->left != NULL) ? t->left : t->right;
		delete oldNode;		
		result = 1;		
	}

	return result;
}

// prints levels of BST using level order traversal
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::
PrintLevels(std::queue <BinaryNode<Comparable> *> q, int levels)
{
		
	queue < BinaryNode<Comparable>* > parentQueue, currentLevel, nextLevel;
	int count = 0;
	//BinaryNode<Comparable>* right, left ;

	



	/*while(count<levels){
		
		parentQueue.push(q.front());
		cout <<"Level " << count << ": " ;
		BinaryNode<Comparable>* temp = q.front();

		for(int i = 0; i < pow(2, count); i++)
		{
			while(!q.empty())
			{
				cout << temp -> element << endl;
				q.pop();
			}

			if(temp->left != NULL) //if left is not NULL enqueue the left child
			{
				q.push(temp->left);
			}

			if (temp->right != NULL) //if  right is not NULL enqueue the right child
			{
				q.push(temp->right);
			}

			if (i%6 == 0)
			{
				cout << endl;
			}
			cout << "Node " ;
			
		}

		parentQueue.pop();
		cout << endl;
		
				
		count++;
	}*/


	/*	
	void printLevelOrder(BinaryTree *root) {
	  if (!root) return;
	  queue<BinaryTree*> currentLevel, nextLevel;
	  currentLevel.push(root);
	  while (!currentLevel.empty()) {
	    BinaryTree *currNode = currentLevel.front();
	    currentLevel.pop();
	    if (currNode) {
	      cout << currNode->data << " ";
	      nextLevel.push(currNode->left);
	      nextLevel.push(currNode->right);
	    }
	    if (currentLevel.empty()) {
	      cout << endl;
	      swap(currentLevel, nextLevel);
	    }
	  }
}*/
	while(!q.empty()) //while the queue is not empty
	{
		BinaryNode<Comparable>* temp = q.front();
		cout << "Level: " << count << endl;
		cout << "(" << temp ->element << ", " << temp ->m_size << ")" << endl;
		
		if(temp->left != NULL) //if left is not NULL enqueue the left child
		{
			q.push(temp->left);
		}

		if (temp->right != NULL) //if  right is not NULL enqueue the right child
		{
			q.push(temp->right);
		}



		q.pop();
		//count++;

	}
	
}

// Removes residue
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::
RemoveResidue(BinaryNode<Comparable> * & t, int *deletions) const
{

}

// returns nth element in a tree
template <class Comparable>
BinaryNode<Comparable>* AugmentedBinarySearchTree<Comparable>::
NthElement(BinaryNode<Comparable> *t, int *nodesVisited, int n) const
{	
	if (t->left != NULL) //if left child is NULL don`t return it
	{
         BinaryNode<Comparable>* temp = NthElement(t->left, nodesVisited, n);
        if (temp != NULL)
        {        	
        	return temp;
        }        
    }
    // if it reached the n-th element using in-order traversal
    // return this element. If n-th element is out of range return NULL
    if (*nodesVisited == n) 
    {
    	return t;
    }
    ++(*nodesVisited); // get track of number of nodes that were visited
    
    if (t->right != NULL) // if right child is NULL don`t return it
    {
        BinaryNode<Comparable>* temp = NthElement(t->right, nodesVisited, n);
        if (temp != NULL)
        {
        	return temp;
        }     
    }
     
    return NULL; //return NULL 
}

//=================================================================
// Prints rank of the element in the tree using in-order traversal;
// If the element is not found the element is not printed;
//=================================================================
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::
Rank(const Comparable & x, BinaryNode<Comparable> *t, int *nodesVisited) const
{  

	// x is the element I am looking for
	if (t->left != NULL)
	{	
		Rank(x, t->left, nodesVisited);		
								
	}
	
	if (x == t->element) 
    {    		    
    	
    	//cout << "found the node " << endl;
    	root->m_size = root->m_size + (*nodesVisited);
    	return ; // exiting the recursion returns the rank
    }

    ++(*nodesVisited); // incrementing the count

    if (t->right != NULL)
    {    	
        Rank(x, t->right, nodesVisited);   	
    }
    
}

// returns true if the tree is perfect (complete & balanced & all levels are filled)
template <class Comparable>
bool AugmentedBinarySearchTree<Comparable>::
IsPerfect(std::queue <BinaryNode<Comparable> *> q, int height)
{
	return false;
}

// Deletes all nodes in the tree
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::
makeEmpty(BinaryNode<Comparable>* & t) const
{
	if(t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;
}

// 
template <class Comparable>
bool AugmentedBinarySearchTree<Comparable>::
IsComplete(std::queue <BinaryNode<Comparable> *> q, int height)
{
	return false;
}



#endif // !_AUGMENTED_BINARY_SEARCH_TREE_CPP