/**
	Reverse all the words in an string.

	for example : if input is :  "  hello how   are you "
	output should be "  olleh woh   era uoy "
*/
#include <iostream>
#include <string>

using namespace std;


void reverse(string &str, int s, int e)
{
	if(s >= e) return;

	swap(str[s], str[e]);
	reverse(str, s+1, e-1);
}

string reverseWords(string s)
{
	for(int i=0; i<s.length(); )
	{

		if(s[i] != ' ')
		{
			int j = i+1;
			while(j < s.length() && s[j] != ' ') j++;

			reverse(s, i, j-1);
			i = j;
		}
		else i++;
	}

	return s;
}

int main()
{
	string s = "  hello how   are you ";

	cout<<"Input is : \""<<s<<"\" \n";

	cout<<"After reversing the words: \""<< reverseWords(s) << "\"" << endl;

	system("pause");
	return 0;
}