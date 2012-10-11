/**
* Given coins with their value and a sum. 
* Find the minimum no. of coins that sum up to the given sum.
*/
#include <iostream>

using namespace std;

int minCoins(int coinValues[], int n, int sum)
{
	int *Min = new int[sum+1];

	for(int i=0; i<sum+1; i++) Min[i] = INT_MAX; // setting min as infinite
	Min[0] = 0; // base case, zero sum is only possible using zero value coin

	// iterate though each possible sum
	for(int i=1; i<=sum; i++)
	{
		// iterate throught each coin
		for(int j=0; j<n; j++)
		{
			// if current sum (i) - current coin value + 1 is less than minimum sum till ith index
			if(coinValues[j] <= i && Min[i-coinValues[j]]+1 < Min[i])
			{
				Min[i] = Min[i-coinValues[j]]+1;
			}
		}
	}

	return Min[sum];
}

int main()
{
	int coinValues[] = {1,3,5}, n=3, sum=11;

	cout<<"Min coins required: "<< minCoins(coinValues, n, sum) << endl;

	system("pause");
	return 0;
}