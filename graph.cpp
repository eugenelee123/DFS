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
	budget = 0;
}

Graph::Graph(int rno, float rbudget) // constructor with two arguments representing the number of nodes, initial budget
{
	number_of_nodes = rno;
	budget = rbudget;
    
   //Sets adjacency matrix values equal to false
    for(int i=0;i< number_of_nodes; i++){
        for(int j=0;j< number_of_nodes; j++)
        adjMat[i][j]=0;
        }
    
    }

void Graph::addEdge(int node1, int node2) // adds an edge between two nodes in the graph node1 and node2
{
    adjMat[node1][node2]=1;
    adjMat[node2][node1]=1;
    counter++;
}
void Graph::setValue(int node, float rval) // sets a value for
{
    //Not an issue with pair, its an issue with the vector
    graph.insert(graph.begin()+node,make_pair(false,rval));
}
void Graph::setBudget(float rbu) // sets the initial budget
{
	budget = rbu;
}
int Graph::getNSize() // return number of nodes
{
	if (graph.size() == 0)
		return number_of_nodes;
	else 	
		return graph.size();
}
int Graph::getESize() // return number of edges
{
    return counter;
}
float Graph::getBudget() // return current budget
{
    return budget;
}
float Graph::getValue(int node) // returns the value of the node
{
    return graph[node].second;
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
int Graph::DFS(int startNode) //return the number of nodes visited using DFS starting at startNode and accumulating values at each node, as long as the budget remains positive
{
    list<int> visited;
    int num_visited=0;
    float Tempbudget= getBudget();
    for(int i=0;i< graph.size();i++){
        //Pushes value of adjecent vertex onto visited stack
        if ((adjMat[startNode][i]==1) && (graph[i].first==false)){
            //Iterate through visited stack to see if node has already been visited, if it hasn't push it on
            visited.push_back(i);
            graph[i].first=true;
            break;
            }
            //Subtracts the budget by node's float value
            Tempbudget = Tempbudget+graph[i].second;
            }
    //maybe loop until stack is empty
    while( (Tempbudget>=0) || (visited.size()==getNSize())){
         num_visited++;
         DFS(visited.front());
        
    }
    return num_visited;
}

// return the starting node that gives a longest DFS run before running out of budget
// if there are multiple nodes with the same DFS run length, return the smallest node
int Graph::bestStartVertex()
{
    int max = 0;
    for(int i=0;i<getNSize();i++){
        if(DFS(i)>max){
            max=DFS(i);
        }
    }
    return max;
}
