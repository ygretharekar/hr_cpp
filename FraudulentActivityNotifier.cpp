#include "FraudulentActivityNotifier.h"

int FraudulentActivityNotifier::activityNotifications(vector<int> expenditure, int d)
{
	size_t n = expenditure.size();
	
	size_t arr[201];

	size_t count = 0;

	for (size_t i = 0; i < 201; i++)
	{
		arr[i] = 0;
	}

	size_t i = 0;

	for (; i < d; i++) 	arr[expenditure[i]]++;

	for (size_t i = 1; i < 201; i++)
	{
		arr[i] += arr[i - 1];
	}

	int fr = 0;

	for (size_t i = 0; i < n; i++)
	{
		size_t j = 0, tmp = 0;

		for (; j < n && arr[j] < d / 2; j++);

		if (arr[j] == d / 2) {
			tmp = j + 1;
		}

	}

	while (i < n)
	{
		size_t j = 1, tmp = 0;
		for (j = 0; j < 201 && arr[j] < d / 2; j++);

		if (arr[j] == d / 2) {
			tmp = j + 1;
			if (d % 2 == 0) {
				tmp += j;
				tmp /= 2;
			}
		}
		else {
			tmp = j;
			if (d % 2 == 0) {
				tmp = arr[j - 1] + 1 == arr[j] ? j - 1: j;
				tmp /= 2;
			}
		}
	}

	return count;
}
