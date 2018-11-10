// ------------------------------graphm.cpp ----------------------------------
// Prarin Behdarvandian,  CSS 343 C
// Creation Date: Feb 3, 2017
// Date of Last Modification: Feb 14, 2017
// ----------------------------------------------------------------------------
// Purpose - The purpose of the assignment is to create a dijkstras shortest 
//		path with a struct table and have it output all paths.  The header file 
//		contains all the functions while the cpp file contains actual 
//		implementation codes.
// ----------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions. 
//		Assumption: I assumed that the maximum number of nodes is 100.
//					I assumed you will do the findShortestPath for each
//					insert and remove that has been done.
// ----------------------------------------------------------------------------
#include "graphm.h"

// -----------------------------Constructor------------------------------------
// Description: Creates an empty adjacency table and T table.
// Pre-Conditions: None.
// Post-Conditions: Empty adjacency table and T table is created.
// ----------------------------------------------------------------------------
GraphM::GraphM()
{
	size = 0;
	for (int i = 1; i < MAXNODES; i++)
	{
		for (int j = 1; j < MAXNODES; j++)
		{
			C[i][j] = INT_MAX;
			T[i][j].visited = false;
			T[i][j].path = 0;
			T[i][j].dist = INT_MAX;
		}
	}
}

// -----------------------------destructor------------------------------------
// Description: Deletes objects.
// Pre-Conditions: None.
// Post-Conditions: All objects variables are deleted.
// ----------------------------------------------------------------------------
GraphM::~GraphM()
{
}

// -----------------------------insertEdge------------------------------------
// Description: Insert the weight in C adjacency matrix.
// Pre-Conditions: None.
// Post-Conditions: Weights are added to adjacency matrix, for each insert
//					T table is made for new values.
// ----------------------------------------------------------------------------
bool GraphM::insertEdge(int source, int dest, int weight)
{
	if (source > size || source < 1)
	{
		return false;
	}
	else if (dest > size || dest < 1)
	{
		return false;
	}
	else if (weight <= 0)
	{
		return false;
	}
	else
	{
		resetTable();
		C[source][dest] = weight;
		return true;
	}
}

// -----------------------------removeEdge------------------------------------
// Description: Remove the weight in C adjacency matrix
// Pre-Conditions: None.
// Post-Conditions: Weights are remove to adjacency matrix, for each remove
//					T table is made for new values.
// ----------------------------------------------------------------------------
bool GraphM::removeEdge(int source, int dest)
{
	if (source > size || source < 1)
	{
		return false;
	}
	else if (dest > size || dest < 1)
	{
		return false;
	}
	else if (C[source][dest] == INT_MAX)
	{
		return false;
	}
	else
	{
		resetTable();
		C[source][dest] = INT_MAX;
		return true;
	}
}

// -----------------------------buildGraph------------------------------------
// Description: Builds the C matrix
// Pre-Conditions: None.
// Post-Conditions: C matrix is filled, size is given a number and data is
//					given items
// ----------------------------------------------------------------------------
void GraphM::buildGraph(istream& inputFile)
{
	int source = 0;
	int dest = 0;
	int weight = 0;

	inputFile >> size;
	
	for (int i = 0; i < size+1; i++)
	{
		data[i].setData(inputFile);
	}
	
	while (!inputFile.eof())
	{
		inputFile >> source >> dest >> weight;
		if (source == 0 && dest == 0 && weight == 0)
		{
			break;
		}
		else
		{
			C[source][dest] = weight;
		}
	}
	
}

// -----------------------------findShortestPath-------------------------------
// Description: Creates the shortest path from one node to all other nodes and
//				inputs them in the T table for furthur use.
// Pre-Conditions: C matrix should have weights.
// Post-Conditions: T table is filled with shortest path amounts and paths.
// ----------------------------------------------------------------------------
void GraphM::findShortestPath()
{
	for (int source = 1; source <= size; source++)
	{
		T[source][source].dist = 0;

		for (int i = 1; i <= size; i++)
		{
			int smallestVertex = findSmallestEdge(source);
			T[source][smallestVertex].visited = true;

			if (smallestVertex != 0)
			{
				for (int j = 1; j <= size; j++)
				{
					if (C[smallestVertex][j] != INT_MAX)
					{
						if (T[source][j].visited == false)
						{
							if (T[source][j].dist > T[source][smallestVertex].dist + C[smallestVertex][j])
							{
								T[source][j].dist = min(T[source][j].dist, (T[source][smallestVertex].dist + C[smallestVertex][j]));
								T[source][j].path = smallestVertex;
							}

						}
					}
				}
			}
		}
	}

}

