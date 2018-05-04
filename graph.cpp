//
//  graph.cpp
//  Project4
//
//  Created by Bein, Doina on 4/21/18.
//  Copyright © 2018 Bein, Doina. All rights reserved.
//

#include "graph.h"

// TO BE COMPLETED WITH IMPLEMENTATIONS OF GRAPH MEMBER FUNCTIONS
Graph::Graph() // default constructor
{
	number_of_nodes = 0;
	initial_budget = 0;
}

Graph::Graph(int rno, float rbudget) // constructor with two arguments representing the number of nodes, initial budget
{
	number_of_nodes = rno;
	initial_budget = rbudget;

}
void Graph::addEdge(int node1, int node2) // adds an edge between two nodes in the graph node1 and node2
{

}
void Graph::setValue(int node, float rval) // sets a value for a node
{
	
}
void Graph::setBudget(float rbu) // sets the initial budget
{
	initial_budget = rbu;
}
int Graph::getNSize() // return number of nodes
{
	return number_of_nodes;
}
int Graph::getESize() // return number of edges
{
}
float Graph::getBudget() // return current budget
{
}
float Graph::getValue(int node) // returns the value of the node
{
}
void Graph::readData(string fileName)// reads data from a specified file
{
	fstream myfile(fileName);
	int  n, edge1, edge2, value;
	float budget;

	if (myfile.is_open())
	{
		while (myfile)
		{
			myfile >> n;
			myfile >> budget;
			setBudget(budget);
			Graph s(n, budget);
			
			for (int i = 0; i < n; i++)
			{
				myfile >> value;
				setValue(i,value);

			}
			while (myfile >> edge1 >> edge2)
			{
				addEdge(edge1, edge2);
			}
		}
		myfile.close();
	}
} 
int Graph::DFS(int startNode) //return the number of nodes visited using BFS starting at startNode and accumulating values at each node, as long as the budget remains positive
{
}

						// return the starting node that gives a longest DFS run before running out of budget
						// if there are multiple nodes with the same DFS run length, return the smallest node
int Graph::bestStartVertex()
{
}
