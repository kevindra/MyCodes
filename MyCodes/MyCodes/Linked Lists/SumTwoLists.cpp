/**
	Add two numbers represented by linked lists

	Given two numbers represented by two lists, write a function that returns sum list. 
	The sum list is list representation of addition of two input numbers.

	Input:
  First List: 5->6->3  // represents number 365
  Second List: 8->4->2 //  represents number 248

	Output:
  Resultant list: 3->1->6  // represents number 613

	http://www.geeksforgeeks.org/archives/15194
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

node *sumLL(node *head1, node *head2, int carry)
{
	if(carry == 0 && head1 == NULL && head2 == NULL) return NULL;

	int head1Dig = head1?head1->val:0;
	int head2Dig = head2?head2->val:0;

	int digit = (head1Dig + head2Dig + carry)%10;
	int newCarry = (head1Dig + head2Dig + carry)/10;

	node *np = createNewNode(digit);
	
	np->next = sumLL(
							head1?head1->next:head1, 
							head2?head2->next:head2, 
							newCarry);

	return np;
}

int main()
{
	int a[] = {3,6,5,9};
	int n1 = 4;

	int b[] = {2,4,8};
	int n2 = 3;

	node *head1=NULL, *head2=NULL;
	for(int i=0; i<n1; i++) insert(head1, a[i]);
	for(int i=0; i<n2; i++) insert(head2, b[i]);

	cout<<"List1: ";
	print(head1);
	cout<<endl;

	cout<<"List2: ";
	print(head2);
	cout<<endl;

	node *sumHead = sumLL(head1, head2, 0);

	cout<<"Sum List: ";
	print(sumHead);
	cout<<endl;

	system("pause");
	return 0;
}