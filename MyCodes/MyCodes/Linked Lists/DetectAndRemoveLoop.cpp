/**
Detect and Remove Loop in a Linked List
Write a function detectAndRemoveLoop() that checks whether a given Linked List 
contains loop and if loop is present then removes the loop and returns true. 
And if the list doesn’t contain loop then returns false. Below diagram shows 
a linked list with a loop. 
detectAndRemoveLoop() must change the below list to 1->2->3->4->5->NULL.
 1->2->3
	  ^  |
		|  v
	  5<-4
http://www.geeksforgeeks.org/archives/12225
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

node *detectLoop(node *head)
{
	if(head == NULL || head->next == NULL) return NULL;

	node *a = head, *b = head;

	do
	{
		cout<<"A: "<<a->val<<" B: "<<b->val<<endl;
		a = a->next;
		b = b->next->next;
	} while(a && b && a != b);

	return a;
}

void removeLoop(node *head, node *loopBeginning)
{
	while(head)
	{
		if(head == loopBeginning)
		{
			head->next = NULL;
		}

		head = head->next;
	}
}

int main()
{
	int a[] = {5,4,3,2,1};
	int n = 5;

	node *head = NULL;
	for(int i=0; i<n; i++) insert(head, a[i]);

	cout<<"List: ";
	print(head);
	cout<<endl;

	cout<<head->next->next->next->next->val<<endl;
	cout<<head->next->val<<endl;

	head->next->next->next->next->next = head->next;

	node *loopHead = detectLoop(head);

	if(loopHead) cout<<"LoopHead: "<<loopHead->val<<endl;

	removeLoop(head, loopHead);

	cout<<"List: ";
	print(head);
	cout<<endl;

	system("pause");
	return 0;
}
