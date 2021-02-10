#include"sort.h"

void Random(int a[], int n)
{
   for(int i = 0; i < n; i++)
    	a[i] = rand();
}


void Swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
//	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		Swap(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

void SelectionSort(int a[], int n)
{
	int i, j, min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[min] > a[j])
				min = j;
		}
		Swap(a[i],a[min]);
	}

}

int Partition(int a[], int first, int last)
{
	int pivot = a[first];
	int left = first + 1;
	int right = last;
	while (true)
	{
		while (left <= right && left < pivot)
			left++;
		while (right >= left && right > pivot)
			right--;
		if (left >= right)break;
		Swap(a[left], a[right]);
		left++;
		right--;

	}
	Swap(a[right], a[first]);
	return right;
}
void Quick_Sort(int a[], int first, int last)
{
	if (first > last)
	{
		int pivot = Partition(a, first, last);
		Quick_Sort(a, first, pivot - 1);
		Quick_Sort(a, pivot + 1, last);
	}
}

void Merge(int a[], int left, int mid, int right)
{
	int n1 = mid - left + 1; 
	int n2 = right - mid; 

	int* tmp1 = new int[n1]; 
	int* tmp2 = new int[n2]; 

	for (int i = 0; i < n1; i++)
		tmp1[i] = a[left + i]; 
	for (int j = 0; j < n2; j++)
		tmp2[j] = a[mid + 1 + j];

	int i = 0, j = 0, k = left; 
	while (i < n1 && j < n2)
	{
		if (tmp1[i] <= tmp2[j])
		{
			a[k] = tmp1[i]; 
			i++; 
		}
		else
		{
			a[k] = tmp2[j]; 
			j++; 
		}
		k++; 
	}

	while (i < n1)
	{
		a[k] = tmp1[i]; 
		i++; 
		k++; 
	}
	while (j < n2)
	{
		a[k] = tmp2[j]; 
		j++; 
		k++; 
	}
}

void MergeSort(int a[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2; 
		MergeSort(a, left, mid); 
		MergeSort(a, mid + 1, right); 
		Merge(a, left, mid, right); 
	}
}
void heap(int arr[], int n, int i)
{
	int max = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[max])
	{
		max = l;
	}

	if (r < n && arr[r] > arr[max])
	{
		max = r;
	}

	if (max != i)
	{
		Swap(arr[i], arr[max]);
		heap(arr, n, max);
	}
}

void heapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heap(a, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		Swap(a[0], a[i]);
		heap(a, i, 0);
	}
}

void RadixSort(int a[], int n)
{
	int max = a[0], b[100], k = 1;

	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}

	while (max / k > 0)
	{
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++)
			bucket[a[i] / k % 10]++;
		for (int i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (int i = n - 1; i >= 0; i--)
			b[--bucket[a[i] / k % 10]] = a[i];
		for (int i = 0; i < n; i++)
			a[i] = b[i];
		k *= 10;
	}
}

void flashSort(int a[], int n){
	int i, j, k, t;
	i = j = k = 0;
	int m = (int)(n * 0.45);
	int* l = new int[m];

	int min = a[0];
	int idmax = 0;
	int idmove = 0;

	for (i = 1; i < n; ++i)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > a[idmax])
		{
			idmax = i;
		}
	}

	if (min == a[idmax])
	{
		return;
	}

	int c1 = (m - 1) / (a[idmax] - min);

	for (k = 0; k < m; k++)
	{
		l[k] = 0;
	}
	for (j = 0; j < n; j++)
	{
		k = (int)(c1 * (a[j] - min));
		++l[k];
	}

	for (int p = 1; p < m; ++p)
	{
		l[p] = l[p] + l[p - 1];
	}

	int hold = a[idmax];
	a[idmax] = a[0];
	a[0] = hold;

	idmove = 0; int flash;
	j = 0; k = m - 1;
	while (idmove < (n - 1))
	{
		while (j >(l[k] - 1)){
			++j;
			k = (int)(c1 * (a[j] - min));
		}
		if (k < 0)
		{
			break;
		}

		flash = a[j];
		while (j != l[k])
		{
			k = (int)(c1 * (flash - min));
			hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++idmove;
		}
	}

	for (j = 1; j < n; j++)
	{
		hold = a[j];
		i = j - 1;
		while (i >= 0 && a[i] > hold)
		{
			a[i + 1] = a[i--];
		}
		a[i + 1] = hold;
	}

}
void insertionSort(int* a, int n){
	int j, x;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > x)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void shakerSort(int a[], int n)
{
	int l = 0;
	int r = n - 1;
	int k = 0;
	while (l < r)
	{
		for (int i = l; i < r; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(a[i], a[i + 1]);
				k = i;
			}
		}
		r = k;
		for (int i = r; i > l; i--)
		{
			if (a[i] < a[i - 1])
			{
				Swap(a[i], a[i - 1]);
				k = i;
			}
		}
		l = k;
	}
}


void shellSort(int a[], int n)
{
	int j, x;
	for (int mid = n / 2; mid > 0; mid /= 2)
	{
		for (int i = mid; i < n; i += 1)
		{
			int x = a[i];
			for (j = i; j >= mid && a[j - mid] > x; j -= mid)
			{
				a[j] = a[j - mid];
			}
			a[j] = x;
		}
	}
}
int findMax(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}


void countingSort(int a[], int n)
{
	int max = findMax(a, n) + 1;
	int* c = new int[max];
	for (int i = 0; i < max; i++)
	{
		c[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		c[a[i]]++;
	}
	for (int i = 1; i < max; i++)
	{
		c[i] += c[i - 1];
	}

	int *b = new int[n];
	for (int i = n - 1; i >= 0; i--)
	{
		b[--c[a[i]]] = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = b[i];
	}
	delete[] b;
	delete[] c;
}

void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
     {  
    	for (j = 0; j < n-i-1; j++)  
        	if (arr[j] > arr[j+1])  
            	Swap(arr[j], arr[j+1]);  
	}
}  	


int binarySearch(int a[], int item, int low, int high) 
{ 
    if (high <= low) 
        return (item > a[low])?  (low + 1): low; 
  
    int mid = (low + high)/2; 
  
    if(item == a[mid]) 
        return mid+1; 
  
    if(item > a[mid]) 
        return binarySearch(a, item, mid+1, high); 
    return binarySearch(a, item, low, mid-1); 
} 
   
void binaryInsertionSort(int a[], int n) 
{ 
    int i, loc, j, k, selected; 
  
    for (i = 1; i < n; ++i) 
    { 
        j = i - 1; 
        selected = a[i]; 
        loc = binarySearch(a, selected, 0, j); 
  
  
        while (j >= loc) 
        { 
            a[j+1] = a[j]; 
            j--; 
        } 
        a[j+1] = selected; 
    } 
} 


