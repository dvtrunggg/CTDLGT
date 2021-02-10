#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <fstream>
#define char_int(c) ((int)c - (int)'a')
#define ALPHABET_SIZE 26
#define MAX 50
#define int_to_char(c) ((char)c + (char)'a')
using namespace std;
typedef struct TrieNode 
{ 
    TrieNode *child[ALPHABET_SIZE]; 
	bool isEndOfWord; 
};


TrieNode *GetNode()
{
	
//	 tao node......
	
	TrieNode *node =  new TrieNode; 
	node->isEndOfWord = false;
	for (int i = 0; i < ALPHABET_SIZE; i++) 
		node->child[i] = NULL;
	return node;
}

void Insert(TrieNode *p, string data) 
{ 
    TrieNode *pNext = p; 
  
    for (int i = 0; i < data.length(); i++) //do dai cua data ( data.lenghth)
	{
        int index = data[i] - 'a';        //chuyen ky tu sang so nguyen (index) ( 'a' = 0; 'b' = 1; 'c' = 2;..........; 'z' = 25 )
        if ( !pNext->child[index] )
            pNext->child[index] = GetNode();
        pNext = pNext->child[index]; 
    } 
    pNext->isEndOfWord = true; 
}

bool Search(TrieNode *p, string data)
{ 
	int length = data.length();
    TrieNode *pNext = p; 
  
    for (int i = 0; i < length; i++) 
    { 
        int index = data[i] - 'a';
        cout<<index;
        if (!pNext->child[index]) 
            return false; 
        else
        	pNext = pNext->child[index]; 
    }
    return (pNext != NULL && pNext->isEndOfWord); 
}

void SearchWord(TrieNode *p_root, bool Hash[], string str, char a[], int array[], int n, vector<string> &OutputList) 
{
    if (p_root->isEndOfWord == true) 
	{
		int k;
		int Temp[ALPHABET_SIZE] = {0};
		for(int i = 0; i < ALPHABET_SIZE; i++)
		{
			Temp[i] = array[i];
		}
		if(str.length() >= 3)             // tu nay phai nam trong file dic 
		{
			for(int i = 0; i < 26; i++)
			{
				for(int j = 0; j < str.length(); j++)
				{
//					cout<<char_int(str[j])<<" and "<<i<<endl;
					if( char_int(str[j]) == i )
						Temp[i] = Temp[i] - 1;
				}
			}
			for(k = 0; k < 26; k++)
			{
				if(Temp[k] < 0)
					break;
			}
			if( k == 26 )
//				cout<<"|"<<str<<"| ";
				OutputList.push_back(str);
		}
	}
    // duyet 
	for (int K = 0; K < ALPHABET_SIZE; K++)
	{
		if (Hash[K] == true && p_root->child[K] != NULL )
		{
			char c = int_to_char(K);
			SearchWord(p_root->child[K], Hash, str + c, a, array, n, OutputList); 
		}
	}
}

void PrintWords(char a[], TrieNode *p_root, int n, int array[], vector<string> &OutputList) 
{
	//file dic.txt gom 26 chu cái ( a->z) ( theo bang chu cai). Input voi cac n chu cai thì ta se gan n cac chu cai do là true và 26-n chu cai còn lai là false
	//vd: nhap a c p e => b,e,f,h,k,z,x,.......->false
	int count = 0;
	bool Hash[ALPHABET_SIZE]; 
	for (int i = 0 ; i < n; i++)
	{
		Hash[char_int(a[i])] = true;
	}
	for (int j = 0; j < ALPHABET_SIZE; j++)
	{
		for(int k = 0; k < n; k++)
		{
			if( j != char_int(a[k]))
			{
				if(count == n-1)
				{
					Hash[j] = false;
				}
				count++;
			}
		}
		count = 0;
	}
    TrieNode *pChild = p_root ;  
    string OutputStr = ""; 

//    cac chu cai dc gan gia tri true se cho phep duyet qua child node 
// a co gia tri true.......a->a ?? ( true?), a->b(true?),.......a->z(true?)
	for (int k=0 ; k<ALPHABET_SIZE ;k++)
    { 
        if (Hash[k] == true && pChild->child[k])
        { 
            OutputStr = OutputStr+(char)int_to_char(k);
            SearchWord(pChild->child[k], Hash, OutputStr, a, array, n, OutputList);          //de quy nay co tac dung kiem tra a->a,....a->z true??
            																						// => a->a, a->p, a->c, a->p, a->e là true, else: false.
			OutputStr = "";		// 1 new word																
		}
    }
}

void ReadFile(ifstream &file, string data, TrieNode *&p_root)
{
	file.open("Dic.txt");
	if(file.fail() == true)
	{
		cout<<"Khong tim thay file Dic.txt, check again please...";
	}
	p_root = GetNode();
	while ( !file.eof() ) 
	{
		getline(file,data);
		Insert(p_root,data);
	}
	file.close();
}

int main()
{
	ifstream file;
	string data;
	TrieNode *p_root = new TrieNode;
	ReadFile(file, data, p_root);

// file Input.txt là file chua cac chu cai de ghep lai thành tu thoa yeu cau Input...
	char a[MAX];
	int n = 0;
	string i_s;        // input string
	file.open("Input.txt");
	if(file.fail() == true)
	{
		cout<<"Khong tim thay file Input.txt. Hay tao file Input.txt va nhap du lieu vao."<<endl;
		return 0;
	}
	
	getline(file,i_s);
//	Input:	
	for(int i = 0; i < strlen(i_s.c_str()); i++)
	{
		if(i_s.c_str()[i] != ' ')
		{
			a[n] = i_s.c_str()[i];
			n++;
		}
	}
	cout<<"Input: ";
	for(int i = 0; i < n; i++)
		cout<<a[i]<<"  ";	
	int array[26] = {0}; //mang luu cac chu cai da cho
	
// new word thoa man: có so ky tu > 3 ( yeu cau de Input)
//						ko dc lap lai
//						co so luong chu cai < = n  ( n la so luong chu cai o INPUT)
//       ................................

	
	for(int i = 0; i < 26 ; i++)
	{
		for(int j = 0; j < n; j++)
			if(int_to_char(i) == (int)a[j])
				array[i]++;
	}



	vector< string > OutputList;
	PrintWords(a,p_root,4,array, OutputList);
	
	cout<<"\nSo tu ghep dc : ";
	cout<<OutputList.size()<<endl;
	cout<<"Cac tu ghep dc: "<<endl;
	
	for(int i = 0 ; i < OutputList.size(); i++)
		cout<<OutputList.at(i)<<"\t";
	file.close();
	
	ofstream outfile;
	outfile.open("Output.txt",ios::out);
	outfile << OutputList.size()<<endl;
	
	for(int i = 0 ; i < OutputList.size(); i++)
		outfile << OutputList.at(i)<<endl;
	outfile.close();
	return 0;
}
