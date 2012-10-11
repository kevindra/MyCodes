/**
* Maximum circular subarray sum
* Given n numbers (both +ve and -ve), arranged in a circle, fnd the maximum sum of consecutive number.
* http://www.geeksforgeeks.org/archives/24106
*/
#include <iostream>

using namespace std;

/**
* Idea is to get the normal subarray sum and the circular subarray sum and take the maximum.
* How to get circular subarray sum?
* We get the totalSum of array. 
* and then we invert the sign of all the numbers in array, and get the maxSubarraySum. 
* now the circular max sum will be totalSum + maxSubarraySum of inverted array.
*/
int maxSubarraySum(int a[], int n)
{
	int maxOverAll=0, maxSoFar=0;

	for(int i=0; i<n; i++)
	{
		if(maxSoFar+a[i] > 0) { maxSoFar += a[i]; maxOverAll = max(maxSoFar, maxOverAll); }
		else maxSoFar = 0;
	}
	return maxOverAll;
}

int maxCircularSubarraySum(int a[], int n)
{
	// get the non circular max Sum
	int nonCircularMaxSum = maxSubarraySum(a, n);

	int sum=0;
	// calculate the total sum of array and invert the signs of the numbers
	for(int i=0; i<n; i++)
	{
		sum += a[i];
		a[i] = -1*a[i];
	}
	// get the max negetive numbers subarray sum
	int maxInvertedSignSum = maxSubarraySum(a, n);

	return max(nonCircularMaxSum, maxInvertedSignSum + sum);
}

int main()
{
	int a[] = {10, -3, -4, 7, 6, 5, -4, -1};
	int n = 8;

	cout<<"Max circular subarray sum: "<< maxCircularSubarraySum(a, n) <<endl;

	system("pause");
	return 0;
}