/**
* Merge two BSTs with limited extra space
* Given two Binary Search Trees(BST), print the elements of both BSTs in sorted form. 
* The expected time complexity is O(m+n) where m is the number of nodes in first tree and n is the number of nodes in second tree.
* Maximum allowed auxiliary space is O(height of the first tree + height of the second tree).
*/
#include<iostream>

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

	node *succ = NULL;
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

/**
* O((m+n)*log(m+n))
*/
void combinedInorder(node *r1, node *r2)
{
	node *n1 = getMin(r1);
	node *n2 = getMin(r2);

	while(n1 != NULL || n2 != NULL)
	{
		if(n1 == NULL) { 
			cout<<n2->val<<" -> "; 
			n2 = inorderSuccessor(r2, n2);
			continue; 
		}
		if(n2 == NULL) { 
			cout<<n1->val<<" -> "; 
			n1 = inorderSuccessor(r1, n1);
			continue; 
		}

		if(n1->val < n2->val)
		{
			cout<<n1->val<<" -> ";
			n1 = inorderSuccessor(r1, n1);
		}
		else
		{
			cout<<n2->val<<" -> ";
			n2 = inorderSuccessor(r2, n2);
		}
	}
}

int main()
{
	int a1[] = {10,5,7,11,6};
	int n1 = 5;
	int a2[] = {7,8,9};
	int n2 = 3;

	node *root1 = NULL;
	for(int i=0; i<n1; i++) insert(root1, a1[i]);

	node *root2 = NULL;
	for(int i=0; i<n2; i++) insert(root2, a2[i]);

	cout<<"Inorder1 : " ;
	inorder(root1);
	cout<<endl;

	cout<<"Inorder2 : " ;
	inorder(root2);
	cout<<endl;

	cout<<"Combined Inorder: ";
	combinedInorder(root1, root2);
	cout<<endl;

	system("pause");
	return 0;
}