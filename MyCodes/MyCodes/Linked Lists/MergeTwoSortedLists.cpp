/**
*	Program to merge two sorted linked lists.
*/
#include <iostream>

using namespace std;

struct node
{
	int val;
	node *next;
};

node *createNewNode(int val)
{
	node *np = new node;
	np->val = val;
	np->next = NULL;
	return np;
}

/** insert a node in the beginning of a linked list  **/
void insert(node *&root, int val)
{
	if(root == NULL) { root = createNewNode(val); return; }
	
	node *np = createNewNode(val);
	np->next = root;
	root = np;
}

void print(node *root)
{
	if(root == NULL) return;

	cout<<root->val<<" ";
	print(root->next);
}

/** take nodes one by one from both the lists - just like MERGE SORT **/
node *merge(node *root1, node *root2)
{
	if(root1 == NULL)
	{
		return root2;
	}

	if(root2 == NULL)
	{
		return root1;
	}

	node *result = NULL;
	if(root1->val > root2->val)
	{
		result = root2;
		result->next = merge(root1, root2->next);
	}
	else
	{
		result = root1;
		result->next = merge(root1->next, root2);
	}
	return result;
}

int main()
{
	int a[] = {30,8,7,5};
	int n = 4;

	node *root1 = NULL;
	for(int i=0; i<n; i++) insert(root1, a[i]);

	cout<<"linked list 1: "<<endl;
	print(root1);
	cout<<endl;

	int b[] = {45,40,35,28,20,10};
	int n2 = 6;

	node *root2 = NULL;
	for(int i=0; i<n2; i++) insert(root2, b[i]);

	cout<<"linked list 2: "<<endl;
	print(root2);
	cout<<endl;

	node *mergedList = merge(root1, root2);

	cout<<"Merged list: "<<endl;
	print(mergedList);
	cout<<endl;

	system("pause");
	return 0;
}