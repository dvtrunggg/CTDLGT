#include "BST.h"

// tao 1 cay 
void CreateTree(NODE* &t)
{
	t = NULL;
}
NODE* CreateNode(int data)
{
	NODE *root = new NODE;
	root->key = data;
	root->p_left = root->p_right = NULL;
	return root;
}


void NLR(NODE* p_root)
{
	if(p_root == NULL) return;
	else
	{
		cout<<p_root->key<<"  ";
		NLR(p_root->p_left);
		NLR(p_root->p_right);
	}
}
void LNR(NODE* p_root)
{
	if(p_root == NULL) return;
	else
	{
		LNR(p_root->p_left);
		cout<<p_root->key<<"  ";
		LNR(p_root->p_right);
	}
}
void LRN(NODE* p_root)
{
	if(p_root == NULL) return;
	else
	{
		LRN(p_root->p_left);
		LRN(p_root->p_right);
		cout<<p_root->key<<"  ";
	}
}

void LevelOrder(NODE* p_root)
{
	if(p_root == NULL) return;
	else
	{
		queue <NODE*> temp;
		temp.push(p_root);
		
		while(!temp.empty())
		{
			NODE* node = temp.front();
			cout<<node->key<<" ";
			temp.pop();
			
			if(node->p_left !=NULL)
				temp.push(node->p_left);
			if(node ->p_right != NULL)
				temp.push(node->p_right);
		}
	}
}
NODE* Search(NODE* p_root, int x)
{
	if(p_root == NULL) return NULL;
	else
	{
		if(x < p_root->key)
			return Search(p_root->p_left, x);
		if(x > p_root->key)
			return Search(p_root->p_right, x);
		return p_root;
	}
}
// them phan tu
void Insert(NODE* &p_root, int x)
{
	if(p_root == NULL)
		p_root = CreateNode(x);
	else
	{
		if(x > p_root->key)             // x > root
			Insert(p_root->p_right, x);
		if(x < p_root->key)              // x < root
			Insert(p_root->p_left, x);
	}
}

NODE* FindMin(NODE* p_root)  // t�m node tr�i nhat ben phai ( node MIN ben phai)
{
	while(p_root->p_left != NULL)
	{
		p_root = p_root->p_left;
	}
	return p_root;
}
void Remove(NODE* &p_root, int x)
{
	if(p_root == NULL) return;
	// duyet cay de t�m phan tu x can x�a
	else
	{
		if(x < p_root->key)             // duyet sang trai
			Remove(p_root->p_left, x);
		else if(x>p_root->key )               // duyet sang phai
			Remove(p_root->p_right, x);
		else                          // da t�m dc gi� tri can x�a
		{
			NODE* temp = p_root;
			
			
			// x�a node l� ( c� 0 con ): x�a truc tiep node do v� x�a node A c� 1 con: dua node B len thay the cho A, dua B th�nh node l� roi x�a A.
			
			//x�a node 0 con
			if((p_root->p_left == NULL) && (p_root->p_right == NULL))
			{
				delete p_root;
				p_root = NULL;
			}
			else if(p_root->p_left  == NULL){       // node A ko c� con ben tr�i
				p_root = p_root->p_right;		// dua B len vi tr� A
				delete temp;
			}
			else if(p_root->p_right == NULL)
			{
				p_root = p_root->p_left;
				delete temp;
			}
			
			
			/* x�a node A c� 2 con:
			*C�ch 1: Thay the A = node B: node tr�i nhat ben phai cua A ( l� node MIN trong nh�nh phai cua A) ( tui chon c�ch n�y nhaaaa)
			C�ch 2: ..................C........phai..........tr�i......(l� node MAX trong nh�nh tr�i cua A)
			*/
			else
			{
				NODE *temp = FindMin(p_root->p_right);
				p_root->key= temp->key;            // thay the vi tr�  ( khi n�y, B se thay the vi tr� cua A, tren cay BST se c� 2 gi� tri B)
				Remove(p_root->p_right, temp->key);         // de quy lai tu ph�a nh�nh phai cua node B tai vi tr� moi, t�m dc B o vi tr� cu ( xuat hien 2 lan)
															// x�a thang B o vi tr� cu di
			}
		}
	}
	
}

int Height(NODE* p_root)         // do sau lon nhat
{
	if(p_root == NULL) return 0;
	else
	{
		return (1+max(Height(p_root->p_left), Height(p_root->p_right)));
	}
}




int CountNode(NODE* p_root)
{
	int count = 0;
	if(p_root == NULL) return 0;
	else
	{
		count++;
		count = count + CountNode(p_root->p_left);
		count = count + CountNode(p_root->p_right);
	}
	return count;
}


int Level(NODE* p_root, NODE* p)
{
	if (p_root == p)
		return 0;
		
	if(p_root->p_left == NULL && p_root->p_right == NULL)
      return -1;

   	int level_left = Level(p_root->p_left, p); 
  	int level_right = Level(p_root->p_right, p); 

   	if(level_left == -1)
      return level_right+1; 
   	else  
      return level_left+1; 

   	return -1;
}

int CountLeaf(NODE* p_root)
{
	int count = 0;
	if(p_root == NULL) return 0;
	else
	{
		//duyet
		count += CountLeaf(p_root->p_left);
		count += CountLeaf(p_root->p_right);
		if(p_root->p_left == NULL && p_root->p_right == NULL) count++;
			return count;
		
	}
}

int CountLess(NODE* p_root, int x)
{
	int n;
	if(p_root == NULL) return 0;
	else
	{
		if(p_root->key <x )
			n = 1 + CountNode(p_root->p_left) + CountLess(p_root->p_right, x); 
		else
			n = CountLess(p_root->p_left,x);
		return n;
	}
}

int CountGreater(NODE* p_root, int x)
{
	int n;
	if(p_root == NULL) return 0;
	else
	{
		if(p_root->key> x )
			n = 1 + CountNode(p_root->p_right) + CountGreater(p_root->p_left,x);
		else
			n = CountGreater(p_root->p_right, x);
		return n;
	}
}

bool isBSTUtil(NODE* p_root, int& prev) 
{ 
    // traverse the tree in inorder fashion and 
    // keep track of prev node 
    if (p_root) { 
        if (!isBSTUtil(p_root->p_left, prev)) 
            return false; 
  
        // Allows only distinct valued nodes 
        if (p_root->key <= prev) 
            return false; 
  
        // Initialize prev to current 
        prev = p_root->key; 
  
        return isBSTUtil(p_root->p_right, prev); 
    } 
  
    return true; 
} 
  
//  check BST???
bool IsBST(NODE* p_root) 
{ 
    int prev = INT_MIN; 
    return isBSTUtil(p_root, prev); 
} 




