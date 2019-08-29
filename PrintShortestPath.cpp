#include "PrintShortestPath.h"

struct KNIGHT_MOVES {
	int i, j, num;
	string allMoves;
};

void PrintShortestPath::printShortestPath(int n, int i_start, int j_start, int i_end, int j_end)
{
	int mov_y[] = {-2, -2, 0, 2, 2, 0};
	int mov_x[] = {-1, 1, 2, 1, -1, -2};
	string moves[] = { "UL ", "UR ", "R ", "LR ", "LL ", "L " };
	vector<vector<bool>> visited(n, vector<bool>(n, true));

	queue<KNIGHT_MOVES> bfs;

	bfs.push(KNIGHT_MOVES{i_start, j_start, 0, ""});
	visited[i_start][j_start] = false;

	while (!bfs.empty())
	{
		auto loc = bfs.front();
		bfs.pop();
		if (loc.i == i_end && loc.j == j_end) 
		{
			cout << loc.num << endl;
			cout << loc.allMoves << endl;
			return;
		}

		for (size_t i = 0; i < 6; i++)
		{
			if (possible(n, loc.i + mov_y[i], loc.j + mov_x[i]))
			{
				if (visited[loc.i + mov_y[i]][loc.j + mov_x[i]])
				{
					visited[loc.i + mov_y[i]][loc.j + mov_x[i]] = false;
					bfs.push(KNIGHT_MOVES{ loc.i + mov_y[i], loc.j + mov_x[i], loc.num + 1, loc.allMoves + moves[i]});
				}
			}
		}
	}

	cout << "Impossible" << endl;
}

bool PrintShortestPath::possible(int n, int x, int y)
{
	return x >= 0 && y >= 0 && x < n-1 && y <= n-1;
}
