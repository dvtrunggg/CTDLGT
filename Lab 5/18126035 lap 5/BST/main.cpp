#include"BST.h"
main()
{
	NODE *p  = NULL;   // tao root = NULL tu ban dau
	Insert(p, 6);
	Insert(p, 15);
	Insert(p, 35);
	Insert(p, 4);
	Insert(p, 1);
	Insert(p, 7);
	Insert(p, 10);
	Insert(p,5);
	NLR(p);
	
//	int n;
/*	cout<<"\ntim phan tu: ", cin>>n;
	if(Search(p,n) == NULL)
		cout<<n<<" ko ton tai"<<endl;
	else cout<<n<<" ton tai";
	Search(p,10);
	*/
//	cout<<"\n all nodes = "<<CountNode(p);
//	Remove(p,6);
	cout<<endl;
//	NLR(p);
//	cout<<"Height of tree: "<<Height(p);
//	LevelOrder(p);
//	cout<<"so node la: "<<CountLeaf(p);
//	cout<<" count = "<<CountLess(p,35);
//	cout<<" count = "<<CountGreater(p,35);


}
