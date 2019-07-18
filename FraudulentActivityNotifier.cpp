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

	for (; i < d; ++i) 	arr[expenditure[i]]++;

	for (size_t j = 1; j < 201; j++)
	{
		arr[j] += arr[j - 1];
	}

	while (i < n)
	{
		size_t j = 0;
		double tmp;
		for (j = 0; j < 201 && arr[j] <= d / 2; j++);

		if ( j > 0 && arr[j - 1] == d / 2) {
			tmp = j;
			if (d % 2 == 0) {
				tmp += j - 1;
				tmp /= 2;
			}
		}
		else {
			tmp = j;
			/*if (d % 2 == 0 && j > 0) {
				tmp += arr[j - 1] + 1 == arr[j] ? j - 1: j;
				tmp /= 2;
			}*/
		}

		tmp *= 2;

		count += expenditure[i] >= tmp;

		for (size_t k = expenditure[i - d]; k < 201; k++) arr[k]--;
		for (size_t k = expenditure[i]; k < 201; k++) arr[k]++;

		i++;
	}

	return count;
}
