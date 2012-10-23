/**
There are n coins in a line. Two players take turns to take a coin from 
one of the ends of the line until there are no more coins left. 
The player with the larger amount of money wins.

Would you rather go first or second? Does it matter?
Assume that you go first and other player plays optimally, 
describe an algorithm to compute the maximum amount of money you can win.


Read more: http://www.businessinsider.com/8-mind-bending-interview-questions-that-google-asks-its-engineers-2012-7?op=1#ixzz2A819QHAj
*/
#include <iostream>

using namespace std;

// Gives max coins player A gets if player B plays optimally
// Time Complexity = 2^n
int maxCoins(int *a, int s, int e, int turn)
{
	if(turn == 0)	// Player A's turn
	{
		if(s == e) return a[s];
		return max(
				maxCoins(a, s+1, e, (turn+1)%2) + a[s],
				maxCoins(a, s, e-1, (turn+1)%2) + a[e]
			);
	}
	else
	{
		if(s == e) return 0;
		return min(
				maxCoins(a, s+1, e, (turn+1)%2),
				maxCoins(a, s, e-1, (turn+1)%2)
			);
	}
}

// Time Complexity n^2
int maxCoins(int *a, int s, int e, int turn, int **&dp)
{
	// use the previously stored result of the subproblem.
	if(dp[s][e] > 0) return dp[s][e];

	if(turn == 0)	// Player A's turn
	{
		if(s == e) return dp[s][e] = a[s];

		return dp[s][e] = max(
				maxCoins(a, s+1, e, (turn+1)%2) + a[s],
				maxCoins(a, s, e-1, (turn+1)%2) + a[e]
			);
	}
	else
	{
		if(s == e) return dp[s][e] = 0;

		return dp[s][e] = min(
				maxCoins(a, s+1, e, (turn+1)%2),
				maxCoins(a, s, e-1, (turn+1)%2)
			);
	}
}

int main()
{
	int a[] = {10, 30, 20, 50};
	int n = 4;

	int **dp = (int**) malloc(n*n*sizeof(int));
	for(int i=0; i<n; i++) dp[i]	=	(int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) dp[i][j] = -1;

	cout<<"Max Money A gets: "<< maxCoins(a, 0, n-1, 0, dp)<<endl;

	system("pause");
	return 0;
}