#include "graph.h"
#include <fstream>

int main()
{
	Graph g = ReadGraph("graph.txt");
	if (IsValidGraph(g) == false)
	{
		cout << "Do thi khong hop le" << endl;
		return 0;
	}
	DisplayGraph(g);
	cout << "So canh cua do thi la: " << CountEdge(g) << endl;
	cout << "So dinh bac le cua do thi la: " << CountVertice(g, 1) << endl;
	cout << "So dinh bac chan cua do thi la: " << CountVertice(g, 0) << endl;
	if (IsConnectedGraph(g))
	{
		cout << "Do thi tren la do thi lien thong" << endl;
	}
	else
	{
		int components = CountConnectedComponents(g);
		cout << "Do thi co " << components << " thanh phan lien thong" << endl;
	}
	cout << "TIM DUONG DI NGAN NHAT TREN DO THI" << endl;
	cout << "Nhap dinh bat dau: ";
	int start_vertex;
	cin >> start_vertex;
	cout << "Dijkstra algorithm" << endl;
	FindShortestPathDijkstra(g, start_vertex);
	return 0;
}