// -----------------------------findSmallestEdge-------------------------------
// Description: Finds the smallest vertex from the source node
// Pre-Conditions: source node should be availiable.
// Post-Conditions: Nothing is changed in the T table, smallest vertex is 
//					returned.
// ----------------------------------------------------------------------------
int GraphM::findSmallestEdge(int source)
{
	int vertex = 0;
	int path = INT_MAX;

	for (int i = 1; i <= size; i++)
	{
		if (T[source][i].dist < path && T[source][i].visited == false)
		{
			path = T[source][i].dist;
			vertex = i;
		}
	}
	return vertex;
}

// -----------------------------outputPath-------------------------------------
// Description: Outputs the number path from source node to the dest node
// Pre-Conditions: source node and dest node should be given.
// Post-Conditions: Nothing is changed in the T table, outputs the path.
// ----------------------------------------------------------------------------
void GraphM::outputPath(int source, int dest)
{
	if (source == dest)
	{
		cout << source << " ";
		return;
	}
	else
	{
		int path = dest;
		outputPath(source, T[source][dest].path);
		cout << path << " ";
	}

}

// -------------------------outputTheDirections--------------------------------
// Description: Outputs the directions path from source node to the dest node
// Pre-Conditions: source node and dest node should be given.
// Post-Conditions: Nothing is changed in the T table, outputs the path 
//					directions.
// ----------------------------------------------------------------------------
void GraphM::outputTheDirections(int source, int dest)
{
	if (source == dest)
	{
		cout << data[source] << endl;
		return;
	}
	else
	{
		int path = dest;
		dest = T[source][dest].path;
		outputTheDirections(source, dest);

		cout << data[path] << endl;
	}
	
}

// ----------------------------------resetTable--------------------------------
// Description: Resets the entire T table and sets everything back to its
//				beginning state
// Pre-Conditions: None.
// Post-Conditions: T table is reset and is emptied.
// ----------------------------------------------------------------------------
void GraphM::resetTable()
{
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			T[i][j].visited = false;
			T[i][j].path = 0;
			T[i][j].dist = INT_MAX;
		}
	}
}

// ----------------------------------displayAll--------------------------------
// Description: Display each node and its paths to all other nodes.
// Pre-Conditions: None.
// Post-Conditions: T table is not changed.
// ----------------------------------------------------------------------------
void GraphM::displayAll()
{
	
	cout << "Description" << setw(20) << "From Node" << setw(10) << "To Node" << setw(12) << "Dijkstra's";
	cout << setw(7) << "Path" << endl;

	for (int i = 1; i < size + 1; i++)
	{
		cout << data[i] << endl;
		for (int j = 1; j < size + 1; j++)
		{
			if (i != j)
			{
				
				if (T[i][j].dist != INT_MAX)
				{
					cout << setw(26) << i << setw(12) << j << setw(10) << T[i][j].dist << setw(9);
					outputPath(i, j); 
					cout << endl;
				}
				else
				{
					cout << setw(26) << i << setw(12) << j << setw(10) << "----" << endl;
				}
			}

		}
	}
	cout << endl;

}

// ----------------------------------display-----------------------------------
// Description: Displays path of source node to the dest node and outputs the
//				weight and the directions.
// Pre-Conditions: None.
// Post-Conditions: T table is not changed.
// ----------------------------------------------------------------------------
void GraphM::display(int source, int dest)
{
	cout << setw(5) << source << setw(8) << dest;
	if (T[source][dest].dist != INT_MAX)
	{
		cout << setw(8) << T[source][dest].dist << setw(8);
		outputPath(source, dest);
		cout << endl;
		outputTheDirections(source, dest);
		

	}
	else
	{
		cout << setw(8) << "----" << endl;
	}
	cout << endl;
}
