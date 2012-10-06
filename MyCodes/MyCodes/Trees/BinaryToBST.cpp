/**
* Binary Tree to Binary Search Tree Conversion
* Given a Binary Tree, convert it to a Binary Search Tree. The conversion must be done in such a way that keeps the original structure of Binary Tree.
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

void inorder(node *root)
{
	if(root == NULL) return;

	inorder(root->left);
	cout<<root->val<<" -> ";
	inorder(root->right);
}

int countNodes(node *root)
{
	if(root == NULL) return 0;

	return countNodes(root->left) + countNodes(root->right) + 1;
}

void storeInorder(node *root, int *a, int &i)
{
	if(root == NULL) return;
	storeInorder(root->left, a, i);
	a[i++] = root->val;
	storeInorder(root->right, a, i);
}

void convertToBST(node *root, int *a, int &i)
{
	if(root == NULL) return;

	convertToBST(root->left, a, i);
	root->val = a[i++];
	convertToBST(root->right, a, i);
}

int main()
{
	node *root = createNewNode(10);
	root->left = createNewNode(2);
	root->right = createNewNode(7);
	root->left->left = createNewNode(8);
	root->left->right = createNewNode(4);

	inorder(root);
	
	// count the number of nodes
	int nodes = countNodes(root);
	cout << "No. of nodes: " << nodes << endl;

	// create an array to store the inorder of the tree
	int *a = new int[nodes];
	int  i=0;
	storeInorder(root, a, i);

	sort(a, a+nodes);

	i=0;
	convertToBST(root, a, i);

	cout<<"BST now: ";
	inorder(root);
	cout<<endl;

	system("pause");
	return 0;
}