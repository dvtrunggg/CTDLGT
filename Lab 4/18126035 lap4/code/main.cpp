#include"sort.h"


int main()
{
	int n;
	cout<<"Nhap n: ", cin>>n;
	int a[n];
	Random(a,n);
	
	
	
	GenerateData(a, n, 0);

/*	cout << "Beforer: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	*/
	  
	clock_t begin = clock(); 
 
   
	SelectionSort(a, n);
	
	
//	clock_t end = clock(); 
/*    cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
	
	MergeSort(a, 0, n - 1);
	
    cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    
	Quick_Sort(a,0,n-1);
	 
    cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
	
	heapSort(a,n);
	
    cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
	 
	RadixSort(a,n);
	
    cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;

	flashSort(a,n);
	
    cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;

	insertionSort(a,n);
 
    cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;

	shakerSort(a,n);
	
    cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;

	shellSort(a,n);
	 
    cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
	
	countingSort( a, n);
	
    cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
*/
	bubbleSort(a,n);
	clock_t end = clock(); 
    cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
	binaryInsertionSort(a,n);

	
	
/*	cout << "   After: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	*/
	
	

	
    cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    	
    	
    	
    	
    	
	//TODO...
	cin.get();
	return 0;
}
