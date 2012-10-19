/**
	In place convert a doubly linked list to balanced BST
*/
#include <iostream>

using namespace std;

// I am using the same structure 
// to store both list and tree
struct dll
{
	int val;
	dll *left, *right;
};

// creates new node 
dll *createNewNode(int val)
{
	dll *np = new dll;
	np->val = val;
	np->left = NULL;
	np->right = NULL;
	return np;
}

// inserts in the beginning of the doubly list
void insertInList(dll *&head, dll *&tail, int val)
{
	if(head == NULL) {	head = createNewNode(val); tail = head; return; }

	dll *np = createNewNode(val);
	np->right = head;
	head->left = np;
	head = np;
}

// prints doubly list forward
void printListForward(dll *head)
{
	if(head == NULL) return;
	cout<<head->val<<" ";
	printListForward(head->right);
}

// prints doubly list backward
void printListBackward(dll *tail)
{
	if(tail == NULL) return;
	cout<<tail->val<<" ";
	printListBackward(tail->left);
}

// prints the tree in inorder
void printTreeInorder(dll *root)
{
	if(root == NULL) return;

	printTreeInorder(root->left);
	cout<<root->val<<" ";
	printTreeInorder(root->right);
}

// counts the number of nodes in the list
int countListNodes(dll *head)
{
	if(head == NULL) return 0;

	return countListNodes(head->right) + 1;
}

// method to convert a DLL inplace
dll *doublyListToBSTInner(dll *&head, int nodes)
{
	if(nodes <= 0) return NULL;

	dll *leftChild = doublyListToBSTInner(head, nodes/2);

	dll *currentNode = head;
	currentNode->left = leftChild;

	head = head->right;

	currentNode->right = doublyListToBSTInner(head, nodes - nodes/2 - 1);
	return currentNode;
}

dll *doublyListToBST(dll *head)
{
	int nodes = countListNodes(head);

	dll *tempHead = head;
	dll *treeRoot = doublyListToBSTInner(tempHead, nodes);
	return treeRoot;
}

int main()
{
	int a[] = {7,6,5,4,3,2,1};
	int n = 7;

	dll *head = NULL, *tail = NULL;
	for(int i=0; i<n; i++) insertInList(head, tail, a[i]);

	cout<<"List Forward: ";
	printListForward(head);
	cout<<endl;

	cout<<"List Backward: ";
	printListBackward(tail);
	cout<<endl;

	dll *treeRoot = doublyListToBST(head);

	cout<<"BST Constructed is: ";
	printTreeInorder(treeRoot);
	cout<<endl;
	
	system("pause");
	return 0;
}