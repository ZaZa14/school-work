#ifndef _AUGMENTED_BINARY_SEARCH_TREE_CPP
#define _AUGMENTED_BINARY_SEARCH_TREE_CPP

#include "AugmentedBinarySearchTree.h"
//#include "BinarySearchTree.h"

using namespace std;

// default constructor
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



// destructor
template <class Comparable>
AugmentedBinarySearchTree<Comparable>::~AugmentedBinarySearchTree()
{
	//makeclean
}

// removes element from the tree
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::remove(const Comparable & x)
{
	return 0;
}

// returns true if tree is perfect
template <class Comparable>
bool AugmentedBinarySearchTree<Comparable>::IsPerfect()
{
	return false;	// by default it is false
}

// returns true if tree is complete
template <class Comparable>
bool AugmentedBinarySearchTree<Comparable>::IsComplete()
{
	return false; // by default it is false
}

// prints levels of the tree using level order traverse
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::PrintLevels(int numlevels)
{

}

// removes all elements from a tree
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::makeEmpty()
{

}

// removes residue from a tree
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::RemoveResidue()
{
	return 0;
}

// returns n-th element in BST 
template <class Comparable>
const Comparable& AugmentedBinarySearchTree<Comparable>::NthElement(int n)
{
	Comparable temp;
	return temp;
}

// returns the position of the element in BST
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::Rank(const Comparable& x)
{
	return 0;
}

// returns middle element from the BST
template <class Comparable>
const Comparable& AugmentedBinarySearchTree<Comparable>::Median()
{
	Comparable temp;
	return temp;
}

// returns minimum node in BST
template <class Comparable>
BinaryNode<Comparable>* AugmentedBinarySearchTree<Comparable>::
findMin(BinaryNode<Comparable> *t) const
{
	BinaryNode<Comparable>* temp;
	return temp;
}

// inserts element into the BST 
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::
insert(const Comparable & x) // ------------->>>>>>>>> why it returns int
{
	return 1;
}

// inserts element into the BST, starting point is root
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::
insert(const Comparable & x, BinaryNode<Comparable>* & t) const
{
	if (t == NULL){
		t = new BinaryNode<Comparable>(x, NULL, NULL);
		return 1;
	}
	else if (x < t->element){
		insert(x, t->left);
		return 1;
	}
	else if (x > t->element){
		insert(x, t->right);
		return 1;
	}
	else if (x == t->element){  // Duplicate
		return 0;
	}


	
}

// removes an element from a tree
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::
remove(const Comparable & x, BinaryNode<Comparable> * & t) const
{
	return 0;
}

// prints levels of BST using level order traversal
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::
PrintLevels(std::queue <BinaryNode<Comparable> *> q, int levels)
{

}

// Removes residue
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::RemoveResidue(BinaryNode<Comparable> * & t, int *deletions) const
{

}

// returns nth element in a tree
template <class Comparable>
BinaryNode<Comparable>* AugmentedBinarySearchTree<Comparable>::
NthElement(BinaryNode<Comparable> *t, int *nodesVisited, int n) const
{
	BinaryNode<Comparable>*  temp;

	return temp;
}

// Rank of the tree
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::
Rank(const Comparable & x, BinaryNode<Comparable> *t, int *nodesVisited) const
{

}

// returns true if the tree is perfect (complete & balanced & all levels are filled)
template <class Comparable>
bool AugmentedBinarySearchTree<Comparable>::
IsPerfect(std::queue <BinaryNode<Comparable> *> q, int height)
{
	return false;
}

// makes tree empty
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::
makeEmpty(BinaryNode<Comparable>* & t) const
{

}

// 
template <class Comparable>
bool AugmentedBinarySearchTree<Comparable>::
IsComplete(std::queue <BinaryNode<Comparable> *> q, int height)
{
	return false;
}


#endif // !_AUGMENTED_BINARY_SEARCH_TREE_CPP