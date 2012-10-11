/**
* Maximum Length Chain of Pairs
* You are given n pairs of numbers. In every pair, the first number is always smaller than the second number. 
* A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. 
* Find the longest chain which can be formed from a given set of pairs.
* 
*
* For example, if the given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} }, 
* then the longest chain that can be formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}
*
* http://www.geeksforgeeks.org/archives/23245
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct Pair
{
	int first, second;
};

int compare(Pair a, Pair b)
{
	return a.first < b.first;
}

int maxChainLength(Pair a[], int n)
{
	// array to store max length till ith index
	int *maxLen = new int[n];

	// initialize all the lengths to 1
	for(int i=0; i<n; i++) maxLen[i] = 1;

	sort(a, a+n, compare);

	// outer index
	for(int i=1; i<n; i++)
	{
		// inner index
		for(int j=0; j<i; j++)
		{
			// if a[i] and a[j] can make chain, 
			// check if max legth at inner index j plus one is greater than 
			// max length at i
			// if so update the max length at i
			if(a[j].second < a[i].first && maxLen[j] + 1 > maxLen[i])
			{
				maxLen[i] = maxLen[j]+1;
			}
		}
	}

	// answer will be the max of all the max lengths ending at each index
	int maxLength=0;
	for(int i=0; i<n; i++) maxLength = max(maxLen[i], maxLength);

	return maxLength;
}

int main()
{
	Pair a[] = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
	int n = 5;

	cout<<"Max length: "<<maxChainLength(a, n)<<endl;

	system("pause");
	return 0;
}