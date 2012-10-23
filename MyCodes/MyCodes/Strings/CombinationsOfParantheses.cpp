/**
	Implement an algorithm to print all valid (e.g., properly opened and closed) 
	combinations of n-pairs of parentheses.
	
	EXAMPLE:
	input: 3 (e.g., 3 pairs of parentheses)
	output: ()()(), ()(()), (())(), ((()))
*/
#include <iostream>
#include <string>

using namespace std;

void printCombs(int l, int r, string s)
{
	if(l==0 && r==0) { cout<<s<<endl; return; }

	if(r < l) return;

	// take the left parentheses
	if(l>0) printCombs(l-1, r, s+"(");

	// take the right parentheses
	if(r>0) printCombs(l, r-1, s+")");
}

int main()
{
	// pairs of parantheses given
	int pairs = 3;

	printCombs(pairs, pairs, "");

	system("pause");
	return 0;
}