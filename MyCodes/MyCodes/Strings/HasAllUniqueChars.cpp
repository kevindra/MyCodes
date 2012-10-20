/**
Implement an algorithm to determine if a string has all unique characters. 
What if you can not use additional data structures?
*/
#include <iostream>

using namespace std;

// c++ style
bool hasAllUniqueCharacters(char *s)
{
	int bits = 0;

	for(int i=0; i<strlen(s); i++)
	{
		if((bits & (1<<(s[i]-'a'))) > 0) return false;
		bits |= (1<<(s[i]-'a'));
	}
	return true;
}

// c style 
bool hasAllUniqueCharactersCSTYLE(char *s)
{
	int bits = 0;
	while(*s)
	{
		if( (bits & (1 << (*s-'a'))) > 0 ) return false;
		bits |= (1 << (*s-'a'));
		s++;
	}
	return true;
}

int main()
{
	char *str = new char;
	cin>>str;

	cout<<"All unique C++ Style: "<< hasAllUniqueCharacters(str) << endl;

	cout<<"All unique C style: " << hasAllUniqueCharactersCSTYLE(str) << endl;

	system("pause");
	return 0;
}