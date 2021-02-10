#include "Examinee.h"


void DisplayExaminee(Examinee ex)
{
	cout << ex.id << endl;
	cout << ex.math << endl;
	cout << ex.literture << endl;
	cout << ex.physic << endl;
	cout << ex.chemistry << endl;
	cout << ex.biology << endl;
	cout << ex.history << endl;
	cout << ex.geography << endl;
	cout << ex.civic_education << endl;
	cout << ex.natural_science << endl;
	cout << ex.social_science << endl;
	cout << ex.foreign_language << endl;
}


int main()
{
	Examinee ex;
	ex = ReadExaminee("BD1200001,,4.0,5.0,,,,4.25,7.0,7.75,,,2.0,N1,BinhDinh");
	
	vector<Examinee> list_ex;
	list_ex = ReadExamineeList("data.txt");
	//DisplayExaminee(list_ex[1000]);
	SumOfScore(list_ex, "result.txt");
	return 0;
}
