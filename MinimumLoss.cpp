#include "MinimumLoss.h"

int MinimumLoss::minimumLoss(vector<long> price)
{
	map<long, int> mp;

	for (int i = 0; i < price.size(); i++)
	{
		mp[price[i]] = i;
	}

	sort(price.begin(), price.end());

	int diff = INT_MAX, ans = 0;

	for (auto it = price.rbegin(); it != price.rend() - 1; it++)
	{
		if (*it - *(it + 1) < diff)
		{
			if (mp[*it] < mp[*(it + 1)])
			{
				diff = *it - *(it + 1);
				//ans = mp[*(it - 1)] - mp[*it] + 1;
			}
		}
	}

	return diff;
}
