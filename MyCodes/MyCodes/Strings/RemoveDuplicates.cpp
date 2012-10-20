/**
Design an algorithm and write code to remove 
the duplicate characters in a string without using any additional buffer. 
NOTE: One or two additional variables are fine. An extra copy of the array is not.
*/
#include <iostream>

using namespace std;

char *removeDuplicates(char *s)
{
	int bits = 0;

	int newLength = 0;
	char *result = s;
	char *curr = s;
	while(*curr)
	{
		if( (bits & (1<<(*curr-'a')) ) > 0)
		{
			curr++;
		}
		else
		{
			*result = *curr;
			bits |= (1 <<(*curr -'a'));
			curr++, result++;
			newLength++;
		}
	}

	*(s+newLength) = '\0';
	return s;
}

int main()
{
	char *s = new char;
	cin>>s;

	char *result = removeDuplicates(s);

	cout<<"After removing duplicates: \""<<result<<"\""<<endl;

	system("pause");
	return 0;
}