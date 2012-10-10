/**
* Find the row with maximum number of 1s
* 
	Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s.

	Example
	Input matrix
	0 1 1 1
	0 0 1 1
	1 1 1 1  // this row has maximum 1s
	0 0 0 0

	Output: 2
*/
#include <iostream>

using namespace std;

// ============================================================================================
// METHOD 1 STARTS HERE - BRUTE FORCE
// ============================================================================================
/**
* Brute force O(m*n)
*/
int findMax1Row(int mat[][4], int r, int c)
{
	int max1s, maxi;
	maxi = max1s = 0;
	for(int i=0; i<r; i++)
	{
		int ones = 0;
		for(int j=0; j<c; j++) ones += mat[i][j];
		if(ones > max1s) maxi = i, max1s = ones;
	}
	return maxi;
}


// ============================================================================================
// METHOD 2 STARTS HERE - USING BINARY SEARCH
// ============================================================================================

/**
* since the rows are sorted we can use Binary Search to get the index of the first occurance of 1
* and then we can get the number of ones also in that row
*/
int findFirstOne(int *a, int s, int e)
{
	if(e >= s)
	{
		int mid = (s+e)/2;

		// find if the a[mid] is the first 1
		if( (mid==0 || a[mid-1]==0) && a[mid]==1 )	return mid;

		if(a[mid] == 1)	return findFirstOne(a, s, mid-1);
		else return findFirstOne(a,mid+1, e);
	}
	return -1;
}

int findMax1RowMethod2(int mat[][4], int r, int c)
{
	int maxOnes = -1, maxI = 0;
	for(int i =0; i<r; i++)
	{
		int firstOne = findFirstOne(mat[i], 0, c-1);
		int noOfOnes = (firstOne==-1)? 0 : (c-firstOne);
		if(maxOnes < noOfOnes) maxOnes=noOfOnes, maxI=i;
	}
	return maxI;
}

int main()
{
	int r = 4, c = 4;
	int mat[4][4] = {
		{0,1,1,1},
		{0,0,1,1},
		{1,1,1,1},
		{0,0,0,0},
	};

	int maxRowIndex = findMax1Row(mat, r, c);

	cout<<"MaxRowIndex (method1): "<<maxRowIndex<<endl;

	int maxRowIndex2 = findMax1RowMethod2(mat, r, c);
	cout<<"MaxRowIndex (method2): "<<maxRowIndex2<<endl;

	system("pause");
	return 0;
}
