/**
You are given two 32-bit numbers, N and M, and two bit positions, i and j. 
Write a method to set all bits between i and j in N equal to M 
(e.g., M becomes a substring of N located at i and starting at j).

EXAMPLE:
Input: N = 10000000000, M = 10101, i = 2, j = 6
Output: N = 10001010100
*/
#include <iostream>

using namespace std;

int solve(int m, int n, int i, int j)
{
	int mx = ~0;	// all 1

	int leftMask = mx - ((1<<j) -1);
	int rightMask = (1<<i) - 1;

	// 1's, with 0s between i and j
	int mask = leftMask | rightMask;

	return (n & mask) | (m << i);
}

int main()
{
	int n,m,i,j;

	n = 1024;
	m = 21;
	i = 2, j = 6;

	cout<<"Output: "<< solve(m, n, i, j) <<endl;
	system("pause");
	return 0;
}