#include <iostream>
#include<math.h>
#include<queue>

using namespace std;

struct NODE
{
	int key;
	NODE* p_left;
	NODE* p_right;
	int height;
};


NODE* CreateNode(int data);
int Height(NODE* p_root);
NODE* Rotate_Left(NODE* right);
NODE* Rotate_Right(NODE* left);
void Insert(NODE* &p_root, int x);
NODE* FindMin(NODE* p_root);
void UpdateHeight(NODE* p_root);
void Remove(NODE* &p_root, int x);
void NLR(NODE* root);
void LNR(NODE* p_root);
void LRN(NODE* p_root);
void PrintGivenLevel(NODE* p_root, int level);
void LevelOrder(NODE* p_root);
bool IsAVL(NODE *p_root);
