// ------------------------------bintree.h ----------------------------------
// Prarin Behdarvandian,  CSS 343 C
// Creation Date: Jan 20, 2017
// Date of Last Modification: Jan 29, 2017
// ----------------------------------------------------------------------------
// Purpose - The purpose of the assignment is to create a Binary search tree
//			 and be able to fill it with data, make it empty, compare it to 
//			other trees and input the data to an array and then back to a tree 
//			again. The header file conains all the defined functions that will
//			need to be implemented.
// ----------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions. 
//		Assumption: I assumed that the array given will be filled for the 
//					arrayToBSTree function.
// ----------------------------------------------------------------------------
#include "nodedata.h"
#include <iostream>
#include <algorithm>

class BinTree
{
	friend ostream& operator<<(ostream &outStream, const BinTree &rhs);

private:
	struct Node
	{
		NodeData* data = NULL;						// pointer to data object
		Node* left = NULL;							// left subtree pointer
		Node* right = NULL;						// right subtree pointer
	};
	Node* root = NULL;

	void inorderHelper(ostream & outStream, Node* root) const;
	void sideways(Node* current, int level) const;
	bool recursiveInsert(NodeData* target, Node* &root);
	void makeItEmpty(Node* &root);
	bool recursiveFind(const NodeData& target, NodeData *& found, Node* root) const;
	void recursiveAssignmentOp(Node* rhs);
	void bstreeToArrayRecursion(NodeData * bstreeArray[], int& index, Node* root);
	void arrayToBSTreeRecursion(NodeData * bstreeArray[], int lowIndex, int highIndex);
	void findTargetNode(const NodeData& target, Node *root, Node* &foundNode) const;
	int getHeightNumber(Node* root) const;
	bool equalityRecursionOp(Node* root, Node* rhs) const;

public:
	
	BinTree();								// constructor
	BinTree(const BinTree & source);				// copy constructor
	~BinTree();								// destructor, calls makeEmpty	
	bool isEmpty() const;					// true if tree is empty, otherwise false
	void makeEmpty();						// make the tree empty so isEmpty returns true
	BinTree& operator=(const BinTree & rhs);
	bool operator==(const BinTree &rhs) const;
	bool operator!=(const BinTree &rhs) const;
	bool insert(NodeData* target);
	bool retrieve(const NodeData& target, NodeData* & found) const;
	void displaySideways() const;			// provided below, displays the tree sideways

	int getHeight(const NodeData& target) const;
	void bstreeToArray(NodeData * bstreeArray[]);
	void arrayToBSTree(NodeData * bstreeArray[]);

};

