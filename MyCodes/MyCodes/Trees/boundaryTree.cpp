/**
*	Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root.
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

void printLeftBoundary(node *root)
{
	if(root == NULL) return;

	if(root->left == NULL || root->right == NULL) return;

	cout<<root->val<<" -> ";
	if(root->left)
	{
		printLeftBoundary(root->left);
	}
	else if(root->right)
	{
		printLeftBoundary(root->right);
	}
}

void printLeavesLeftToRight(node *root)
{
	if(root == NULL) return;

	printLeavesLeftToRight(root->left);

	if(root->left == NULL && root->right == NULL) cout<<root->val<< " -> ";

	printLeavesLeftToRight(root->right);
}

void printRightBoundaryBottomUp(node *root)
{
	if(root == NULL) return;

	if(root->left == NULL && root->right == NULL) return;

	if(root->right)
	{
		printRightBoundaryBottomUp(root->right);
	}
	else if(root->left)
	{
		printRightBoundaryBottomUp(root->left);
	}

	cout<<root->val << " -> ";
}

int main()
{
	int a[] = {5,2,4,3,1,8,7,10,9};
	int n = 9;

	node *root = NULL;
	for(int i=0; i<n; i++) insert(root, a[i]);

	inorder(root);
	cout<<endl;

	printLeftBoundary(root);
	printLeavesLeftToRight(root);
	printRightBoundaryBottomUp(root);
	
	system("pause");
	return 0;
}