#include "GridlandMetro.h"

int GridlandMetro::gridlandMetro(int n, int m, int k, vector<vector<int>> track)
{
	map<int, vector<pair<int, int>>> grids;

	int ans = 0;

	for (vector<int> i: track) {
		if (grids.find(i[0]) == grids.end())
		{
			grids[i[0]] = vector<pair<int, int>>{make_pair(i[1], i[2])};
		}
		else {
			if (i[2] < grids[i[0]][0].first)
			{
				grids[i[0]].insert(grids[i[0]].begin(), make_pair(i[1], i[2]));
				continue;
			}
			else if (grids[i[0]][grids[i[0]].size() - 1].second < i[1])
			{
				grids[i[0]].push_back(make_pair(i[1], i[2]));
				continue;
			}
			int high = grids[i[0]].size() - 1, low = 0;

			while (low < grids[i[0]].size() && grids[i[0]][low].second < i[1])
			{
				low++;
			}
			while (high >= 0 && grids[i[0]][high].first > i[2])
			{
				high--;
			}

			int minimum = min(i[1], grids[i[0]][low].first),
				maximum = max(i[2], grids[i[0]][high].second);

			grids[i[0]].erase(grids[i[0]].begin() + low, grids[i[0]].begin() + high + 1);
			grids[i[0]].insert(grids[i[0]].begin() + low, make_pair(
				minimum,
				maximum
			));
		}
	}

	long long total = (long long)m * n;

	for (pair<int, vector<pair<int, int>>> i: grids) {
		for (pair<int, int> j: i.second) {
			int len = j.second - j.first + 1;
			total -= (long long)len;
		}
	}

	return (int)total;
}
