#include "GridlandMetro.h"

int GridlandMetro::gridlandMetro(int n, int m, int k, vector<vector<int>> track)
{
	map<int, pair<int, pair<int, int>>> posts;

	for (vector<int> i: track) {
		if (posts.count(i[0])) {

		}
		else {
			posts[i[0]].first = i[2] - i[1] + 1;
			posts[i[0]].second.first = i[1];
			posts[i[0]].second.first = i[2];
		}
	}

	return 0;
}
