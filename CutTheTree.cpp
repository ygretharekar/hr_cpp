#include "CutTheTree.h"

int CutTheTree::cutTheTree(vector<int> data, vector<vector<int>> edges)
{
	int total = 0;
	int mini = INT_MAX;
	for (int i : data) total += i;
	
	vector<vector<int>> nodes;

	nodes.resize(data.size() + 1);

	for (size_t i = 0; i < edges.size(); i++)
	{
		nodes[edges[i][0]].push_back(edges[i][1]);
		nodes[edges[i][1]].push_back(edges[i][0]);
	}
	int a = dfs(1, data, nodes);

	for (size_t i = 0; i < data.size(); i++)
	{
		if (abs((a - 2 * sum[i + 1])) < mini) mini = abs((a - 2 * sum[i + 1]));
	}

	return mini;
}

int CutTheTree::dfs(int node, vector<int> &data, vector<vector<int>> &nodes)
{
	if (visited[node]) return 0;
	if (!nodes[node].size())
	{
		sum[node] = data[node - 1];
		return data[node - 1];
	}

	visited[node] = true;

	int ans = 0;

	for(int n: nodes[node])
	{
		if(!visited[n]) ans += dfs(n, data, nodes);
	}

	sum[node] = ans + data[node - 1];
	return sum[node];
}
