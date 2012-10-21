/**
	Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height.
*/
#include <iostream>
#include <algorithm>
#include <list>

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

// solution using queue
node *arrayToBinaryTree(int *a, int n)
{
	node *root = NULL;
	root = createNewNode(a[0]);

	list<node*> q;
	q.push_back(root);

	int i=1;
	while(!q.empty())
	{
		node *curr = q.front();
		q.pop_front();

		if(i < n)
		{
			curr->left = createNewNode(a[i]);
			q.push_back(curr->left);
		}

		if(i+1 < n) 
		{
			curr->right = createNewNode(a[i+1]);
			q.push_back(curr->right);
		}

		i+=2;
	}

	return root;
}

// solution without queue
node *arrayToBinaryTreeWithoutQueue(int *a, int s, int e)
{
	if(s > e) return NULL;

	int mid = (s+e)/2;
	node *np = new node;
	np->left = arrayToBinaryTreeWithoutQueue(a, s, mid-1);
	np->val = a[mid];
	np->right = arrayToBinaryTreeWithoutQueue(a, mid+1, e);
	return np;
}

int main()
{
	int a[] = {20,10,30,11,29,31,13,12};
	int n = 8;

	sort(a, a+n);

	cout<<"Array: "<<endl;
	for(int i=0; i<n; i++) cout<<a[i]<<" ";
	cout<<endl;

	node *root = arrayToBinaryTree(a, n);

	cout<<"Inorder: "<<endl;
	inorder(root);
	cout<<endl;

	node *root2 = arrayToBinaryTreeWithoutQueue(a, 0, n-1);

	cout<<"Inorder: "<<endl;
	inorder(root2);
	cout<<endl;

	system("pause");
	return 0;
}