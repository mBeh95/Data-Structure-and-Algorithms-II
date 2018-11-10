// ------------------------------bintree.cpp ----------------------------------
// Prarin Behdarvandian,  CSS 343 C
// Creation Date: Jan 20, 2017
// Date of Last Modification: Jan 29, 2017
// ----------------------------------------------------------------------------
// Purpose - The purpose of the assignment is to create a Binary search tree
//			 and be able to fill it with data, make it empty, compare it to 
//			other trees and input the data to an array and then back to a tree 
//			again. The cpp file contains all the code for the funcions defined 
//			in the h file.
// ----------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions. 
//		Assumption: I assumed that the array given will be filled for the 
//					arrayToBSTree function.
// ----------------------------------------------------------------------------
#include "bintree.h"

// -----------------------------Constructor------------------------------------
// Description: Creates an Empty tree with a root of NULL
// Pre-Conditions: None.
// Post-Conditions: Empty tree is created
// ----------------------------------------------------------------------------
BinTree::BinTree()
{
	root = NULL;
}

// -------------------------CopyConstructor------------------------------------
// Description: Creates a copy of the source tree given.
// Pre-Conditions: Must have a source tree to copy from.
// Post-Conditions: The current tree becomes a copy of the source tree.
// ----------------------------------------------------------------------------
BinTree::BinTree(const BinTree & source)
{
	root = NULL;
	*this = source;
}

// -----------------------------Destructor------------------------------------
// Description: Calls on makeEmpty function to release all the heap memory.
// Pre-Conditions: None.
// Post-Conditions: Emptys the tree and returns the heap memory.
// ----------------------------------------------------------------------------
BinTree::~BinTree()
{
	makeEmpty();
	
}

// --------------------------------isEmpty-------------------------------------
// Description: Checks to see if the tree is empty by looking at the root.
// Pre-Conditions: None.
// Post-Conditions: Tree is not changed, return true or false depending on if 
//					if the tree is empty.
// ----------------------------------------------------------------------------
bool BinTree::isEmpty() const
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// -----------------------------makeEmpty--------------------------------------
// Description: Calls on its recursive counterpart to make the tree empty.
// Pre-Conditions: None.
// Post-Conditions: The tree becomes empty.
// ----------------------------------------------------------------------------
void BinTree::makeEmpty()
{
	makeItEmpty(root);
}

// -----------------------------makeItEmpty------------------------------------
// Description: In a post order transversal goes through the tree and deletes
//				the NodeData and Node.
// Pre-Conditions: None.
// Post-Conditions: Tree is delete node by node.
// ----------------------------------------------------------------------------
void BinTree::makeItEmpty(Node*& root)
{
	if (root != NULL)
	{
		makeItEmpty(root->left);
		makeItEmpty(root->right);

		delete root->data;
		root->data = NULL;

		delete root;
		root = NULL;
	}
	
}

// -----------------------------=operator--------------------------------------
// Description: Sets one tree equal to another. Will empty the tree if needed.
// Pre-Conditions: Must have a rhs avaliable, can be empty.
// Post-Conditions: The tree becomes equal to the rhs tree.
// ----------------------------------------------------------------------------
BinTree & BinTree::operator=(const BinTree &rhs)
{
	if (*this == rhs)
	{
		return *this;
	}
	makeEmpty();
	recursiveAssignmentOp(rhs.root);
	return *this;
}

// --------------------------recursiveAssignmentOp-----------------------------
// Description: In pre-order transversal inserts from the rhs tree to the 
//				current tree
// Pre-Conditions: Rhs tree needs to exist.
// Post-Conditions: The current tree becomes a copy of the rhs tree.
// ----------------------------------------------------------------------------
void BinTree::recursiveAssignmentOp(Node * rhs)
{
	if (rhs != NULL)
	{
		NodeData* ptr = new NodeData(*rhs->data);
		insert(ptr);
		recursiveAssignmentOp(rhs->left);
		recursiveAssignmentOp(rhs->right);
	}
}

// -----------------------------==operator--------------------------------------
// Description: Check to see if both tree are NULL, Then call on its recursive 
//				counterpart to do the rest of the checking
// Pre-Conditions: Must have a rhs avaliable in order to check both trees.
// Post-Conditions: Both trees are not changed, will return the result of
//					if they are equal to each other.
// ----------------------------------------------------------------------------
bool BinTree::operator==(const BinTree &rhs) const
{
	if (root == NULL && rhs.root == NULL)
	{
		return true;
	}
	return equalityRecursionOp(root, rhs.root);
}

