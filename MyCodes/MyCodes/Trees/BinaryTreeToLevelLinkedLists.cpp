/**
	Given a binary search tree, 
	design an algorithm which creates a linked list of all the treenodes at each depth 
	(i.e., if you have a tree with depth D, you’ll have D linked lists).
*/
#include <iostream>
#include <list>

using namespace std;

struct treenode
{
	int val;
	treenode *left, *right;
};

struct listnode
{
	int val;
	listnode *next;
};

treenode *createNewTreetreenode(int val)
{
	treenode *np = new treenode;
	np->val = val;
	np->left = NULL;
	np->right = NULL;
	return np;
}

listnode *createNewListNode(int val)
{
	listnode *np = new listnode;
	np->next = NULL;
	np->val = val;
	return np;
}

void insert(treenode *&root, int val)
{
	if(root == NULL) { root = createNewTreetreenode(val); return; }

	if(val < root->val) insert(root->left, val);
	else insert(root->right, val);
}

void inorder(treenode *root)
{
	if(root == NULL) return;

	inorder(root->left);
	cout<<root->val<<" -> ";
	inorder(root->right);
}

void printList(listnode *head)
{
	if(head == NULL) return;

	cout<<head->val<<" ";
	printList(head->next);
}

int maxDepth(treenode *root)
{
	if(root == NULL) return 0;
	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

void bstToListsInner(treenode *root, listnode **lists, int depth)
{
	if(root == NULL) return;

	bstToListsInner(root->left, lists, depth+1);
	
	if(lists[depth] == NULL) lists[depth] = createNewListNode(root->val);
	else 
	{
		listnode *np = createNewListNode(root->val);
		np->next = lists[depth];
		lists[depth] = np;
	}

	bstToListsInner(root->right, lists, depth+1);
}

void bstTolists(treenode *root)
{
	int d = maxDepth(root);
	listnode **lists = (listnode**) malloc(d*sizeof(listnode));

	for(int i=0; i<d; i++) lists[i] = NULL;

	bstToListsInner(root, lists, 0);

	for(int i=0; i<d; i++)
	{
		cout<<"Linked List: "<<i<<endl;
		printList(lists[i]);
		cout<<endl;
	}
}

int main()
{
	int a[] = {20,15,27,11,17,21,28,10,12,16,23,13,24};
	int n = 13;

	treenode *root = NULL;
	for(int i=0; i<n; i++) insert(root, a[i]);

	cout<<"Inorder: ";
	inorder(root);
	cout<<endl;

	cout<<"Lists: "<<endl;
	bstTolists(root);

	system("pause");
	return 0;
}