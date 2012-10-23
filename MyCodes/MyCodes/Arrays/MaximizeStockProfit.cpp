/**
You have an array for which the ith element is the price of a given stock on day "i".
If you are only allowed to buy one share of the stock and sell one share of the stock, make an algorithm to find the best times to buy and sell.


Read more: http://www.businessinsider.com/8-mind-bending-interview-questions-that-google-asks-its-engineers-2012-7?op=1#ixzz2A7vVBfL0
*/
#include <iostream>

using namespace std;

// This solution just returns the max profit 
// it doesn't tell anything about the best buy and sell days
int getMaxProfit(int *a, int n)
{
	int maxProfit = 0;
	int minStockSoFar = a[0];

	for(int i=1; i<n; i++)
	{
		maxProfit = max( maxProfit, a[i] - minStockSoFar );
		minStockSoFar = min( minStockSoFar, a[i] );
	}

	return maxProfit;
}

// solution which gives max profit along with best buy and sell days
int maximizeProfit(int *a, int n, int &buyDay, int &sellDay)
{
	int maxProfit = 0;
	int minStockDay = 0;

	for(int i=1; i<n; i++)
	{
		if(maxProfit < a[i] - a[minStockDay])
		{
			maxProfit = a[i] - a[minStockDay];
			buyDay = minStockDay;
			sellDay = i;
		}

		if(a[minStockDay] > a[i])	minStockDay = i;
	}

	return maxProfit;
}

int main()
{
	int a[] = {5,6,7,1,4,2,10};
	int n = 7;

	int buyDay, sellDay;
	cout<<"Maximum Profit Method 1: "<< getMaxProfit(a,n) <<endl;
	cout<<"Maximum Profit Method 2: "<< maximizeProfit(a, n, buyDay, sellDay) <<endl;

	cout<<"Buy Day: "<<buyDay<<endl;
	cout<<"Sell Day: "<<sellDay<<endl;

	system("pause");
	return 0;
}