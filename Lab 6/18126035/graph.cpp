#include"graph.h"
#include <iostream>


using namespace std;
Graph ReadGraph(string file_name)
{
	fstream input;
	char str[file_name.size() + 1];
	strcpy(str, file_name.c_str());
	input.open(str,ios::in);
	
	Graph graph;
	input >> graph.num_vertices;
	for (int i = 0; i < graph.num_vertices; i++)
	{
		graph.free[i] = true;
	}
	for (int i = 0; i < graph.num_vertices; i++)
	{
		for (int j = 0; j < graph.num_vertices; j++)
		{
			input >> graph.adjacency_matrix[i][j];
		}
	}
	input.close();
	return graph;
}

bool IsValidGraph(Graph g)
{
	if (g.num_vertices < 0)
		return false;
	for (int i = 0; i < g.num_vertices; i++)
	{
		if (g.adjacency_matrix[i][i] != 0)
			return false;
		for (int j = 0; j < g.num_vertices; j++)
		{
			if (i != j && g.adjacency_matrix[i][j] < 0)
				return false;
		}
	}
	return true;
}

bool IsScalarGraph(Graph g)
{
	for (int i = 0; i < g.num_vertices; i++)
	{
		for (int j = i + 1; j < g.num_vertices; j++)
		{
			if (g.adjacency_matrix[i][j] != g.adjacency_matrix[j][i])
			{
				return false;
			}
		}
	}
	return true;
}

void DisplayGraph(Graph g)
{
	cout << "So luong dinh cua do thi la: " << g.num_vertices << endl;
	bool flag = IsScalarGraph(g);
	for (int i = 0; i < g.num_vertices; i++)
	{
		for (int j = 0; j < g.num_vertices; j++)
		{
			if (flag)
			{
				if (i <= j && g.adjacency_matrix[i][j])
					cout << i << "<->" << j << endl;
			}
			else
			{
				if (g.adjacency_matrix[i][j])
					cout << i << "->" << j << endl;
			}
		}
	}
}

int CountEdge(Graph g)
{
	int count = 0;
	for (int i = 0; i < g.num_vertices; i++)
    		for (int j = 0; j < g.num_vertices; j++)
    			if ((g.adjacency_matrix[i][j] == g.adjacency_matrix[j][i]) && (g.adjacency_matrix[i][j] != 0))
    				count++;
    return count / 2;
}

int CountVertice(Graph g, int flag)
{
	int evenDegVertices = 0;
	for(int i = 0;i<g.num_vertices;i++)
	{
		int deg = 0;
		for (int j = 0; j < g.num_vertices; j++)
		{
			if (g.adjacency_matrix[i][j] == 1)
				deg++;
		}
		if (deg % 2 == 0)
			evenDegVertices++;
	}
	if (flag == 1)
		return g.num_vertices - evenDegVertices;
	else
		return evenDegVertices;
}


void resetState(Graph g)
{
	for (int i = 0; i < g.num_vertices; i++)
	{
		g.free[i] = true;
	}
}

void BFS(Graph g, int start_vertex)
{
	g.free[start_vertex] = false;
	queue<int> q;
	q.push(start_vertex);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v = 0; v < g.num_vertices; v++)
		{
			if (g.adjacency_matrix[u][v] == 1 && g.free[v])
			{
				g.free[v] = false;
				q.push(v);
			}
		}
	}
}

void DFS(Graph g, int start_vertex)
{
	g.free[start_vertex] = false;
	stack<int> q;
	q.push(start_vertex);
	while (!q.empty())
	{
		int u = q.top();
		q.pop();
		for (int v = 0; v < g.num_vertices; v++)
		{
			if (g.adjacency_matrix[u][v] == 1 && g.free[v])
			{
				g.free[v] = false;
				q.push(v);
			}
		}
	}
}

int CountConnectedComponents(Graph g)
{
	resetState(g);
	int components = 0;
	for (int i = 0; i < g.num_vertices; i++)
	{
		if (g.free[i] == true)
		{
			components++;
			BFS(g, i);
		}
	}
	return components;
}

bool IsConnectedGraph(Graph g)
{
	return (CountConnectedComponents(g) == 1);
}



int minDistance(int dist[], bool sptSet[]) 
{  
    int min = INT_MAX, min_index; 
  
    for (int i = 0; i < MAX; i++) 
        if (sptSet[i] == false && dist[i] <= min) 
            min = dist[i], min_index = i; 
  
    return min_index; 
} 
  

int printSolution(int dist[]) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < MAX; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 
  
void FindShortestPathDijkstra(Graph g, int start_vertex) 
{ 
    int dist[MAX]; 
    bool sptSet[MAX];  
    for (int i = 0; i < MAX; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
  
    dist[start_vertex] = 0; 
  
    for (int count = 0; count < MAX - 1; count++) { 
        
        int u = minDistance(dist, sptSet); 
  
        sptSet[u] = true; 
        for (int v = 0; v < MAX; v++) 
  
            if (!sptSet[v] && g.adjacency_matrix[u][v] && dist[u] != INT_MAX 
                && dist[u] + g.adjacency_matrix[u][v] < dist[v]) 
                dist[v] = dist[u] + g.adjacency_matrix[u][v]; 
    } 
  
    printSolution(dist); 
} 
