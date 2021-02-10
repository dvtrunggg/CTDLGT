#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include "ht.h"

#define TABLE_SIZE 2000


Company ReadCompanyInfo(string f_data)
{
//	cout<<f_data<<endl;
	Company companyInfo;
	char info[f_data.size() + 1];
	strcpy(info, f_data.c_str());
//	for(int i = 0; i < strlen(info); i++)
//		cout<<info[i];
//	cout<<endl;
	int s_point = 0, e_point = 0, key = 0;
	for( int i = s_point; i < strlen(info); i++ )
	{
		if( info[i] == '|' || i == strlen(info)-1)
		{
			e_point = i;
		}
		if( s_point != e_point )
		{
			if( key == 0 )
			{
//				cout<<s_point<<"  "<<e_point<<endl;
				companyInfo.name = f_data.substr(s_point,e_point);
				key++;
			}
			else if( key == 1 )
			{
			//	cout<<s_point<<" - "<<e_point<<endl;
				companyInfo.profit_tax = f_data.substr(s_point+1,e_point-s_point-1);
				key++;
			}
			else if( key == 2 )
			{
				companyInfo.address = f_data.substr(s_point+1,e_point);
			}
			s_point = i, e_point = i;
		}

	}
	return companyInfo;
}

vector<Company> ReadCompanyList(string file_name)
{
	string f_data;
	ifstream f;
	f.open(file_name.c_str());
	vector<Company> companyList;
	getline(f,f_data);
	
	if( f.is_open() )
	{
		string line_temp;
		while( !f.eof() )
		{
			getline(f,f_data);
			companyList.push_back(ReadCompanyInfo(f_data));
//			cout<<f_data<<endl;
		}
		f.close();
	}
	return companyList;
}

int CharToASCII(char a)
{
	int num = a;
}

long long HashString(string company_name)
{
	const int p = 31;
	const unsigned long long m = 1e9 + 9;
	string key_str;
	long long hash_value = 0;
	if (company_name.size() <= 20)
		key_str = company_name;
	else
		key_str = string(company_name.c_str() + company_name.size() - 20);
	for (int i = 0; i < key_str.length(); i++)
		hash_value += key_str[i] * pow(p, i);
	hash_value %= m;
	return hash_value;
}

Company* CreateHashTable(vector<Company> list_company)
{
	Company* hash_table = new Company[TABLE_SIZE];
	for (size_t i = 0; i < list_company.size(); i++)
	{
		long long index = HashString(list_company[i].name) % TABLE_SIZE;
		while (!hash_table[index].name.empty() && hash_table[index].name != list_company[i].name)
		{
			index++;
			index %= TABLE_SIZE;
		}
		hash_table[index] = list_company[i];
	}
	return hash_table;
}

void Insert(Company* hash_table, Company company)
{
	long long index = HashString(company.name) % TABLE_SIZE;
	while ((!hash_table[index].name.empty() && hash_table[index].name != company.name) || (!hash_table[index].profit_tax.empty() && hash_table[index].profit_tax != company.profit_tax) || (!hash_table[index].address.empty() && hash_table[index].address != company.address))
	{
		index++;
		index %= TABLE_SIZE;
	}
	hash_table[index] = company;
}

Company* Search(Company* hash_table, string company_name)
{
	long long index = HashString(company_name) % TABLE_SIZE;

	while (!hash_table[index].name.empty() || !hash_table[index].profit_tax.empty() || !hash_table[index].address.empty())
	{
		if (hash_table[index].name == company_name)
		{
			return &hash_table[index];
		}

		index++;
		index %= TABLE_SIZE;
	}

	return NULL;
}

