/**
* ZigZag/Spiral traversal
* This solution is written without queue/stack
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

// 0 means left to right direction , 1 means right to left
void printLevel(node *root, int level, int direction)
{
	if(root == NULL) return;

	if(level == 0)
	{
		cout<<root->val<<" -> "; return;
	}

	if(direction == 0)
	{
		printLevel(root->left, level-1, direction);
		printLevel(root->right, level-1, direction);
	}
	else
	{
		printLevel(root->right, level-1, direction);
		printLevel(root->left, level-1, direction);
	}
}

int height(node *root)
{
	if(root == NULL) return 0;

	return max( height(root->left), height(root->right) ) + 1;
}

void zigzag(node *root)
{
	int h = height(root);

	int dir = 0;
	for(int i=0; i<h; i++)
	{
		printLevel(root, i, dir);
		dir = (dir+1)%2;
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

	cout<<"Level: ";
	printLevel(root, 2, 1);
	cout<<endl;

	cout<<"Height: "<<height(root);
	cout<<endl;

	cout<<"Zigzag: ";
	zigzag(root);
	cout<<endl;

	system("pause");
	return 0;
}