#pragma once

#include<vector>
#include<map>
#include<string>
#include<algorithm>


using namespace std;

class CutTheTree
{
	bool visited[100001] = {false};
	int sum[100001] = {0};
public:
	int cutTheTree(vector<int> data, vector<vector<int>> edges);
	int dfs(int node, vector<int> &data, vector<vector<int>> &edges);
};

