/**
*	Given a binary matrix, print all unique rows of the given matrix.
*/

#include <iostream>
#include <string>

using namespace std;

#define MAXCHILD 2

struct trie
{
	bool isEnd;
	int val;
	trie *child[MAXCHILD]; // just the zero and one
};

trie *createNewNode(int val)
{
	trie *t = new trie;
	t->isEnd = false;
	t->val = val;

	for(int i=0; i<MAXCHILD; i++) t->child[i] = NULL;
	return t;
}

void insert(trie *&root, int *a, int i, int n)
{
	if(root == NULL) root = createNewNode(a[i]);

	if(i == n) { root->isEnd = true; return; }

	insert(root->child[a[i]], a, i+1, n);
}

void printAllStrings(trie *root, string str)
{
	if(root == NULL) return;

	if(root->isEnd) { cout<<str<<endl; return; }

	for(int i=0; i<MAXCHILD; i++)	{
		char bit = i + '0';
		printAllStrings(root->child[i], str + bit); 
	}
}

int main()
{
	int r=4,c=5;
	int mat[4][5] = {{0, 1, 0, 0, 1}, 
				{1, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
				{1, 1, 1, 0, 0}};
				
	//for(int i=0; i<r; i++) for(int j=0; j<c; j++) cin>>mat[i][j];

	for(int i=0; i<r; i++) {for(int j=0; j<c; j++) {cout<<mat[i][j]<<" ";} cout<<endl;}

	trie *root = createNewNode(-1);
	for(int i=0; i<r; i++)
		insert(root, mat[i], 0, c);

	cout<<"STRINGS: "<<endl;
	printAllStrings(root, "");
	cout<<endl;

	system("pause");
	return 0;
}