#include <iostream>
#include <string>

using namespace std;

// from any base to decimal
// keep multiplying the digits of the given number from left to right by base^i 
// and add them 
// number n in base b will be 
// n[0]*b^0 + n[1]*b^1 + n[2]*b^2 + n[3]*b^3 .... so on
// where n[i] are digits from left to right.
int convertBaseBtoDecimal(int n, int fromBase)
{
	int factor = 1;
	int decimal = 0;

	while(n)
	{
		decimal += (n%10)*factor;
		factor*=fromBase;
		n/=10;
	}
	return decimal;
}

// convert decimal to any base
// this will work only for base <= 10
int convertDecimalToBaseB(int n, int toBase)
{
	int result = 0;
	int factor = 1;
	while(n)
	{
		result += (n%toBase)*factor;
		factor*=10;
		n/=toBase;
	}
	return result;
}

// convert decimal to any base (> 10)
string convertDecimalToBaseBString(int n, int toBase)
{
	string s = "0123456789ABCDEFGHIJ";	// 20 length - can support upto base 19
	
	if(toBase >= s.length()) return "";

	string result = "";

	while(n)
	{
		result += s[n%toBase];
		n/=toBase;
	}

	reverse(result.begin(), result.end());

	return result;
}

int main()
{
	int num, fromBase;	

	num=1010110011, fromBase=2;
	cout<<num<<" base "<< fromBase <<" is: "<< convertBaseBtoDecimal(num, fromBase)<< " in decimal base(10)"<<endl;

	int toBase = 2;
	num = 691;
	cout<<num <<" in binary: "<< convertDecimalToBaseB(num , toBase) <<endl;

	num = 200;
	toBase = 16;
	cout<<num<<" in base "<<toBase<<": "<< convertDecimalToBaseBString(num, toBase) <<endl;

	system("pause");
	return 0;
}