/**
*	Construct Special Binary Tree from given Inorder traversal
* Given Inorder Traversal of a Special Binary Tree in which key of every node is greater than keys in left and right children, construct the Binary Tree and return root.
*	For Example: 1,5,10,40,30,15,28,20
*
       40
      / \
    10  30
   /     \
  5      28
 /      / \
1     15  20
*/
#include <iostream>
#include <algorithm>

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

int getMax(int a[], int s, int e)
{
	int maxI = s;
	for(int i=s; i<=e; i++)
		if(a[i] > a[maxI]) maxI = i;
	return maxI;
}

node *buildTree(int a[], int s, int e)
{
	if(s>e) return NULL;

	int maxI = getMax(a, s, e);

	node *root = createNewNode(a[maxI]);
	
	if(s == e) return root;

	root->left = buildTree(a, s, maxI-1);
	root->right = buildTree(a, maxI+1, e);

	return root;
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
	int a[] = {1,5,10,40,30,15,28,20};
	int n = 8;
	
	node *root = buildTree(a, 0, n-1);

	inorder(root);

	system("pause");
	return 0;
}