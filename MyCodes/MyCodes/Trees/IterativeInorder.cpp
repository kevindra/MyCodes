/**
*	Iterative Inorder Traversal of a BST
*/
#include <iostream>
#include <vector>

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
* Iterative INORDER
*/ 
void iterativeInorder(node *root)
{
	if(root == NULL) return;

	vector<node*> stack;

	stack.push_back(root);
	node *n = root;
	while(!stack.empty())
	{
		if(n)
		{
			if(n->left) stack.push_back(n->left);
			n = n->left;
		}
		else
		{
			node *t = stack.back();
			stack.pop_back();

			cout<< t->val <<" -> ";

			if(t->right) { stack.push_back(t->right); }
			n = t->right;
		}
	}
}

int main()
{
	int a[] = {20,10,30,11,29,31,13,12};
	int n = 8;

	node *root = NULL;
	for(int i=0; i<n; i++)
	{
		insert(root, a[i]);
	}

	cout<<"Inorder: ";
	inorder(root);
	cout<<endl;

	cout<<"Iterative: ";
	iterativeInorder(root);
	cout<<endl;
	system("pause");
	return 0;
}