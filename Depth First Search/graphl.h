// ------------------------------graphl.h--------------------------------------
// Prarin Behdarvandian,  CSS 343 C
// Creation Date: Feb 3, 2017
// Date of Last Modification: Feb 14, 2017
// ----------------------------------------------------------------------------
// Purpose - The purpose of the assignment is to create a depth first search
//			for a given array of linked lists. The header file contains
//			all the codes while the cpp file contains actual implementation
// ----------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions. 
//		Assumption: I assumed that the maximum number of nodes is 100
// ----------------------------------------------------------------------------
#include "nodedata.h"
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "limits.h"
using namespace std;

const int MAXNODE = 101;

class GraphL
{
private:

	struct EdgeNode;      // forward reference for the compiler
	struct GraphNode
	{    // structs used for simplicity, use classes if desired
		EdgeNode* edgeHead = NULL; // head of the list of edges
		NodeData* data = NULL;     // data information about each node
		bool visited;
	};

	struct EdgeNode 
	{
		int adjGraphNode;  // subscript of the adjacent graph node
		EdgeNode* nextEdge = NULL;
	};
	GraphNode depthFirstArray[MAXNODE];
	void recursionDepthFirstSearch(int source);
	void makeEmpty();
	void makeItEmpty(EdgeNode* &root);
	int size;
	

public:
	GraphL();
	~GraphL();
	void buildGraph(istream &inputFile);
	void displayGraph();
	void depthFirstSearch();
	
};

