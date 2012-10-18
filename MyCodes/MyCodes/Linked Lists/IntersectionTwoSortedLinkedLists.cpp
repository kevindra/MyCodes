/**
	Intersection of two sorted linked lists
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

node *merge(node *root1, node *root2)
{
	if(root1 == NULL)
	{
		return root2;
	}

	if(root2 == NULL)
	{
		return root1;
	}

	node *result =  NULL;
	if(root1->val < root2->val)
	{
		result = root1;
		result->next = merge(root1->next, root2);
	}
	else
	{
		result = root2;
		result->next = merge(root1, root2->next);
	}
	return result;
}

node *intersectionLL(node *root1, node *root2, node *lastChosen)
{
	// if both the roots are null return NULL
	if(root1 == NULL && root2 == NULL) return NULL;

	// if root1 has become/is null 
	// we check if the lastChosen and next node from LL2 is same
	// if they are same, we skip and increment pointer in LL2
	// otherwise, we store it in a node and return the node
	if(root1 == NULL)
	{
		// check if lastChose and current root2->val are same
		if(lastChosen && root2->val == lastChosen->val)
		{
			// if same skip root2, just increment it without choosing root2 node
			return intersectionLL(root1, root2->next, lastChosen);
		}
		
		// if not same 
		// store it in result 
		node *result = root2;
		
		// fill the next of result recursively
		result->next	= intersectionLL(root1, root2->next, root2);

		// return the result
		return result;
	}

	// same if root 2 is null
	// we compare root1 current value and lastChosen value
	if(root2 == NULL)
	{
		// if root1 current value and lastChosen value are same
		if(lastChosen && root1->val == lastChosen->val)
		{
			// we skip the node and increment root1
			return intersectionLL(root1->next, root2, lastChosen);
		}

		// otherwise we store it in the result and return it
		node *result = root1;

		// fill the next of result recursively
		result->next = intersectionLL(root1->next, root2, root1);

		// return the result
		return result;
	}

	// this condition is to check 
	// if lastChose and root1 current value are same
	if(lastChosen && root1->val == lastChosen->val)
	{
		// if they are same just skip root1 current value
		return intersectionLL(root1->next, root2, lastChosen);
	}

	// if last chosen and current root2 value are same
	if(lastChosen && root2->val == lastChosen->val)
	{
		// skip root2 current value, don't store it in the result
		return intersectionLL(root1, root2->next, lastChosen);
	}

	// In all other cases, we store the value in result 
	// and return the result
	node *result = NULL;
	if(root1->val < root2->val)
	{
		result = root1;
		result->next = intersectionLL(root1->next, root2, root1);
	}
	else
	{
		result = root2;
		result->next = intersectionLL(root1, root2->next, root2);
	}
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

	//node *mergedList = merge(root1, root2);

	//cout<<"Merged List: ";
	//print(mergedList);
	//cout<<endl;

	node *lastChosen = NULL;
	node *intersection = intersectionLL(root1, root2, lastChosen);

	cout<<"Intersection List: ";
	print(intersection);
	cout<<endl;

	system("pause");
	return 0;
}