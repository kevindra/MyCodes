/**
How would you design a stack which, in addition to push and pop, 
also has a function min which returns the minimum element? 
Push, pop and min should all operate in O(1) time.
*/
#include <iostream>

using namespace std;

struct node
{
	int val;
	int minTillNow;
	node *bottom;
};

node *createNewNode(int val)
{
	node *np = new node;
	np->val = val;
	np->minTillNow = INT_MAX;
	np->bottom = NULL;
	return np;
}

void push(node *&top, int val)
{
	if(top == NULL) {	top	=	createNewNode(val); top->minTillNow = val; return; }

	node *np = createNewNode(val);
	np->minTillNow = min(np->val, top->minTillNow);
	np->bottom	=	top;
	top = np;
}

void pop(node *&top)
{
	if(top == NULL) return;

	node *toDelete = top;
	top = top->bottom;
	delete toDelete;
}

node *getTop(node *top)
{
	return top;
}

int getMin(node *top)
{
	if(top == NULL) return INT_MAX;
	return top->minTillNow;
}

void print(node *top)
{
	if(top == NULL) return;
	cout<<top->val<<" ";
	print(top->bottom);
}

int main()
{
	int a[] = {9,2,4,4,6,2,4,1,3,8}, n = 10;

	node *top = NULL;
	for(int i=0; i<n; i++) push(top, a[i]);

	cout<<"Stack: "<<endl;
	print(top);
	cout<<endl;

	cout<<"min: "<<getMin(top)<<endl;
	
	pop(top);

	cout<<"min: "<<getMin(top)<<endl;

	system("pause");
	return 0;
}