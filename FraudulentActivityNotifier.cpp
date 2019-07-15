#include "FraudulentActivityNotifier.h"

int FraudulentActivityNotifier::activityNotifications(vector<int> expenditure, int d)
{
	size_t n = expenditure.size();
	
	size_t arr[201];

	for (size_t i = 0; i < 201; i++)
	{
		arr[i] = 0;
	}

	for (int i : expenditure)
		arr[i]++;

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

	return 0;
}
