/**
Reverse a cstyle string
*/

#include <iostream>

using namespace std;

char *reverse(char *s)
{
	char *end = s;
	while(*end) ++end;
	--end;

	char *result = s;
	while(s < end)
	{
		char c = *s;
		*s = *end;
		*end = c;
		s++, end--;
	}
	return result;
}

int main()
{
	char *c = new char;
	cin>>c;

	char *reverseStr = reverse(c);

	cout<<reverseStr<<endl;

	system("pause");
	return 0;
}