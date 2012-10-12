/**
*	Maximum Product Subarray
* Given an array that contains both positive and negative integers, find the product of the maximum product subarray. 
* Expected Time complexity is O(n) and only O(1) extra space can be used.
* 
* Input: arr[] = {6, -3, -10, 0, 2}
* Output:   180  // The subarray is {6, -3, -10}

* Input: arr[] = {-1, -3, -10, 0, 60}
* Output:   60  // The subarray is {60}

* Input: arr[] = {-2, -3, 0, -2, -40}
* Output:   80  // The subarray is {-2, -40}

* http://www.geeksforgeeks.org/archives/22216
*/

#include <iostream>

using namespace std;

int maxSubarrayProduct(int a[], int n)
{
	int maxSoFar = 1, minSoFar = 1;
	int maxOverAll = 1;

	for(int i=0; i<n; i++)
	{
		if(a[i] > 0)
		{
			maxSoFar = maxSoFar*a[i];
			minSoFar = min(a[i]*minSoFar, 1);
		}

		else if(a[i] == 0)
		{
			maxSoFar = minSoFar = 1;
		}

		else
		{
			int prevMaxSoFar = maxSoFar;
			maxSoFar = max(minSoFar*a[i] , maxSoFar);
			minSoFar = min(prevMaxSoFar*a[i], minSoFar);
		}

		maxOverAll = max(maxOverAll, maxSoFar);
	}

	return maxOverAll;
}

int main()
{
	int arr[] = {-2, -3, 0, -2, -40};
	int n = 5;

	cout<<"Max Subarray Product: "<< maxSubarrayProduct(arr, n) << endl;

	system("pause");
	return 0;
}