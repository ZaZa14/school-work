#ifndef _AUGMENTED_BINARY_SEARCH_TREE_CPP
#define _AUGMENTED_BINARY_SEARCH_TREE_CPP

#include"AugmentedBinarySearchTree.h"
#include"BinarySearchTree.h"

using namespace std;

// default constructor
template <class Comparable>
AugmentedBinarySearchTree<Comparable>::AugmentedBinarySearchTree() : root(NULL)
{

}

// overloaded constructor
template <class Comparable>
AugmentedBinarySearchTree<Comparable>::AugmentedBinarySearchTree(const AugmentedBinarySearchTree<Comparable> & rhs) : root(NULL)
{

}



// destructor
template <class Comparable>
AugmentedBinarySearchTree<Comparable>::~AugmentedBinarySearchTree()
{

}

// removes element from the tree
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::remove(const Comparable & x)
{

}

// returns true if tree is perfect
template <class Comparable>
bool AugmentedBinarySearchTree<Comparable>::IsPerfect()
{
	
}

// returns true if tree is complete
template <class Comparable>
bool AugmentedBinarySearchTree<Comparable>::IsComplete()
{
	
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

}

// returns n-th element in BST 
template <class Comparable>
const Comparable& AugmentedBinarySearchTree<Comparable>::NthElement(int n)
{

}

// returns the position of the element in BST
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::Rank(const Comparable& x)
{

}

// returns middle element from the BST
template <class Comparable>
const Comparable& AugmentedBinarySearchTree<Comparable>::Median()
{

}

// returns minimum node in BST
template <class Comparable>
BinaryNode<Comparable>* AugmentedBinarySearchTree<Comparable>::
findMin(BinaryNode<Comparable> *t) const
{

}

// inserts element into the BST 
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::insert(const Comparable & x) // ------------->>>>>>>>> why it returns int
{

}

// inserts 
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::
insert(const Comparable & x, BinaryNode<Comparable>* & t) const
{

}

// removes an element from a tree
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::
remove(const Comparable & x, BinaryNode<Comparable> * & t) const
{

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

}


#endif // !_AUGMENTED_BINARY_SEARCH_TREE_CPP