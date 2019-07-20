#include "LilysHomework.h"

int LilysHomework::lilysHomework(vector<int> arr)
{
	map<int, int> occAsc;
	map<int, int, greater<int>> occDsc;

	for (size_t i = 0; i < arr.size(); i++) {
		occAsc[arr[i]] = i;
		occDsc[arr[i]] = i;
	} 

	int dscCount, ascCount;

	ascCount = dscCount = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		dscCount += abs(occDsc[arr[i]] - i);
		ascCount += abs(occAsc[arr[i]] - i);
	}


	return dscCount > ascCount ? ascCount: dscCount;
}
