#include <iostream>

using namespace std;

struct node
{
	int val;
	node *next;
};

node *createNewNode(int val)
{
	node *np = new node;
	np->next = NULL;
	np->val	=	val;
	return np;
}

void insert(node *&root, int val)
{
	if(root == NULL) {	root = createNewNode(val); return; }

	node *np = createNewNode(val);
	np->next = root;
	root = np;
}

void print(node *root)
{
	if(root == NULL) return;
	cout<<root->val<<" ";
	print(root->next);
}