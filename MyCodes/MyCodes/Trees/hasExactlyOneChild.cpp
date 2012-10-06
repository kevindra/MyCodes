/**
* Check if each internal node of a BST has exactly one child
* Given Preorder traversal of a BST, check if each non-leaf node has only one child. Assume that the BST contains unique entries.
*/
#include <iostream>

using namespace std;

/**
* Approach:
* Since all the descendants of a node must either be larger or smaller than the node. We can do following for every node in a loop.
*	1. Find the next preorder successor (or descendant) of the node.
*	2. Find the last preorder successor (last element in pre[]) of the node.
*	3. If both successors are less than the current node, or both successors are greater than the current node, then continue. Else, return false.
*/
bool check(int a[], int n)
{
	int max = a[n-1];

	for(int i=0; i<n-1; i++)
	{
		if( (a[i] < a[i+1] && a[i] > a[n-1]) || (a[i] > a[i+1] && a[i] < a[n-1]) )	return false; 
	}
	return true;
}

int main()
{
	int a[] = {20,10,11,13,12};
	int n = 5;

	cout<< (check(a,n) ? "Yes":"No") <<endl;

	system("pause");
	return 0;
}