#include "ConnectedCellsInAGrid.h"

int ConnectedCellsInAGrid::connectedCell(vector<vector<int>> matrix)
{
	int max_size = -1;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			int s = findRegionSize(matrix, i, j);
			max_size = max_size < s ? s : max_size;
		}
	}
	return max_size;
}

int ConnectedCellsInAGrid::findRegionSize(vector<vector<int>> &matrix, int i, int j)
{
	if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[i].size()) return 0;
	if (!matrix[i][j]) return 0;

	int ans = matrix[i][j];

	matrix[i][j] = 0;

	for (int a = i - 1; a <= i + 1; a++)
	{
		for (int b = j - 1; b <= j + 1; b++)
		{
			ans += findRegionSize(matrix, a, b);
		}
	}

	return ans;
}
