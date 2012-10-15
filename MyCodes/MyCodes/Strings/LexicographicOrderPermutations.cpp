/**
* Print all permutations in sorted (lexicographic) order
* Given a string, print all permutations of it in sorted order. 
* For example, if the input string is “ABC”, then output should be “ABC, ACB, BAC, BCA, CAB, CBA”.
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string nextPermutation(string s)
{
	int firstIdx=-1, secIdx=-1;

	// first Take the previously printed permutation 
	// and find the rightmost character in it, 
	// which is smaller than its next character.
	// Let us call this index as firstIdx.
	for(int i=s.size()-1; i>=1 ; i--)
	{
		if(s[i-1] < s[i])	{	firstIdx = i-1; break; }
	}
	
	// no more permutations
	if(firstIdx == -1) return "";

	// Now find the smallest character on right of ‘firstIdx’ character, 
	// which is greater than ‘firstIdx’ character. 
	// Let us call the ceil character as ‘secondIdx’.
	secIdx = -1;
	for(int i=firstIdx+1; i<s.size(); i++) 
	{
		if(s[i] > s[firstIdx]) 
		{
			if(secIdx == -1) secIdx = i;
			else if(s[i] < s[secIdx]) secIdx = i;
		}
	}

	// swap both the first and second indexes
	swap(s[firstIdx], s[secIdx]);

	// sort the substring after firstIdx
	sort(s.begin()+firstIdx+1, s.end());

	// return s
	return s;
}

void generateLaxicographicPermutations(string s)
{
	if(s == "" || s.length() == 1) return;

	// first we will sort the string in ascending order
	sort(s.begin(), s.end());

	// print the first permutation, i.e. all letters sorted
	cout<<s<<endl;

	// get the next permutation
	string next = nextPermutation(s);
	int count=1;
	while( next != "")
	{
		cout<<next<<endl;
		s = next;
		next = nextPermutation(s);
		count++;
	}

	cout<<"Total Permutations: "<<count<<endl;
}

int main()
{
	string s = "DCFEBA";
	generateLaxicographicPermutations(s);

	system("pause");
	return 0;
}