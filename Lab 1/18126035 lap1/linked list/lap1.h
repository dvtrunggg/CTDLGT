#ifndef _lap_1_
#define _lap_1_


struct NODE
{
	int key;
	NODE* p_next;
};

struct List
{
	NODE* p_head;
	NODE* p_tail;
};

NODE* CreateNode(int data);
List* CreateList();
void PrintList(List* L);
bool AddHead(List* list, int value);
bool AddTail(List* list, int value);
void RemoveHead(List *L);
void RemoveTail(List *L);
void RemoveAll(List *&L);
int CountElement(List* L);
List* ReverseList(List* L);
void RemoveDuplicate(List* &L);
void PrintList(List* L);
#endif
