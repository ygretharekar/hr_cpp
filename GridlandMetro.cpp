#include "GridlandMetro.h"

int GridlandMetro::gridlandMetro(int n, int m, int k, vector<vector<int>> track)
{
	map<int, pair<int, pair<int, int>>> posts;

	int ans = 0;

	for (vector<int> i: track) {
		if (posts.count(i[0])) {
			if (posts[i[0]].second.first > i[1]) {
				posts[i[0]].first += posts[i[0]].second.first - i[1];
				posts[i[0]].second.first = i[1];
			}
			if (posts[i[0]].second.second < i[2]) {
				posts[i[0]].first += i[2] - posts[i[0]].second.second;
				posts[i[0]].second.second = i[2];
			}
		}
		else {
			posts[i[0]].first = i[2] - i[1] + 1;
			posts[i[0]].second.first = i[1];
			posts[i[0]].second.second = i[2];
		}
	}

	ans = (n - posts.size())*m;

	for (pair<int, pair<int, pair<int, int>>> i: posts) {
		ans += (m - i.second.first);
	}

	return ans;
}
