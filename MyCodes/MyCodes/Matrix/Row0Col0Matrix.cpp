/**
	Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.
*/
#include <iostream>

using namespace std;

void print(int **mat, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

void solve(int **mat, int n)
{
	int *row = new int[n];
	int *col = new int[n];

	for(int i=0; i<n; i++)	for(int j=0; j<n; j++)
		if(mat[i][j] == 0) row[i] = 1, col[j] = 1;

	for(int i=0; i<n; i++)	for(int j=0; j<n; j++)
		if(row[i] == 1 || col[j] == 1) mat[i][j] = 0;
}

int main()
{
	int n = 5;
	int **mat;

	mat = (int**) malloc( n*n*sizeof(int));
	for(int i=0; i<n; i++) mat[i] = (int*) malloc(n*sizeof(int));

	for(int i=0; i<n; i++) for(int j=0; j<n; j++) mat[i][j] = 1;

	mat[0][1] = 0;
	mat[3][4] = 0;
	mat[2][2] = 0;

	cout<<"Original Matrix: "<<endl;
	print(mat, n);
	cout<<endl;

	solve(mat, n);

	cout<<"After : "<<endl;
	print(mat, n);
	cout<<endl;

	system("pause");
	return 0;
}