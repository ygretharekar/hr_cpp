#include "KnightLOnAChessboard.h"

vector<vector<int>> KnightLOnAChessboard::knightlOnAChessboard(int n)
{
	vector<vector<int>> ans = vector<vector<int>>(n - 1, vector<int>(n - 1, 0));

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++) {
			ans[i-1][j-1] = getNumber(n, i, j);
		}
	}

	return ans;
}

int KnightLOnAChessboard::getNumber(int n, int a, int b)
{
	vector<vector<int>> temp(n, vector<int>(n, INT_MAX));

	temp[0][0] = 0;

	queue<pair<int, int>> q;

	q.push(make_pair(0, 0));

	while (!q.empty())
	{
		pair<int, int> loc = q.front();
		q.pop();

		int cnt = temp[loc.first][loc.second] + 1;

		vector<pair<int, int>> possibles = {
			make_pair(loc.first + a, loc.second + b),
			make_pair(loc.first + a, loc.second - b),
			make_pair(loc.first - a, loc.second + b),
			make_pair(loc.first - a, loc.second - b),
			make_pair(loc.first + b, loc.second + a),
			make_pair(loc.first + b, loc.second - a),
			make_pair(loc.first - b, loc.second + a),
			make_pair(loc.first - b, loc.second - a),
		};

		for (pair<int, int> i: possibles) {
			if (i.first >= 0 && i.first < n && i.second >= 0 && i.second < n) {
				if (cnt < temp[i.first][i.second])
				{
					temp[i.first][i.second] = cnt;
					q.push(i);
				}
			}
		}
	}

	if (temp[n - 1][n - 1] == INT_MAX)
		return -1;
	else return temp[n - 1][n - 1];
}
