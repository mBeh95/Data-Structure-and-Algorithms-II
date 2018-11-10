// ------------------------------graphm.h -------------------------------------
// Prarin Behdarvandian,  CSS 343 C
// Creation Date: Feb 3, 2017
// Date of Last Modification: Feb 14, 2017
// ----------------------------------------------------------------------------
// Purpose - The purpose of the assignment is to create a dijkstras shortest 
//		path with a struct table and have it output all paths.  The header file 
//		contains all the functions, while the cpp file contains actual 
//		implementation codes.
// ----------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions. 
//		Assumption: I assumed that the maximum number of nodes is 100.
//					I assumed you will do the findShortestPath for each
//					insert and remove that has been done.
// ----------------------------------------------------------------------------
#include "nodedata.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "limits.h"
using namespace std;

const int MAXNODES = 101;

class GraphM
{
private:
	struct TableType
	{
		bool visited;          // whether node has been visited
		int dist;              // shortest distance from source known so far
		int path;              // previous node in path of min dist
	};

	NodeData data[MAXNODES];              // data for graph nodes 
	int C[MAXNODES][MAXNODES];            // Cost array, the adjacency matrix
	int size;                             // number of nodes in the graph
	TableType T[MAXNODES][MAXNODES];	// stores visited, distance, path

	int findSmallestEdge(int source);
	void outputPath(int source, int dest);
	void outputTheDirections(int source, int dest);
	void resetTable();
public:
	GraphM();
	~GraphM();
	bool insertEdge(int source, int dest, int weight);
	bool removeEdge(int source, int dest);
	void buildGraph(istream &inputFile);
	void findShortestPath();
	void displayAll();
	void display(int source, int dest);
};

