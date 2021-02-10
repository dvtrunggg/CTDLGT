#include"pointer.h"
int main(){
	int n,key;
	int *a = new int;
	InputArray(a,n);
//	PrintArray(a,n);
//	cout<<"\n\nso min = "<<FindMin(a,n);
//	cout<<"\n max tuyet doi cua mang = "<<FindMaxModulus(a,n);
	if(IsAscending(a,n)) 
		cout<<"Mang ko tang dan.";
	else 
		cout<<"Mang tang dan";
	//cout<<" sum = "<<SumOfArray(a,n);
//	cout<<"\nso luong so ngto: "<<CountPrime(a,n);
//	ReverseArray(a,b,n);
//	LinearSearch(a,n, key);
	DellocateArray(a);
//	DellocateArray(b);
	return 0;
}
	

