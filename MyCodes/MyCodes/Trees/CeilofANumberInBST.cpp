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

/**
Ceil Value Node: Node with smallest data larger than or equal to key value.

Imagine we are moving down the tree, and assume we are root node. 
The comparison yields three possibilities,

A) Root data is equal to key. We are done, root data is ceil value.

B) Root data < key value, certainly the ceil value can’t be in left subtree. 
		Proceed to search on right subtree as reduced problem instance.

C) Root data > key value, the ceil value may be in left subtree. 
		We may find a node with is larger data than key value in left subtree, 
		if not the root itself will be ceil node.
*/
int Ceil(node *root, int num)
{
	if(root == NULL) return -1;

	if(root->val == num) return root->val;

	if(root->val < num) return Ceil(root->right, num);

	int ceil = Ceil(root->left, num);
	return (ceil>=num) ? ceil:root->val;
}

int main()
{
	int a[] = {11,5,12,4,6,15,5,9};
	int n = 8;

	node *root = NULL;
	for(int i=0; i<n; i++) insert(root, a[i]);

	cout<<"Inorder: ";
	inorder(root);
	cout<<endl;
	
	int num = 8; 
	cout<<"Ceil of "<<num<<": "<< Ceil(root, num) <<endl;


	system("pause");
	return 0;
}