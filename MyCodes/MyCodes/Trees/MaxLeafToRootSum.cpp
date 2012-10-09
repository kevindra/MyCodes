/**
* Find the maximum sum leaf to root path in a Binary Tree
* Given a Binary Tree, find the maximum sum path from a leaf to root.
*
* http://www.geeksforgeeks.org/archives/18722
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

int maxRootToLeafSum(node *root)
{
	if(root == NULL) return 0;

	return max( maxRootToLeafSum(root->left), maxRootToLeafSum(root->right) ) + root->val;
}

int maxRootToLeafSumWithPath(node *root)
{
	if(root == NULL) return 0;

	// get the max sum of the left sub tree 
	int maxLeft = maxRootToLeafSumWithPath(root->left);

	// get the max sum of the right sub tree
	int maxRight = maxRootToLeafSumWithPath(root->right);

	if(maxLeft < maxRight)
	{
		if(root->right) cout<< root->right->val << " -> ";
		return root->val + maxRight;
	}
	else
	{
		if(root->left) cout<< root->left->val <<" -> ";
		return root->val + maxLeft;
	}

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

	cout<<"Max root to leaf sum: "<< maxRootToLeafSum(root) << endl;

	cout<<"Path: " << root->val <<" -> ";
	int maxSum = maxRootToLeafSumWithPath(root);

	cout<<"Max Sum: " << maxSum << endl;

	system("pause");
	return 0;
}