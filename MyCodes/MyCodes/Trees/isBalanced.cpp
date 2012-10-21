/**
Implement a function to check if a tree is balanced. 
For the purposes of this question, a balanced tree is defined to be a tree such 
that no two leaf nodes differ in distance from the root by more than one.
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

// idea is to calculate max and min depth of the tree
// and then check if difference is > 1 
// if > 1 means not a balanced tree
int maxDepth(node *root)
{
	if(root == NULL) return 0;

	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int minDepth(node *root)
{
	if(root == NULL) return 0;

	return min(minDepth(root->left), minDepth(root->right)) + 1;
}

bool isBalanced(node *root)
{
	if(root == NULL) return true;

	return (maxDepth(root) - minDepth(root)) <= 1;
}

int main()
{
	int a[] = {5,2,3,1,7,6,8,9};
	int n = 8;

	node *root = NULL;
	for(int i=0; i<n; i++) insert(root, a[i]);

	cout<<"Inorder: ";
	inorder(root);
	cout<<endl;

	cout<<"Is Balanced: "<<isBalanced(root)<<endl;

	system("pause");
	return 0;
}