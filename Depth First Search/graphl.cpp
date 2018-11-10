// ------------------------------graphl.cpp ----------------------------------
// Prarin Behdarvandian,  CSS 343 C
// Creation Date: Feb 3, 2017
// Date of Last Modification: Feb 14, 2017
// ----------------------------------------------------------------------------
// Purpose - The purpose of the assignment is to create a depth first search
//			for a given array of linked lists. The header file contains
//			all the codes while the cpp file contains actual implementation
// ----------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions. 
//		Assumption: I assumed that the maximum number of nodes is 100.
// ----------------------------------------------------------------------------
#include "graphl.h"

// -----------------------------Constructor------------------------------------
// Description: Creates an empty array of linked lists.
// Pre-Conditions: None.
// Post-Conditions: Empty array of linked lists is created and size is 0.
// ----------------------------------------------------------------------------
GraphL::GraphL()
{
	size = 0;
	for (int i = 0; i < MAXNODE; i++)
	{
		depthFirstArray[i].data = NULL;
		depthFirstArray[i].edgeHead = NULL;
		depthFirstArray[i].visited = false;
	}
}

// -----------------------------Destructor------------------------------------
// Description: Call on makeEmpty to delete everything in the linked list array
// Pre-Conditions: None.
// Post-Conditions: Array of linked lists is emptied and size is set to 0.
// ----------------------------------------------------------------------------
GraphL::~GraphL()
{
	makeEmpty();
}

// -----------------------------buildGraph------------------------------------
// Description: Builds the array linked list and adds in edges
// Pre-Conditions: None.
// Post-Conditions: The array linked list is filled with data, size is given 
//					a number and data is given items
// ----------------------------------------------------------------------------
void GraphL::buildGraph(istream & inputFile)
{
	int source;
	int dest;
	string s;
	inputFile >> size;

	for (int i = 0; i < size + 1; i++)
	{
		getline(inputFile, s);
		NodeData* ptr = new NodeData(s);
		depthFirstArray[i].data = ptr;
	}
	while (!inputFile.eof())
	{
		inputFile >> source >> dest;
		if (source == 0 && dest == 0)
		{
			break;
		}
		else
		{
			if (depthFirstArray[source].edgeHead == NULL)
			{
				depthFirstArray[source].edgeHead = new EdgeNode;
				depthFirstArray[source].edgeHead->nextEdge = NULL;
				depthFirstArray[source].edgeHead->adjGraphNode = dest;
			}
			else
			{
				EdgeNode* newHead = new EdgeNode;
				newHead->nextEdge = depthFirstArray[source].edgeHead;
				newHead->adjGraphNode = dest;
				depthFirstArray[source].edgeHead = newHead;
			}
		}
	}
}

// ----------------------------------displayGraph------------------------------
// Description: Displays each node and each of its edges in order.
// Pre-Conditions: None.
// Post-Conditions: Array of linked list is not changed.
// ----------------------------------------------------------------------------
void GraphL::displayGraph()
{
	cout << "Graph:" << endl;
	for (int i = 1; i <= size; i++)
	{
		cout << "Node" << i << "\t\t" << *depthFirstArray[i].data << endl;
		EdgeNode* root = depthFirstArray[i].edgeHead;
		while (root != NULL)
		{
			cout << setw(6) << "edge" << setw(5) << i << setw(5);
			cout << root->adjGraphNode;
			cout << endl;
			root = root->nextEdge;
		}
	}
	cout << endl;

}

// ------------------------------depthFirstSearch------------------------------
// Description: Calls on its recursive counterpart to find the depth first 
//				order of the array of linked lists. For loop help if the 
//				beginning nodes are empty.
// Pre-Conditions: None.
// Post-Conditions: Array of linked list is not changed.
// ----------------------------------------------------------------------------
void GraphL::depthFirstSearch()
{
	cout << "Depth-First Ordering: ";
	for (int i = 1; i <= size; i++)
	{
		recursionDepthFirstSearch(i);
	}
	cout << endl;
	cout << endl;
}

// ---------------------recursionDepthFirstSearch------------------------------
// Description: Finds the depth first order of the array of linked lists. 
//				Each graph is marked visited as the function finds each 
//				unvisited
// Pre-Conditions: None.
// Post-Conditions: Array of linked list is not changed. Outputs the order as 
//					it goes through the array if linked lists.
// ----------------------------------------------------------------------------
void GraphL::recursionDepthFirstSearch(int source)
{

	if (depthFirstArray[source].visited == true)
	{
		return;
	}
	else
	{
		depthFirstArray[source].visited = true;
		cout << source << " ";
		EdgeNode* root;
		root = depthFirstArray[source].edgeHead;
		while (root != NULL)
		{
			recursionDepthFirstSearch(root->adjGraphNode);
			root = root->nextEdge;
		}
	}
}

// -----------------------------makeEmpty--------------------------------------
// Description: Calls on its recursive counterpart to make the array of linked 
//				lists empty of edges, while it deletes the NodeData.
// Pre-Conditions: None.
// Post-Conditions: The array of linked lists becomes empty.
// ----------------------------------------------------------------------------
void GraphL::makeEmpty()
{
	for (int i = 0; i <= size; i++)
	{
		depthFirstArray[i].visited = false;
		delete depthFirstArray[i].data;
		depthFirstArray[i].data = NULL;
		while (depthFirstArray[i].edgeHead != NULL)
		{
			makeItEmpty(depthFirstArray[i].edgeHead);
		}

	}
	size = 0;
}

// -----------------------------makeItEmpty------------------------------------
// Description: In while loop goes to the last edge and starts deleting each 
//				edge until it deletes the actual root
// Pre-Conditions: None.
// Post-Conditions: Edges are deleted one by one
// ----------------------------------------------------------------------------
void GraphL::makeItEmpty(EdgeNode *& root)
{
	while (root != NULL)
	{
		makeItEmpty(root->nextEdge);
		root->adjGraphNode = 0;
		delete root;
		root = NULL;
	}
}

