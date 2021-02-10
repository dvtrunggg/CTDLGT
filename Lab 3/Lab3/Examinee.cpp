#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "Examinee.h"
using namespace std;
Examinee ReadExaminee(string line_info)
{
	Examinee student;
	char str[line_info.size() +1];
	strcpy(str, line_info.c_str());
	int length = strlen(str);
	int s_point = 0, e_point = 0, count =0;
	string temp;
	for( int i = s_point; i < strlen(str); i++)
	{
		if (str[i] == ',')
		{
			e_point = i;
		}
		if(s_point != e_point)
		{
			if(count == 0)
			{
				student.id = line_info.substr(s_point,e_point);
			}
			else if(count == 2)
			{
				temp = line_info.substr(s_point + 1, e_point - s_point);
				student.math = atof(temp.c_str());
			}
			else if(count ==3)
			{
				temp = line_info.substr(s_point + 1, e_point - s_point);
				student.literture = atof(temp.c_str());
			}
			else if(count ==4)
			{
				temp = line_info.substr(s_point + 1, e_point - s_point);
				student.physic = atof(temp.c_str());
			}
			else if(count ==5)
			{
				temp = line_info.substr(s_point + 1, e_point - s_point);
				student.chemistry = atof(temp.c_str());
			}
			else if(count ==6)
			{
				temp = line_info.substr(s_point + 1, e_point - s_point);
				student.biology = atof(temp.c_str());
			}
			else if(count ==7)
			{
				temp = line_info.substr(s_point + 1, e_point - s_point);
				student.history = atof(temp.c_str());
			}
			else if(count ==8)
			{
				temp = line_info.substr(s_point + 1, e_point - s_point);
				student.geography = atof(temp.c_str());
			}
			else if(count ==9)
			{
				temp = line_info.substr(s_point + 1, e_point - s_point);
				student.civic_education = atof(temp.c_str());
			}
			else if(count ==10)
			{
				temp = line_info.substr(s_point + 1, e_point - s_point);
				student.natural_science = atof(temp.c_str());
			}
			else if(count ==11)
			{
				temp = line_info.substr(s_point + 1, e_point - s_point);
				student.social_science = atof(temp.c_str());
			}
			else if(count ==12)
			{
				temp = line_info.substr(s_point + 1, e_point - s_point);
				student.foreign_language = atof(temp.c_str());
			}
			s_point = i, e_point = i;
			count ++;
			}
		}
			return student;
}


vector<Examinee> ReadExamineeList(string file_name)
{
	vector<Examinee> arr_examinee;
	arr_examinee.clear();
	
	ifstream file;
	file.open(file_name.c_str());
	
	if (file.is_open())
	{
		string line_temp;
		getline(file, line_temp, '\n');
		
		while(!file.eof())
		{
			file >> line_temp;
			arr_examinee.push_back(ReadExaminee(line_temp));
		}
		
		file.close();
	}
	else
		cout << "khong mo duoc file!";
	
	return arr_examinee;
}

void SumOfScore(vector<Examinee> examinee_list, string out_file_name)
{
	ofstream out_file;
	out_file.open(out_file_name.c_str());
	if (!out_file.is_open())
		cout << "ERROR : Cannot open the file" << endl;
	
	for (int i = 0; i < examinee_list.size(); i++)
	{
		examinee_list[i].natural_science = examinee_list[i].physic + examinee_list[i].chemistry + examinee_list[i].biology;
		examinee_list[i].social_science = examinee_list[i].history + examinee_list[i].geography + examinee_list[i].civic_education;
		
		out_file << examinee_list[i].id << " ";
		out_file << examinee_list[i].math + examinee_list[i].literture + examinee_list[i].foreign_language +
		  			examinee_list[i].natural_science + examinee_list[i].social_science;
		out_file << endl;
	}
	
	out_file.close();
}

					
