#include <iostream>
#include <algorithm>

using namespace std;

// ----------------------------------------------------------------
// METHOD 1
// ----------------------------------------------------------------
// O(n) 
// Search for the rotation index 
// and then do a binary search on both left and right arrays
int findRotationIndex(int a[], int n)
{
	for(int i=1; i<n; i++)	if(a[i] > a[i+1]) return i+1;
	return 0;
}

int binarySearch(int a[], int n, int s, int e, int x)
{
	if(s > e) return -1;

	int mid = (s+e)/2;

	if(x == a[mid]) return mid;

	if(x < a[mid]) return binarySearch(a, n, s, mid-1, x);
	
	if(x > a[mid]) return binarySearch(a, n, mid+1, e, x);
}

int search(int a[], int n, int e)
{
	int rotationIndex = findRotationIndex(a, n);

	int eIdx = -1;
	
	if(rotationIndex == 0) return binarySearch(a, n, 0, n-1, e);

	eIdx = binarySearch(a, n, 0, rotationIndex-1, e);

	if(eIdx >= 0) return eIdx;

	eIdx = binarySearch(a, n, rotationIndex, n-1, e);

	return eIdx;
}

// ----------------------------------------------------------------
// METHOD 2
// ----------------------------------------------------------------

// Time Complexity: O(logn)
// Worst case: O(n) when all numbers are equal
int search(int a[], int n, int s, int e, int x)
{
	if( s > e ) return -1;

	int mid = (s+e)/2;

	// if the subarray is normal sorted array
	if( a[s] <= a[mid] )
	{
		if( x > a[mid] ) return search(a, n, mid+1, e, x);
		else if( x < a[mid] ) return search(a, n, s, mid-1, x);
		else return mid;
	}
	// if subarray is also a rotated array
	else if(a[s] > a[mid])
	{
		if( x < a[s] )	return search(a, n, mid, e, x);
		else if( x > a[s] ) return search(a, n, s+1, mid, x);
		else return s;
	}
}

int main()
{
	int a[] = {15,16,19,20,25,1,3,4,5,7,10,14};
	int n = 12;

	cout<<"Found at: "<<search(a, n, 19)<<endl;
	cout<<"Found at: "<<search(a, n, 0, n-1, 19)<<endl;
	system("pause");
	return 0;
}