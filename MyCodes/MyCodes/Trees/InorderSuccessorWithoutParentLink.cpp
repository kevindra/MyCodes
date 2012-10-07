/**
* Find inorder successor.
* Without the parent link.
*/
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

node *getMin(node *root)
{
	if(root == NULL) return NULL;

	while(root->left)
	{
		root = root->left;
	}
	return root;
}

/**
* Inorder Successor without the parent pointer
*/
node *inorderSuccessor(node *root, node *n)
{
	// if right subtree of n exists, the return the min. of right subtree
	if(n->right) return getMin(n->right);

	// if there is no right subtree of n, 
	// then return the ancestor of n whose left subtree contains n.

	node *succ = root;
	while(root)
	{
		if(n->val < root->val)
		{
			succ = root;
			root = root->left;
		}
		else if(n->val > root->val)
		{
			root = root->right;
		}
		else break;
	}
	return succ;
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

	cout<<"Successor of "<< t->val<<": ";
	node *succ = inorderSuccessor(root, t);
	cout<<succ->val<<endl;

	system("pause");
	return 0;
}