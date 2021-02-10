#include <iostream>
#include<queue>
#include<math.h>
using namespace std;

struct NODE{
	int key;
	NODE* p_left;
	NODE* p_right;
};

void CreateTree(NODE* &t);
NODE* CreateNode(int data);
void NLR(NODE* p_root);
void LNR(NODE* p_root);
void LRN(NODE* p_root);
void LevelOrder(NODE* p_root);
NODE* Search(NODE* p_root, int x);
void Insert(NODE* &p_root, int x);
NODE* FindMin(NODE* p_root);
void Remove(NODE* &p_root, int x);
int Height(NODE* p_root) ;
int CountNode(NODE* p_root);
int Level(NODE* p_root, NODE* p);
int CountLeaf(NODE* p_root);
int CountLess(NODE* p_root, int x);
int CountGreater(NODE* p_root, int x);
bool isBSTUtil(NODE* p_root, int& prev) ;
bool IsBST(NODE* p_root);
