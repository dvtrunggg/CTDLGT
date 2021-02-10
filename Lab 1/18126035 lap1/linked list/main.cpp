#include <iostream>
#include "lap1.h"

using namespace std;

int main()
{
	List *list = CreateList();
	
	int key;
	cout << "Input: ";
	cin >> key;
	while(key != 0)
	{
		AddHead(list, key);
		cin >> key;
	}
	
	PrintList(list);
	cout << endl;
//	AddTail(list, 5);
//	PrintList(list);
//	RemoveHead(list);
//	PrintList(list);
//	cout<<endl;
//	RemoveTail(list);
//	PrintList(list);
//	cout<<endl;
//	RemoveAll(list);
//	PrintList(list);
	cout<<endl;
	cout << CountElement(list);
	cout<<endl;
	
	List* list_2 = ReverseList(list);
	PrintList(list_2);
	cout<<endl;
	return 0;
}
