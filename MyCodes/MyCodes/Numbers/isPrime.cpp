#include <iostream>
#include <cmath>

using namespace std;


/**
	Check a number if it is a prime number
	1. Check divisibility till square root of the given number
	2. No even numbers are prime
*/
bool isPrime(int n)
{
		if(n <= 1) return false;
		if(n == 2) return true;
		if(n%2 == 0) return false;

		int nsqrt = sqrt(n*1.0);

		// incrementing the loop by 2 every time 
		// to skip the even numbers
		for(int i=3; i <= nsqrt; i += 2)
			if(n%i == 0) return false;
		return true;
}

/**
	Sieve of Eratosthenes

	Find all the prime numbers from 2 to n
	
	 The Sieve of Eratosthenes will generate all the primes from 2 to a given number n. 
	 It begins by assuming that all numbers are prime. 
	 It then takes the first prime number and removes all of its multiples. 
	 It then applies the same method to the next prime number.
	 This is continued until all numbers have been processed.
*/
void printAllPrimes(int limit)
{
	bool *isPr = new bool[limit+1];
	for(int i=0; i<limit+1; i++) isPr[i] = true;

	isPr[0] = false;
	isPr[1] = false;

	for(int i=2; i<=sqrt(limit*1.0); i++)
	{
		if(isPr[i])
		{
			for(int k=i*i; k<=limit; k+=i)
				isPr[k] = false;
		}
	}

	cout<<"Primes from 2 to "<<limit<<": "<<endl;
	for(int i=2; i<limit+1; i++)
	{
		if(isPr[i]) cout<<i<<" ";
	}
}

int main()
{
	int n = 23;

	cout<<"Is PRIME: "<< isPrime(n) << endl;

	printAllPrimes(20);

	system("pause");
	return 0;
}