// -------------------------equalityRecursionOp--------------------------------
// Description: Recursively checks through both trees to see if they are equal
//				to each other. Should one Node be different, it will return 
//				false as a result.
// Pre-Conditions: Must have a rhs avaliable, can be empty.
// Post-Conditions: No changes are to either tree. Will return the result of
//					if they are equal to each other.
// ----------------------------------------------------------------------------
bool BinTree::equalityRecursionOp(Node * root, Node * rhs) const
{
	if (root == NULL && rhs == NULL)
	{
		return true;
	}
	else if (root == NULL || rhs == NULL)
	{
		return false;
	}
	else if (*root->data != *rhs->data)
	{
		return false;
	}
	else
	{
		bool checkLeft = equalityRecursionOp(root->left, rhs->left);
		bool checkRight = equalityRecursionOp(root->right, rhs->right);
		if (checkLeft == false || checkRight == false)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	
}

// -----------------------------!=operator--------------------------------------
// Description: Uses the ==Operator and reverse the process in order to get
//				the correct result for itself.
// Pre-Conditions: Must have a rhs avaliable in order to check both trees.
// Post-Conditions: Both trees are not changed, will return the result of
//					if they are inequal to each other.
// ----------------------------------------------------------------------------
bool BinTree::operator!=(const BinTree &rhs) const
{
	return !(*this == rhs);
}

// -----------------------------insert-----------------------------------------
// Description: Calls on its recursive counterpart to insert data into a node
//				of the tree.
// Pre-Conditions: The data must be a NodeData type
// Post-Conditions: The tree will have the data in one of its Nodes
// ----------------------------------------------------------------------------
bool BinTree::insert(NodeData *target)
{
	return recursiveInsert(target, root);
	
}

// -----------------------------recursiveInsert--------------------------------
// Description: Recursively inserts data into a node of the tree.
// Pre-Conditions: The data must be a NodeData type
// Post-Conditions: The tree will have the data inserted in one of its nodes
// ----------------------------------------------------------------------------
bool BinTree::recursiveInsert(NodeData  *target, Node *& root)
{
	if (root == NULL)
	{
		root = new Node;
		root->data = target;
		root->left = root->right = NULL;
		return true;
	}
	else if (*target < *root->data)
	{
		if (root->left == NULL)
		{
			root->left = new Node;
			root->left->data = target;
			return true;
		}
		else
		{
			return recursiveInsert(target, root->left);
		}
	}
	else if (*target > *root->data)
	{
		if (root->right == NULL)
		{
			root->right = new Node;
			root->right->data = target;
			return true;
		}
		else
		{
			return recursiveInsert(target, root->right);
		}
	}
	else
	{
		return false;
	}

}

// -----------------------------retrieve---------------------------------------
// Description: Calls on its recursive counterpart Find to search through the 
//				tree to see if the target data is contained in the tree. If so
//				the second parameter will be set to equal the found data.
// Pre-Conditions: The target data must be a NodeData type
// Post-Conditions: The tree will not be changed. The second paramete will 
//					be set to equal the target data if found.
// ----------------------------------------------------------------------------
bool BinTree::retrieve(const NodeData & target, NodeData *& found) const
{
	return recursiveFind(target, found, root);
}

// -----------------------------recursiveFind----------------------------------
// Description: Recursively searches through the tree to see if the target 
//							data is contained in the tree. If so, the second 
//							parameter will be set to equal the found data.
// Pre-Conditions: None. Please see retrieve function pre-Conditions.
// Post-Conditions: The tree will not be changed. Found will 
//					be set to equal the target data if found.
// ----------------------------------------------------------------------------
bool BinTree::recursiveFind(const NodeData & target, NodeData *& found, Node* root) const
{
	if (root == NULL)
	{
		return false;
	}
	else if (*root->data == target)
	{
		found = root->data;
		return true;
	}
	else if (target < *root->data)
	{
		recursiveFind(target, found, root->left);
	}
	else
	{
		recursiveFind(target, found, root->right);
	}
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const 
{
	sideways(root, 0);
}

// -----------------------------getHeight--------------------------------------
// Description: Checks if the root is and will return zero for an empty tree.
//				Otherwise will call on the findTargetNode in order to first 
//				find the target node and then calls on the getHeightNumber 
//				to return the actual height of the node.
// Pre-Conditions: None.
// Post-Conditions: The tree will not change. Return the height of the Node.
// ----------------------------------------------------------------------------
int BinTree::getHeight(const NodeData & target) const
{
	if (root == NULL)
	{
		return 0;
	}
	
	else
	{
		Node* foundNode = NULL;
		findTargetNode(target, root, foundNode);
		return getHeightNumber(foundNode);
	}
}

// -----------------------------findTargetNode---------------------------------
// Description: In a post-order transversal, look through the tree to find the
//				target node. Once found, it will be set to the foundNode.
// Pre-Conditions: None.
// Post-Conditions: The tree will not change.
// ----------------------------------------------------------------------------
void BinTree::findTargetNode(const NodeData& target, Node * root, Node* &foundNode) const
{
	if (root != NULL)
	{
		if (*root->data == target)
		{
			foundNode = root;
		}
		findTargetNode(target, root->left, foundNode);
		findTargetNode(target, root->right, foundNode);
		
	}
}

// -----------------------------getHeightNumber---------------------------------
// Description: Goes recursively through from the Node to its last 
//				child/children from the left and right. Once the root is Null,
//				it will return the base case of zero, then go up the the tree
//				while returning the maximum number between the left and right 
//				children and adding 1 for each recursion.
// Pre-Conditions: None.
// Post-Conditions: The tree will not change. Return the height of the selected
//					Node.
// ----------------------------------------------------------------------------
int BinTree::getHeightNumber(Node * root) const
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + max(getHeightNumber(root->left), getHeightNumber(root->right));
	}
}

