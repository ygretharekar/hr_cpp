#include "RoadsAndLibraries.h"

long RoadsAndLibraries::roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities)
{
	if (c_road > c_lib) return (long)n * c_lib;

	vector<bool> visited(n, false);

	vector<vector<int>> roads(n, vector<int>());

	for (size_t i = 0; i < cities.size(); i++)
	{
		roads[cities[i][0] - 1].push_back(cities[i][1] - 1);
		roads[cities[i][1] - 1].push_back(cities[i][0] - 1);
	}

	long cost = 0;

	for (size_t i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			long tmp = c_lib;
			stack<int> cts;

			cts.push(i);
			visited[i] = true;

			while (!cts.empty())
			{
				int node = cts.top();
				cts.pop();

				for (auto j: roads[node])
				{
					if (!visited[j])
					{
						visited[j] = true;
						tmp += c_road;
						cts.push(j);
					}
				}
			}

			cost += tmp;
		}
	}

	return cost;
}
