/**
	Write a method to decide if two strings are anagrams or not.
*/

#include <iostream>

using namespace std;


// Solution 1
// sort both the strings and compare them 
// if they are equal .. then they are Anagrams
// else not

// Solution 2
// check the counts of letters in both the strings
// if counts are same 
// then they are Anagrams
bool areAnagramsSolution2(char *s1, char *s2)
{
	if(s1 == NULL || s2 == NULL) return false;

	int freqS1[26] = {0};
	int freqS2[26] = {0};

	char *tempS1 = s1;
	while(*tempS1)	freqS1[(*tempS1++) -'a']++; 

	char *tempS2 = s2;
	while(*tempS2) freqS2[(*tempS2++) - 'a']++;

	for(int i=0; i<26; i++)
		if(freqS1[i] != freqS2[i]) return false;
	return true;
}

int main()
{
	char *s1 = new char;
	cin>>s1;
	char *s2 = new char;
	cin>>s2;

	cout<<"Anagrams: "<< areAnagramsSolution2(s1,s2) <<endl;

	system("pause");
	return 0;
}