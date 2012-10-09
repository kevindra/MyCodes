#include <iostream>

using namespace std;

struct node
{
	int val;
	node *left, *right;
};

node *createNewNode(int val)
{
	node *np = new node;
	np->val = val;
	np->left = NULL;
	np->right = NULL;
	return np;
}

void insert(node *&root, int val)
{
	if(root == NULL) { root = createNewNode(val); return; }

	if(val < root->val) insert(root->left, val);
	else insert(root->right, val);
}

void inorder(node *root)
{
	if(root == NULL) return;

	inorder(root->left);
	cout<<root->val<<" -> ";
	inorder(root->right);
}

int main()
{
	int a[] = {20,10,30,11,29,31,13,12};
	int n = 8;

	node *root = NULL;
	for(int i=0; i<n; i++) insert(root, a[i]);

	cout<<"Inorder: ";
	inorder(root);
	cout<<endl;

	node *t = root->left->right->right;

	system("pause");
	return 0;
}