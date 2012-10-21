#include <iostream>
#include <list>

using namespace std;

int main()
{
	int n = 5;
	int **g = (int**)malloc(n*n*sizeof(int));
	for(int i=0; i<n; i++) g[i] = (int*)malloc(n*sizeof(int));

	for(int i=0; i<n; i++) for(int j=0; j<n; j++) g[i][j] = 0;

	g[0][1] = 1;
	g[0][2] = 1;
	g[1][3] = 1;
	g[2][1] = 1;
	g[4][0] = 1;

	system("pause");
	return 0;
}