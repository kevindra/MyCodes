/**
Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
*/
#include <iostream>
#include <list>

using namespace std;

bool isPath(int **g, int n, int src, int dest)
{
	bool *visited = (bool*)malloc(n*sizeof(bool));
	for(int i=0; i<n; i++) visited[i] = false;

	list<int> q;

	// enqueue the src
	q.push_back(src);
	
	while(!q.empty())
	{
		int curr = q.front();

		if(curr == dest) return true;

		q.pop_front();
		visited[curr] = true;

		for(int i=0; i<n; i++)
			if(g[curr][i] && !visited[i]) {	q.push_back(i); }
	}
	return false;
}

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

	cout<<"IS PATH: "<<isPath(g, n, 4, 3)<<endl;

	system("pause");
	return 0;
}