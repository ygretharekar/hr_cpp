#include "Pairs.h"

int Pairs::pairs(int k, vector<int> arr)
{
	map<long, int> mp;
	int ans = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		if (mp.count(arr[i])) {
			mp[arr[i]] = mp[arr[i]] + 1;
		}
		else {
			mp[arr[i]] = 1;
		}
	}

	for (auto i: arr) {
		long t = i + k;
		if (mp.find(t) != mp.end()) ans += mp[t];
	}

	return ans;
}
