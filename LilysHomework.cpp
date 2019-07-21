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

	auto findPos = [](map<int, int> mp, int pos) -> int {
		map<int, int>::iterator it = mp.begin();

		while (it != mp.end())
		{
			if (it->second == pos) return it->first;
			it++;
		}

		return -1;
	};

	int pos = 0;

	for (auto const& [key, val] : occAsc) {
		if (val != pos) {
			occAsc[findPos(occAsc, pos)] = val;
			occAsc[key] = pos;
			ascCount += 1;
		}
		pos++;
	}

	pos = 0;

	for (auto const& [key, val] : occDsc) {
		if (val != pos) {
			//occDsc[findPos(occDsc, pos)] = val;
			map<int, int, greater<int>>::iterator it = occDsc.begin();

			int ans = -1;

			while (it != occDsc.end())
			{
				if (it->second == pos) ans = it->first;
				it++;
			}

			if(ans > 0) occDsc[ans] = val;
			occDsc[key] = pos;

			dscCount += 1;
		}
		pos++;
	}

	return dscCount > ascCount ? ascCount : dscCount;
}
