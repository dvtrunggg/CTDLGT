
#include <iostream>
#include "lap1.h"

using namespace std;

NODE* CreateNode(int data)
{
	NODE* node = new NODE;
	if(node == NULL)
		return NULL;
	node->key = data;
	node->p_next = NULL;
	return node;
}

List* CreateList()
{
	List* list = new List;
	list->p_head = list->p_tail = NULL;
	return list;	
}

void PrintList(List* L)
{
	for (NODE* p = L->p_head; p != NULL; p = p->p_next)
	{
		cout << p->key << " ";
	}
}

bool AddHead(List* list, int value)
{
	NODE* node = new NODE;
	node = CreateNode(value);
	
	if (node == NULL)
		return false;
	
	if (list->p_head == NULL)
		list->p_head = list->p_tail = node;
	else
	{
		node->p_next = list->p_head;
		list->p_head = node;
	}
	
	return true;
}

bool AddTail(List* list, int value)
{
	NODE * node = new NODE;
	node = CreateNode(value);
	
	if(node == NULL)
		return false;
	if(list->p_head == NULL)
		list->p_head = list->p_tail = node;
	else
	{
		list->p_tail->p_next = node;
		list->p_tail = node;
	}
	return true;
}
void RemoveHead(List *L)
{
	NODE *p=L->p_head;
	L->p_head=L->p_head->p_next;
	delete p;
}
void RemoveTail(List *L)
{
	NODE *p=L->p_head;
	while(p->p_next!=L->p_tail)
	{
		p=p->p_next;
	}
	L->p_tail=p;
	p=L->p_tail->p_next;
	L->p_tail->p_next=NULL;
	delete p;
}
void RemoveAll(List *&L)
{
	while(L->p_head!=NULL)
	{
		RemoveHead(L);
	}
}

int CountElement(List* L)
{
	int count = 0;
	for(NODE* p = L->p_head; p != NULL; p = p->p_next)
		count ++;
	return count;
}

List* ReverseList(List* L)
{
	NODE* p = L->p_head;
	List* list_2 = CreateList();
	while(p != NULL)
	{
		AddHead(list_2, p->key);
		p = p->p_next;
	}
	return list_2;
}
void RemoveDuplicate(List* &L){
    NODE* current = L->p_head;  
  
    NODE* temp;  
    if (current == NULL)  
    	return;  
  
    while (current->p_next != NULL)  
    {  
    	if (current->key == current->p_next->key)  
    	{      
        	temp = current->p_next->p_next;  
        	delete(current->p_next);  
        	current->p_next = temp;  
    	}  
   		else
      		current = current->p_next;   
    }  
}

void PrintList(List* L){
    cout << "OUTPUT: " << endl;
    for(NODE *p = L->p_head; p != NULL; p = p->p_next)
        cout << p->key << " ";
    cout << endl;
}

