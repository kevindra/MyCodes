/**
*	Remove unnecessary spaces from a given string. 
* For example: if input is " A B   CDE F" , 
* your output should be "ABCDEF"
*/

#include <iostream>
#include <string>

using namespace std;

/**
* Method 1 : Using another string
* Time complexity: O(n)
* Space complexity: O(n)
*/
string removeSpacesMethod1(string s)
{
	string s2 = "";
	bool extraSpace = true;
	for(int i=0; i<s.size(); i++)
		if(s[i] == ' ' && !extraSpace)  extraSpace = true;
		else if(s[i] == ' ') continue;
		else s2 += s[i];
		
	return s2;
}

int main()
{
	string s = " A B   CDE  F   ";

	string output = removeSpacesMethod1(s);
	cout<< "After removing spaces: \"" << output <<"\""<< endl;

	system("pause");
	return 0;
}