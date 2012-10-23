/**
	Write a function to determine the number of bits required to convert integer A to integer B.
	Input: 31, 14
	Output: 2
*/
#include <iostream>

using namespace std;

int getBitsCount(int a, int b)
{
	int count = 0;
	for(int c = a^b; c != 0; c>>=1)
	{
		count += c&1;
	}
	return count;
}

int main()
{
	int a, b;

	a = 31, b = 14;

	cout<<"Bits required to convert "<<a<<" to "<<b<<": "<<getBitsCount(a, b)<<endl;

	system("pause");
	return 0;
}