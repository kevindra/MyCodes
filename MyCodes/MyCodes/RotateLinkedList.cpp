/**
Rotate a linked list counter-clockwise by k nodes.

For example, if the given linked list is 10->20->30->40->50->60 and k is 4, 
the list should be modified to 50->60->10->20->30->40. 
Assume that k is smaller than the count of nodes in linked list.
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

void insertAtBeginning(node *&root, int val)
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

node *rotateAntiClockwise(node *&root, int k)
{
	if(root == NULL || k == 0) return root;

	node *curr = root;
	while(k-- > 1 && curr)
	{
		curr = curr->next;
	}

	// if k is equal or greater than the 
	// number of nodes in the linked list
	if(curr == NULL) return root;

	node *kthNode = curr;

	while(curr->next)
	{
		curr = curr->next;
	}
	curr->next = root;
	
	root = kthNode->next;
	kthNode->next = NULL;

	return root;
}


int main()
{
	int a[] = {60,50,40,30,20,10};
	int n=6, k=4;

	node *root = NULL;
	for(int i=0; i<n; i++) insertAtBeginning(root, a[i]);

	cout<<"Original Nodes: "<<endl;
	print(root);
	cout<<endl;

	cout<<"After Rotating linked list by k nodes anticlockwise: "<<endl;
	node *head = rotateAntiClockwise(root, k);
	print(head);
	cout<<endl;

	system("pause");
	return 0;
}