/**
Write a method to replace all spaces in a string with ‘%20’.
*/
#include <iostream>
#include <string>

using namespace std;

char *replaceSpaces(char *s)
{
	int spaces = 0;
	char *tmp = s;
	while(*tmp) {
		if(*tmp == ' ') spaces++;
		tmp++;
	}

	int newLength = strlen(s) + 2*spaces;

	tmp = s;
	int j = strlen(s)-1;
	for(int i=newLength; i>=0; )
	{
		if(i==newLength)	{	*(tmp+i) = '\0'; --i; }
		else if(*(tmp+j) == ' ')
		{
			*(tmp+i) = '0';
			*(tmp+i-1) = '2';
			*(tmp+i-2) = '%';
			i-=3;
			j-=1;
		}
		else
		{
			*(tmp+i) = *(tmp+j);
			--i, --j;
		}
	}
	return s;
}

int main()
{
	char *s = new char;
	cin.getline(s, 20);

	cout<<"\""<<s<<"\""<<endl;

	cout<<"After replacing spaces with %20 :\n \""<<replaceSpaces(s)<<"\""<<endl;

	system("pause");
	return 0;
}