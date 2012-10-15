/**
* program to write all possible permutations of a string.
*/

#include <iostream>
#include <string>

using namespace std;

// logic is to swap each index with every index greater than current.
void permute(string s, int i)
{
	if(i == s.size())
	{
		cout<<s<<endl;
		return;
	}

	for(int x=i;  x<s.size(); x++)
	{
		swap(s[i], s[x]);
		permute(s, i+1);
		swap(s[i], s[x]); //backtrack
	}
}

int main()
{
	string s = "abcd";

	permute(s, 0);

	system("pause");
	return 0;
}