#include"baitap.h"



//POINTER--------------------------------------------------------------


//Cau 1: Input a n-element integer array with int *a is the pointer point to the allocated dynamic memory:
void InputArray(int *&a, int &n)
{
	cout<<"Nhap so phan tu cua mang:", cin>>n;
	a = new int[n];
	for(int i = 0; i < n; i++)
		cout<<" \nArr["<<i<<"] = ", cin>>*(a+i);
}

// cau 2:  Remove allocated dynamic memory:
void DellocateArray(int *&a){
	delete a;
}


//cau 3: Output all elements of the array:
void PrintArray(int *a, int n)
{
	for(int i = 0; i < n; i++)
		cout<<"   "<<*(a+i);
}

//cau 4: Find the smallest value from the array
int FindMin(int *a, int n)
{
	int min = *a;
	for(int i = 0; i < n; i++)
	
		if(min > *(a+i) )
			min = *(a+i);
	return min;
}

//cau 5: Find the greatest absolute value from the array
int FindMaxModulus(int* a, int n)
{
	int max = abs(*a);
	for(int i = 0; i < n; i++)
		if(max < abs(*(a+i)))
			max = abs(*(a+i));
	return max;
}


//cau 6: Check if the array is ascending
bool IsAscending(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		if (*(a + i) > *(a + i + 1))
			return false;
	return true;

	
}

//cau 7: Find the total value of all elements of the array
int SumOfArray(int* a, int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum +=*(a+i);
	return sum;
}

// cau 8: Count the number of prime numbers in the array

int CheckPrime(int x)
{	
	if(x<2) return 0;
	for(int i = 2; i<x; i++)
		if(x%i == 0) return 0;
	return 1;
}

int CountPrime(int *a, int n)       //

{
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if(CheckPrime(a[i]) == 1) count++;
	} 
	return count;
}
	



//cau 9: Create a new dynamic array which is the reverse of the given array:
void ReverseArray(int* &a, int* b, int n)
{
		for(int i = 0; i<n; i++){
			*(b+i) = *(a+n-i-1);
	cout<<"  "<<*(b+i);}
}
		
// cau 10:
int LinearSearch(int* a, int n, int key)
{
	for(int i = 0; i<n ; i++){
		if(a[i] == key)
		return i;
	}
	return -1;
}
//cau 11
int SentinelLinearSearch(int* a, int n, int key)
{
	a[n] = key;
	int i;
	for(i = 0; a[i] |= key; i++);
	if( i == n)
		return -1;
	return i;
}


//cau 12
int BinarySearch(int* a, int n, int key)
{
	int start = 0;
	int end = n -1;
	int mid = (start + end)/2;
	
	while(start <= end)
	{
		if(a[mid] == key)
			return mid;
		if(key > a[mid])
			start = mid - 1;
		if(key<a[mid])
				end = mid -1;
		mid = (start + end)/2;	
	} return -1;
}  


