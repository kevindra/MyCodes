/**
Given a Singly Linked List, write a function to delete a given node. Your function must follow following constraints:
1) It must accept pointer to the start node as first parameter and node to be deleted as second parameter i.e., pointer to head node is not global.
2) It should not return pointer to the head node.
3) It should not accept pointer to pointer to head node.

http://www.geeksforgeeks.org/archives/15663
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
	np->next = NULL;
	np->val	=	val;
	return np;
}

void insert(node *&root, int val)
{
	if(root == NULL) {	root = createNewNode(val); return; }

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

void deleteNode(node *start, node *toDelete)
{
	// if the given node is the start node
	if(start == toDelete)
	{
		start->val = start->next->val;
		toDelete = start->next;
		start->next = start->next->next;

		delete toDelete; 
		return;
	}

	while(start && start->next != toDelete)
	{
		start = start->next;
	}

	// No such node exists in the linked list
	if(start == NULL) return;

	start->next = toDelete->next;
	delete toDelete;
}

int main()
{
	int a[] = {5,4,3,2,1};
	int n = 5;

	node *head = NULL;
	for(int i=0; i<n; i++) insert(head, a[i]);

	cout<<"Linked list: ";
	print(head);
	cout<<endl;

	deleteNode(head, head);

	cout<<"Linked list: ";
	print(head);
	cout<<endl;

	system("pause");
	return 0;
}