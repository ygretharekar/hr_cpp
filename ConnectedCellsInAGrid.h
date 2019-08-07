#pragma once
#include<vector>
#include<map>

using namespace std;


class ConnectedCellsInAGrid
{
public:
	int connectedCell(vector<vector<int>> matrix);
	int findRegionSize(vector<vector<int>> &matrix, int i, int j);
};

