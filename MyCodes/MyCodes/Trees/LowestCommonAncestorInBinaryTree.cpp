#include <iostream>

using namespace std;

struct node
{
	int val;
	node *left, *right;
};

node *createNewNode(int val)
{
	node *np = new node;
	np->val = val;
	np->left = NULL;
	np->right = NULL;
	return np;
}

void insert(node *&root, int val)
{
	if(root == NULL) { root = createNewNode(val); return; }

	if(val < root->val) insert(root->left, val);
	else insert(root->right, val);
}

// method 1 : without parent link
// Using isAChild method
bool isAChild(node *root, node *n)
{
	if(root == NULL) return false;
	if(root == n) return true;

	return isAChild(root->left, n) || isAChild(root->right, n);
}

node *commonAncestor(node *root, node *a, node *b)
{
	if(root == NULL) return NULL;
	if(isAChild(root->left,a) && isAChild(root->left,b))
		return commonAncestor(root->left, a, b);
	if(isAChild(root->right,a) && isAChild(root->right, b))
		return commonAncestor(root->right, a, b);
	return root;
}

void inorder(node *root)
{
	if(root == NULL) return;

	inorder(root->left);
	cout<<root->val<<" -> ";
	inorder(root->right);
}

// O(n) solution
// bottom up approach
char commonAncestor2(node *root, node *p, node *q, node *&result)
{
	if(root == NULL) return 'N'; // none

	char directionLeft = commonAncestor2(root->left, p, q, result);
	char directionRight = commonAncestor2(root->right, p, q, result);

	cout<<root->val<<": left: "<<directionLeft<<", right: "<<directionRight<<endl;

	// if current node is 'P' return 'P'
	if( root == p && (directionLeft == 'Q' || directionRight == 'Q')) 
	{ 
		result = root; 
		return 'B'; 
	}

	if( root == p )	return 'P';

	if( root == q && (directionLeft == 'P' || directionRight == 'P') )
	{
		result = root;
		return 'B';
	}

	// if current node is 'Q' return 'Q'
	if( root == q ) return 'Q';

	// if left subtree has 'P' and right subtree has 'Q' 
	// OR vice versa
	// in this case we store root as result
	if( (directionLeft == 'P' && directionRight == 'Q') 
				|| (directionLeft == 'Q' && directionRight == 'P') ) 
	{
		result = root;
		return 'B';
	}

	// if left OR right subtree has 'P' 
	if(directionLeft == 'P' || directionRight == 'P') return 'P';

	// if left OR right subtree has 'Q'
	if(directionLeft == 'Q' || directionRight == 'Q') return 'Q';

	// if left OR right subtree has both 'P' and 'Q'
	if( directionLeft == 'B' || directionRight == 'B' ) return 'B';

	return 'N';
}

int main()
{
	int a[] = {20,15,27,11,17,21,28,10,12,16,23,13,24};
	int n = 13;

	node *root = NULL;
	for(int i=0; i<n; i++) insert(root, a[i]);

	cout<<"Inorder: ";
	inorder(root);
	cout<<endl;

	node *n1, *n2;
	n1 = root->left->left->left;
	n2 = root->right->left->right->right;

	node *lcm = commonAncestor(root, n1, n2);

	cout<<"common ancestor of "<<n1->val<<" and "<<n2->val<<": "<<lcm->val<<endl;


	node *result = NULL;

	commonAncestor2(root, n1, n2, result);

	if(result != NULL)
		cout<<"common ancestor method 2: "<< result->val<<endl;
	else cout<<"NULL!"<<endl;

	system("pause");
	return 0;
}