/**
Imagine a robot sitting on the upper left hand corner of an NxN grid. 
The robot can only move in two directions: right and down. 
How many possible paths are there for the robot?

Answer: In an NxN grid, total number of right steps are (N-1) and down steps are (N-1). 
So we have input set as {R,R,R...N-1, D,D,D...N-1}
Total number of permutation of this set will be (N-1+N-1)! / (N-1)! * (N-1)! = (2*N-2)!/((N-1)!*(N-1)!)

FOLLOW UP
PART 2
Imagine certain squares are “off limits”, such that the robot can not step on them. 
Design an algorithm to get all possible paths for the robot.
*/
#include <iostream>
#include <string>

using namespace std;

int getPathsCount(string s[], int i, int j, int n)
{
	if(i<n && j<n && s[i][j] == '1') return 0;
	
	if(i == n-1 && j == n-1)	return 1;

	if(i == n-1)
		return getPathsCount(s, i, j+1, n);
	if(j == n-1)
		return getPathsCount(s, i+1, j, n);

	return getPathsCount(s, i+1, j, n) + getPathsCount(s, i, j+1, n);
}

int main()
{
	string s[] = { "0001", "0000", "0000", "0000" };
	int n = 4;

	cout<<"Paths: "<<getPathsCount(s, 0, 0, n)<<endl;

	system("pause");
	return 0;
}
