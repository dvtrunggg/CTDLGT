
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
using namespace std

struct DataOrder {
	int ID;
	string Name;
};

struct SortingAlgorithm {
	string Name;
	void(*Sort) (int*, int);
};

bool IsAscending(int* a, int n);

void Display(int* a, int n);

void ReportText(string file_name);

void ReportCSV(string file_name);
