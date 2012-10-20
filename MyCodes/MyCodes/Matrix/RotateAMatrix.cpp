/**
Given an image represented by an NxN matrix, 
where each pixel in the image is 4 bytes,
write a method to rotate the image by 90 degrees. 
Can you do this in place?
*/
#include <iostream>

using namespace std;

void print(char **mat, int n)
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

/** METHOD 1: using rotation matrix **/
// This method doesn't work with even sized matrix.
// we can tweak the matrix and make it odd sized.
void getNewIJ(int &i, int &j, int n)
{
	int mat[2][2] = {	{0, -1}, {1, 0} };

	i -= (n)/2;
	j -= (n)/2;

	int newi = i*mat[0][0] + j*mat[0][1];
	int newj = i*mat[1][0] + j*mat[1][1];

	i = newi + (n)/2;
	j = newj + (n)/2;
}

void rotate(char **fromMat, int n)
{
	char **mat = (char**) malloc( n*n*sizeof(char*));
	for(int i=0; i<n; i++)	mat[i] = (char*) malloc(n*sizeof(char));

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			int newi = i, newj = j;
			getNewIJ(newi, newj, n);

			mat[newi][newj] = fromMat[i][j];
		}
	}

	cout<<"Rotated mat: " <<endl;
	print(mat, n);
	cout<<endl;
}

// CORRECT SOLUTION!!
// INPLACE ROTATION
// counterclock-wise
void rotate2(char **mat, int n)
{
	for(int layer=0; layer<=n/2; layer++)
	{
		for(int j=layer; j<n-layer-1; j++)
		{
			char c = mat[layer][j];
			mat[layer][j] = mat[j][n-layer-1];
			mat[j][n-layer-1] = mat[n-layer-1][n-j-1];
			mat[n-layer-1][n-j-1] = mat[n-j-1][layer];
			mat[n-j-1][layer] = c;
		}
	}
	cout<<"Rotated mat: " <<endl;
	print(mat, n);
	cout<<endl;
}

int main()
{
	int n = 10;
	char **mat = (char**) malloc( n*n*sizeof(char*));
	for(int i=0; i<n; i++)	mat[i] = (char*) malloc(n*sizeof(char));

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			mat[i][j] = i+'a';
		}
	}
	cout<<"Original Mat: "<<endl;
	print(mat, n);
	cout<<endl;

	//rotate(mat, n);
	rotate2(mat, n);

	system("pause");
	return 0;
}