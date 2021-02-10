#ifndef GRAPH_H
#define GRAPH_H
#include<string.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include "graph.h"
using namespace std;

#define MAX 100
#define oo 1000000000
//#define ii pair<int,int>
//#define mp make_pair

struct Graph
{
	int num_vertices; // number of vertices
	int adjacency_matrix[MAX][MAX]; // adjacency matrix
	bool free[MAX];
};

Graph ReadGraph(string file_name);

bool IsValidGraph(Graph g);

bool IsScalarGraph(Graph g);

void DisplayGraph(Graph g);

int CountEdge(Graph g);

int CountVertice(Graph g, int flag);

void resetState(Graph g);

void BFS(Graph g, int begin_vertex);

void DFS(Graph g, int begin_vertex);

int CountConnectedComponents(Graph g);

bool IsConnectedGraph(Graph g);

void FindShortestPathDijkstra(Graph g, int start_vertex);




#endif
