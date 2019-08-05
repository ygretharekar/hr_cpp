#include "GridlandMetro.h"

long long GridlandMetro::gridlandMetro(int n, int m, int k, vector<vector<int>> track)
{
	map<int, vector<pair<int, int>>> grids;

	int ans = 0;

	for (vector<int> &i: track) {
		if (grids.find(i[0]) == grids.end())
		{
			grids[i[0]] = vector<pair<int, int>>{make_pair(i[1], i[2])};
		}
		else {

			vector<pair<int, int>> &grd = grids[i[0]];

			if (i[2] < grd[0].first)
			{
				grd.insert(grd.begin(), make_pair(i[1], i[2]));
				continue;
			}
			else if (grd[grd.size() - 1].second < i[1])
			{
				grd.push_back(make_pair(i[1], i[2]));
				continue;
			}
			int high = grd.size() - 1, low = 0;

			while (low < grd.size() && grd[low].second < i[1])
			{
				low++;
			}
			while (high >= 0 && grd[high].first > i[2])
			{
				high--;
			}

			int minimum = min(i[1], grd[low].first),
				maximum = max(i[2], grd[high].second);

			grd.erase(grd.begin() + low, grd.begin() + high + 1);
			grd.insert(grd.begin() + low, make_pair(
				minimum,
				maximum
			));
		}
	}

	long long total = (long long)m * n;

	for (pair<int, vector<pair<int, int>>> i: grids) {
		for (pair<int, int> &j: i.second) {
			int len = j.second - j.first + 1;
			total -= (long long)len;
		}
	}

	return total;
}
