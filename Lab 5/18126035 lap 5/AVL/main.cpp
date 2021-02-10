#include "AVL.h"
int main()
{
	NODE *root = NULL;
	
	Insert(root, 30);
	Insert(root, 40);
	Insert(root, 50);
	Insert(root, 11);
	Insert(root, 33);
	Insert(root, 6);
	Insert(root, 13);
	Insert(root, 20);
	LRN(root);
	LNR(root);
//	NLR(root);
//	Remove(root, 11);
//	cout << endl;
//	NLR(root);
//	LevelOrder(root);
	
	if(IsAVL(root))
      cout << "The Tree is AVL Tree"<<endl;
   else
      cout << "The Tree is not AVL Tree "<<endl;
	
	return 0;
}
