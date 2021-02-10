#include "ht.h"
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main()
{
	vector <Company> CompanyList;
	CompanyList = ReadCompanyList("MST.txt");
	Company* HashTable;
	int i;
	HashTable = CreateHashTable(CompanyList);
	return 0;
}
