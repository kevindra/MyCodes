/**
	union of two sorted linked lists
*/
#include <iostream>

using namespace std;

struct node
{
	int val;
	node *next;
};

node *createNewNode(int n)
{
	node *np = new node;
	np->val= n;
	np->next = NULL;
	return np;
}

void insertAtBeginning(node *&root, int val)
{
	if(root == NULL) { root=createNewNode(val); return; } 

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

node *intersectionLL(node *root1, node *root2, node *lastChosen)
{
	if(root1 == NULL || root2 == NULL) 
		return NULL;

	if(root1->val < root2->val)
	{
		return intersectionLL(root1->next, root2, lastChosen);
	}

	if(root1->val > root2->val)
	{
		return intersectionLL(root1, root2->next, lastChosen);
	}

	// if both root1 and root2 values are same
	// but already is in the result set
	// then we simply ignore that 
	if(lastChosen && root1->val == lastChosen->val)
	{
		return intersectionLL(root1->next, root2->next, lastChosen);	
	}

	// if both root1 and root2 values are same
	// and is not is the result set yet
	// we add it to the result set and return the result node
	node *result = root1;
	result->next = intersectionLL(root1->next, root2->next, root1);
	return result;
}

int main()
{
	int a1[] = {5,4,2,1};
	int n1 = 4;

	int a2[] = {12,10,6,5,5,2};
	int n2 = 6;

	node *root1 = NULL, *root2 = NULL;
	for(int i=0; i<n1; i++) insertAtBeginning(root1, a1[i]);
	for(int i=0; i<n2; i++) insertAtBeginning(root2, a2[i]);

	cout<<"Linked Lists: "<<endl;
	print(root1);
	cout<<endl;
	print(root2);
	cout<<endl;

	node *lastChosen = NULL;
	node *intersectionll = intersectionLL(root1, root2, lastChosen);

	cout<<"Intersection List: ";
	print(intersectionll);
	cout<<endl;

	system("pause");
	return 0;
}