#include <string>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;


struct Company
{
	string name;
	string profit_tax;
	string address;
};

struct NODE
{
	long long key;
	NODE* p_next;
};

Company ReadCompanyInfo(string f_data);
vector<Company> ReadCompanyList(string file_name);
long long HashString(string company_name);
Company* CreateHashTable(vector<Company> list_company);
void Insert(Company* hash_table, Company company);
Company* Search(Company* hash_table, string company_name);
