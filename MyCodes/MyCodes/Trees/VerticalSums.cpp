/**
* Vertical Sum in a given Binary Tree
* Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines.
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

void findMaxLeftRightSpan(node *root, int actualLeft, int actualRight, int &maxLeft, int &maxRight)
{
	if(root == NULL) return;

	maxLeft = max(maxLeft, actualLeft);
	maxRight = max(maxRight, actualRight);

	findMaxLeftRightSpan(root->left, actualLeft+1, actualRight, maxLeft, maxRight);
	findMaxLeftRightSpan(root->right, actualLeft, actualRight+1, maxLeft, maxRight);
}

void findVerticalSums(node *root, int index, int maxLeft, int *&sum)
{
	if(root == NULL) return;

	sum[maxLeft+index] += root->val;

	findVerticalSums(root->left, index-1, maxLeft, sum);
	findVerticalSums(root->right, index+1, maxLeft, sum);
}

int main()
{
	/*
				1
			/   \
		2      3
	 / \    / \
	4   5  6   7
	*/

	node *root = createNewNode(1);
	root->left = createNewNode(2);
	root->right = createNewNode(3);
	root->left->left = createNewNode(4);
	root->left->right = createNewNode(5);
	root->right->left = createNewNode(6);
	root->right->right = createNewNode(7);

	cout<<"Inorder: ";
	inorder(root);
	cout<<endl;

	int maxLeft=0, maxRight=0;
	findMaxLeftRightSpan(root, 0, 0, maxLeft, maxRight);

	cout<<"max left, right: "<<maxLeft<<" "<<maxRight<<endl;

	int arrSize = maxLeft+maxRight+1;
	int *sum = new int[arrSize];
	sum = (int*) calloc(arrSize, sizeof(sum));

	findVerticalSums(root, 0, maxLeft, sum);

	for(int i=0; i<arrSize; i++)
	{
		cout<<i<<": "<<sum[i]<<endl;
	}

	system("pause");
	return 0;
}