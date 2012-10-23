#include <iostream>

using namespace std;

void printSubsets(string s)
{
	int n = s.size();

	for(int i=0; i< (1<<s.size()) ; i++)
	{
		cout<<"Subset "<<i+1<<": ";
		for(int j=0; j<n; j++)
		{
			if( (i&(1<<j)) > 0 )
			{
				cout<<s[j]<<" ";
			}
		}
		cout<<endl;
	}
}

int main()
{
	string s = "abc";

	printSubsets(s);

	system("pause");
	return 0;
}