// -----------------------------bstreeToArray---------------------------------
// Description: Intializes an index of zero for the array and then calls on
//				its recursive counterpart to fill the array. The last step
//				of this function is to call the makeEmpty function to empty
//				out the array.
// Pre-Conditions: Array need to be avaliable.
// Post-Conditions: The tree will be empty and the array will be filled inorder
// ----------------------------------------------------------------------------
void BinTree::bstreeToArray(NodeData * bstreeArray[])
{
	int index = 0;
	bstreeToArrayRecursion(bstreeArray, index, root);
	makeEmpty();
}

// --------------------------bstreeToArrayRecursion----------------------------
// Description: In an in-order transversal recursion it will fill out the array
//				with the data from the tree. For each insertion, the index will
//				increase in order for all of the data to be put in.
// Pre-Conditions: None. See the bstreeToArray pre-conditions.
// Post-Conditions: The array will be filled in-order.
// ----------------------------------------------------------------------------
void BinTree::bstreeToArrayRecursion(NodeData * bstreeArray[], int& index, Node* root)
{
	if (root != NULL)
	{
		bstreeToArrayRecursion(bstreeArray, index, root->left);
		NodeData* temp = new NodeData(*root->data);
		bstreeArray[index] = temp;
		index++;
		bstreeToArrayRecursion(bstreeArray, index, root->right);
	}

}

// -----------------------------arrayToBSTree---------------------------------
// Description: Intializes a size of zero and uses the while loop to find the 
//				exact size of the array. It will then call its recursive 
//				counterpart to fill in the tree.
// Pre-Conditions: The array will need to be initialized.
// Post-Conditions: The tree will be filled and the array will be empty.
// ----------------------------------------------------------------------------
void BinTree::arrayToBSTree(NodeData * bstreeArray[])
{
		
	int size = 0;
	while (bstreeArray[size] != NULL)
	{
		size++;
	}
	arrayToBSTreeRecursion(bstreeArray, 0, size-1);
}

// --------------------------arrayToBSTreeRecursion----------------------------
// Description: Will go in a pre-order transversal through the array and input
//				middle index of each section, to insure the tree will be filled
//				will the data from the array. Will use the insert function to
//				insert data properly in the right order.
// Pre-Conditions: The array will need to be filled and the tree needs to be 
//				empty.
// Post-Conditions: The tree will be filled and the array will be empty.
// ----------------------------------------------------------------------------
void BinTree::arrayToBSTreeRecursion(NodeData * bstreeArray[], int lowIndex, int highIndex)
{
	if (lowIndex <= highIndex)
	{
		int midIndex = (lowIndex + highIndex) / 2;
		NodeData* temp = bstreeArray[midIndex];
		insert(temp);
		bstreeArray[midIndex] = NULL;
		arrayToBSTreeRecursion(bstreeArray, lowIndex, midIndex - 1);
		arrayToBSTreeRecursion(bstreeArray, midIndex + 1, highIndex);
	}

}

// -----------------------------outputOperator---------------------------------
// Description: Outputs the data in the tree in an in-orderTransversal using 
//				and send the information to the ostream operator
// Pre-Conditions: None.
// Post-Conditions: The tree does not change. Sends the output of the tree to 
//					the ostream operator to output to the window.
// ----------------------------------------------------------------------------
void BinTree::inorderHelper(ostream & outStream, Node* root) const
{
	if (root != NULL)
	{
		inorderHelper(outStream, root->left);
		outStream << *(root)->data << " ";
		inorderHelper(outStream, root->right);
	}
	
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const 
{
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}

// -----------------------------outputOperator---------------------------------
// Description: Outputs the data in the tree in an in-orderTransversal using 
//				the inorderHelper function
// Pre-Conditions: Must have a rhs avaliable, can be empty.
// Post-Conditions: The tree does not change.
// ----------------------------------------------------------------------------
ostream & operator<<(ostream & outStream, const BinTree & rhs)
{
	if (rhs.root != NULL)
	{
		rhs.inorderHelper(outStream, rhs.root);
		outStream << endl;
	}
	return outStream;
}
