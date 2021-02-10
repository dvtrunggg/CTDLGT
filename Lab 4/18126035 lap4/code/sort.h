#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <stdlib.h>

using namespace std;

void Random(int a[], int n);

void Swap(int &a, int &b);
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

void SelectionSort(int a[], int n);

int Partition(int a[], int first, int last);
void Quick_Sort(int a[], int first, int last);

void Merge(int a[], int left, int mid, int right);
void MergeSort(int a[], int left, int right);

void heap(int arr[], int n, int i);
void heapSort(int a[], int n);

void RadixSort(int a[], int n);

void flashSort(int a[], int n);

void insertionSort(int* a, int n);

void shakerSort(int a[], int n);

void shellSort(int a[], int n);

int findMax(int a[], int n);
void countingSort(int a[], int n);

void bubbleSort(int arr[], int n);

int binarySearch(int a[], int item, int low, int high);
void binaryInsertionSort(int a[], int n);



