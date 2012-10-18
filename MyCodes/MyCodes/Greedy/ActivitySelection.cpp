/**
* Given an activities plan with start and finish time for each activity.
* Find out the max number of activities we can perform such that no activity conflicts other.
*/
#include <iostream>
#include <algorithm>

using namespace std;

struct Activity
{
	int startTime;
	int endTime;
};

bool compareAct(Activity a, Activity b)
{
	return a.endTime < b.endTime;
}

/**
* Logic is to sort the activities by the end time 
* and keep picking them, 
* and ignore the ones which conflict with the already picked activities
*/
void printMaxActivities(Activity act[], int n)
{
	sort(act, act+n, compareAct);

	int lastPicked = 0;
	cout<<"\nPicked Activity #0"<<": "<<act[0].startTime<<" "<<act[0].endTime<<endl;

	for(int i=1; i<n; i++)
	{
		if(act[i].startTime > act[lastPicked].endTime)
		{
			lastPicked = i;
			cout<<"Picked Activity #"<<i<<": "<<act[i].startTime<<" "<<act[i].endTime<<endl;
		}
	}
}

int main()
{
	Activity act[] = {{0,5}, {3,6}, {4,7}, {6,8}, {7,14}, {9,12}, {10,11}, {13,15}, {14, 17}, {16, 18}, {18, 20}};
	int n = 11;

	printMaxActivities(act, n);

	system("pause");
	return 0;
}