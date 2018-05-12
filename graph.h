//
//  graph.h
//  Project4
//
//  Created by Bein, Doina on 4/21/18.
//  Copyright © 2018 Bein, Doina. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>


using namespace std;

class Graph {
public:
	Graph(); // default constructor
	Graph(int rno, float rbudget); // constructor with two arguments representing the number of nodes, initial budget
	void addEdge(int node1, int node2); // adds an edge between two nodes in the graph node1 and node2
	void setValue(int node, float rval); // sets a value for a node
	void setBudget(float rbu); // sets the initial budget
	int getNSize(); // return number of nodes
	int getESize(); // return number of edges
	float getBudget(); // return current budget
	float getValue(int node); // returns the value of the node
	void readData(string fileName); // reads data from a specified file
	int DFS(int startNode); //return the number of nodes visited using BFS starting at startNode and accumulating values at each node, as long as the budget remains positive

    // return the starting node that gives a longest DFS run before running out of budget
    // if there are multiple nodes with the same DFS run length, return the smallest node
	int bestStartVertex();

private:
	// member variables and helper functions (if needed)
	int number_of_nodes=0;
    float budget=0;
  
    //counts number of edges
    int counter =0;
    //Initializes adjacency matrix to maximum possible size
    bool adjMat[100][100];
    //Graph's vector location will be the node location, bool is to help with visited or not visited and floats are the values stored at each node
    vector<pair<bool,float>> graph;
};


#endif /* Graph_h */
