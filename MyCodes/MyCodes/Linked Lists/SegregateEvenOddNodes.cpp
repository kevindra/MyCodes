/**
	Segregate even and odd nodes in a Linked List

	Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.

	Examples:
	Input: 17->15->8->12->10->5->4->1->7->6->NULL
	Output: 8->12->10->4->6->17->15->5->1->7->NULL
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

void segregateEvenOdd(node *&head)
{
	if(head == NULL) return;

	node *tempHead = head;
	node *evenTail = NULL;
	
	if(tempHead->val%2 == 0) evenTail = tempHead;

	while(tempHead && tempHead->next)
	{
		if(tempHead->next->val % 2 == 0)
		{
			if(evenTail == NULL)
			{
				node *evenNode = tempHead->next;
				tempHead->next = tempHead->next->next;
				evenNode->next = head;
				head = evenNode;
				evenTail = evenNode;
			}
			else
			{
				node *evenNode = tempHead->next;
				tempHead->next = tempHead->next->next;
				evenNode->next = evenTail->next;
				evenTail->next = evenNode;
				evenTail = evenNode;
			}
		}
		else tempHead = tempHead->next;
	}
}

int main()
{
	int a[] = {6,7,1,4,5,10,12,8,15,17};
	int n = 10;
	 
	//int a[] = {1, 3, 4};
	//int n = 3;

	node *head = NULL;
	for(int i=0; i<n; i++) insert(head, a[i]);

	cout<<"Linked List: ";
	print(head);
	cout<<endl;

	segregateEvenOdd(head);

	cout<<"Linked List: ";
	print(head);
	cout<<endl;

	system("pause");
	return 0;
}