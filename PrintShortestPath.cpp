#include "PrintShortestPath.h"

void PrintShortestPath::printShortestPath(int n, int i_start, int j_start, int i_end, int j_end)
{
	int mov_y[] = {2, 2, 0, -2, -2, 0};
	int mov_x[] = {-1, 1, 2, 1, -1, -2};
	string moves[] = { "UL", "UR", "R", "LR", "LL", "L" };

	queue<pair<int, int>> bfs;

	bfs.push(pair<int, int>(i_start, j_start));

	while (!bfs.empty())
	{
		auto loc = bfs.front();
		bfs.pop();
	}

	cout << "Hello World" << endl;
}

bool PrintShortestPath::possible(int n, int x, int y)
{
	return x >= 0 && y >= 0 && x < n-1 && y <= n-1;
}
