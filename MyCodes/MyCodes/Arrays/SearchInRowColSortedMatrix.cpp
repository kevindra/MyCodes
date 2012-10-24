/**
	Given a matrix in which each row and each column is sorted, 
	write a method to find an element in it.
*/
#include <iostream>

using namespace std;

bool search(int mat[][3], int m, int n, int x, int &r, int &c)
{
	// we'll start at r=0, c=n-1
	r = 0, c = n-1;

	while(r < m && c >=0)
	{
		if(x == mat[r][c]) return true;
		else if( x < mat[r][c] )
		{
			--c;
		}
		else 
		{
			r++;
		}
	}
	r=-1, c=-1;
	return false;
}

int main()
{
	int mat[][3] = {{1,5,9}, {2,6,11}, {3,7,12}, {10,18,22}};
	int m = 4, n = 3;

	int r, c;
	cout<<"Found? : "<< search(mat, m, n, 10, r, c) <<endl;

	cout<<"Found at: "<<r<<" "<<c<<endl;

	system("pause");
	return 0;
}