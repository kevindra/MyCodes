#include <iostream>

using namespace std;

// Tree Node Structure
struct treenode
{
	int val;
	treenode *left, *right;
};

// Linked List Structure
struct listnode
{
	int val;
	listnode *next;
};

// creates a new treenode 
treenode *createNewTreeNode(int val)
{
	treenode *np = new treenode;
	np->left = NULL;
	np->right = NULL;
	np->val = val;

	return np;
}

// creates a new listnode
listnode *createNewListNode(int val)
{
	listnode *np = new listnode;
	np->val = val;
	np->next = NULL;
	return np;
}

// insert in tree
void insertInTree(treenode *&root, int val)
{
	if(root == NULL) { root = createNewTreeNode(val); return; }

	if(val < root->val)	insertInTree(root->left, val);
	else insertInTree(root->right, val);
}

// insert at the beginning of linked list
void insertInList(listnode *&root, int val)
{
	if(root == NULL) { root = createNewListNode(val); return; }

	listnode *np = createNewListNode(val);
	np->next = root;
	root = np;
}

// print the tree
void inorderTree(treenode *root)
{
	if(root == NULL) return;

	inorderTree(root->left);
	cout<<root->val<<" ";
	inorderTree(root->right);
}

// print the list
void printList(listnode *root)
{
	if(root == NULL) return;

	cout<<root->val<<" ";
	printList(root->next);
}

// ----------------------------------------------------------------------------
// METHOD 1
// Use divide and conquer
// Keep getting middle node of the linked list and pushing it in the tree
// Time Complexity: O(nLogn)
// ----------------------------------------------------------------------------

// Gets the ith node of the linked list
listnode *getListNode(listnode *root, int i)
{
	if(root == NULL) return root;
	if(i == 0) return root;

	return getListNode(root->next, i-1);
}

// uses divide and conquer technique to create the tree
treenode *sortedListToBST1(listnode *listroot, int s, int e)
{
	if(s > e) return NULL;

	// get the mid index of the list
	int mid = (s+e+1)/2;
	listnode *midlist = getListNode(listroot, mid);

	treenode *treeroot = NULL;
	treeroot	= createNewTreeNode( midlist->val );

	// set the left and right child of the current tree node
	treeroot->left = sortedListToBST1(listroot, s, mid-1);
	treeroot->right = sortedListToBST1(listroot, mid+1, e);
	return treeroot;
}

// ----------------------------------------------------------------------------
//	METHOD 2
//	Bottom up approach 
//	This method generates leaves first 
//	Then their parents n so on
//	Time Complexity : O(n)
// ----------------------------------------------------------------------------

// count the no. of nodes in the list
int countListNodes(listnode *listroot)
{
	if(listroot == NULL) return 0;

	return countListNodes(listroot->next) + 1;
}

// traverse the list in inorder traversal
// keep the reference of a pointer to the list
// increase it to "next" every time you insert 
// the node to the tree
treenode *sortedListToBST2Inner(listnode *&listroot, int nodes)
{
	// return NULL if nodes become 0
	if(nodes <= 0) return NULL;

	// initialize root to null
	treenode *treeroot = NULL;
	
	// store the left child reference 
	treenode *treeleft = sortedListToBST2Inner(listroot, nodes/2);

	// insert the current list node value to tree 
	// and store it in tree root
	treeroot = createNewTreeNode(listroot->val);

	// store the left child reference which we get from above 
	// to treeroot->left
	treeroot->left = treeleft;

	// increment the listroot
	// remember it is passed by reference above in function parameters
	listroot = listroot->next;

	// -1 is because everytime we are adding one node to the tree.
	// so the no. of left nodes left to get processed are nodes/2 and right nodes are (nodes - nodes/2) - 1 
	treeroot->right = sortedListToBST2Inner(listroot, nodes-(nodes/2)-1); 

	// return the treeroot
	return treeroot;
}

treenode *sortedListToBST2(listnode *listroot)
{
	// count the number of nodes in the list
	int nodes = countListNodes(listroot);

	listnode *templistroot = listroot;
	treenode *treeroot = sortedListToBST2Inner(templistroot, nodes);

	return treeroot;
}

int main()
{
	int a[] = {7,6,5,4,3,2,1};
	int n = 7;

	listnode *listroot = NULL;
	for(int i=0; i<n; i++) insertInList(listroot, a[i]);

	//treenode *treeroot = sortedListToBST1(listroot, 0, n-1);

	treenode *treeroot	=	sortedListToBST2(listroot);

	cout<<"BST Constructed is: ";
	inorderTree(treeroot);
	cout<<endl;

	system("pause");
	return 0;
}