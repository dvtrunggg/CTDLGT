#include "AVL.h"



NODE* CreateNode(int data)
{
	NODE* p_node = new NODE;
	
	p_node->key = data;
	p_node->p_left = p_node->p_right = NULL;
	p_node->height = 1;
	
	return p_node;
}

int Height(NODE* p_root)
{
	if(p_root == NULL)
		return 0;
	return 1 + max(Height(p_root->p_left), Height(p_root->p_right));
}

NODE* Rotate_Left(NODE* right)
{
	NODE* left = right->p_right;
	right->p_right = left->p_left;
	left->p_left = right;
	
	right->height = Height(right);
	left->height = Height(left);

	return left;	
}

NODE* Rotate_Right(NODE* left)
{
	NODE* right = left->p_left;
	left->p_left = right->p_right;
	right->p_right = left;
	
	right->height = Height(right);
	left->height = Height(left);	
	
	return right;	
}

void Insert(NODE* &p_root, int x)
{
	if(p_root == NULL)
	{
		p_root = CreateNode(x);
		p_root->height =Height(p_root);
	}
	else
	{
		if(p_root->key > x)
			Insert(p_root->p_left, x);
		else if (p_root->key < x)
			Insert(p_root->p_right, x);
		else return;
		
		int balance = Height(p_root->p_left) - Height(p_root->p_right);
		
		if(balance <= -2)
		{
			if(Height(p_root->p_right->p_right) - Height(p_root->p_right->p_left) >= 0)             //phai phai
				p_root = Rotate_Left(p_root);
			if(Height(p_root->p_right->p_right) - Height(p_root->p_right->p_left) < 0)           
			{
				p_root->p_right = Rotate_Right(p_root->p_right);
				p_root = Rotate_Left(p_root);
			}
		}
		else if(balance > 1)
		{
			if(Height(p_root->p_left->p_left) - Height(p_root->p_left->p_right) >= 0)
				p_root = Rotate_Right(p_root);
			if(Height(p_root->p_left->p_left) - Height(p_root->p_left->p_right) < 0)
			{
				p_root->p_left = Rotate_Left(p_root->p_left);
				p_root = Rotate_Right(p_root);
			}	
		}
		p_root->height = Height(p_root);
	}
}

NODE* FindMin(NODE* p_root)
{
	while(p_root->p_left != NULL)
		p_root = p_root->p_left;
		
	return p_root;
}
void UpdateHeight(NODE* p_root)
{
	if(p_root == NULL)
		return;
	else
	{
		p_root->height = Height(p_root);
		UpdateHeight(p_root->p_left);
		UpdateHeight(p_root->p_right);
	}
}

void Remove(NODE* &p_root, int x)
{
	if(p_root == NULL)
		return;
	else
	{
		if(x < p_root->key)
			Remove(p_root->p_left, x);
		else if(x > p_root->key)
			Remove(p_root->p_right, x);
		else
		{
			NODE* temp = p_root;
			if((p_root->p_left == NULL) && (p_root->p_right == NULL))
			{
				delete p_root;
				p_root = NULL;
			}
			else if(p_root->p_left == NULL)
			{
				p_root = p_root->p_right;
				delete temp;
			}
			else if(p_root->p_right == NULL)
			{
				p_root = p_root->p_left;
				delete temp;
			}
			else
			{
				NODE* temp = FindMin(p_root->p_right);
				p_root->key = temp->key;
				Remove(p_root->p_right, temp->key);
			}
		}
	}
	int balance;
	if(p_root == NULL)
		balance = 0;
	else if(p_root->p_left == NULL && p_root->p_right == NULL)
		balance = 0;
	else
		balance = Height(p_root->p_left) - Height(p_root->p_right);
	
	if(balance < -1)
	{
		if(Height(p_root->p_right->p_right) - Height(p_root->p_right->p_left) >= 0)
			p_root = Rotate_Left(p_root);
		else
		{
			p_root->p_right = Rotate_Right(p_root->p_right);
			p_root = Rotate_Left(p_root);
		}
	}
	else if(balance > 1)
	{
		if(Height(p_root->p_left->p_left) - Height(p_root->p_left->p_right) >= 0)
			p_root = Rotate_Right(p_root);
		else
		{
			p_root->p_left = Rotate_Left(p_root->p_left);
			p_root = Rotate_Right(p_root);
		}	
	}
	UpdateHeight(p_root);
}

void NLR(NODE* root)
{
	if (root == NULL)
		return;
		
	cout << "(" << root->key << "; " << root->height << ") ";
	NLR(root->p_left);
	NLR(root->p_right);
}


void LNR(NODE* p_root)
{
	if(p_root == NULL ) return;
	LNR(p_root->p_left);
	cout << "(" << p_root->key << "; " << p_root->height << ") ";
	LNR(p_root->p_right);
	
	 
}
void LRN(NODE* p_root)
{
	if(p_root == NULL ) return;
	LRN(p_root->p_left);
	LRN(p_root->p_right);
	cout << "(" << p_root->key << "; " << p_root->height << ") ";
}

void PrintGivenLevel(NODE* p_root, int level)
{
	if (p_root == NULL)
		return;
	else if (level == 1)
		cout << p_root->key << " - " << "Height: " << p_root->height << endl;
	else if (level > 1)
	{
		PrintGivenLevel(p_root->p_left, level - 1);
		PrintGivenLevel(p_root->p_right, level - 1);
	}	
}

void LevelOrder(NODE* p_root)
{
	int height = Height(p_root);
	for (int i = 0; i <= height; i++)
		PrintGivenLevel(p_root, i);
}
bool IsAVL(NODE *p_root) {
   int lh;
   int rh;
   if(p_root == NULL)
      return 1;
   lh = Height(p_root->p_left); // left height
   rh = Height(p_root->p_right); // right height
   if(abs(lh-rh) <= 1 && IsAVL(p_root->p_left) && IsAVL(p_root->p_right)) return 1;
   return 0;
}



