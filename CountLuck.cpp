#include "CountLuck.h"

string CountLuck::countLuck(vector<string> matrix, int k)
{
	int start_i = 0, start_j = 0;
	
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix[i].length(); j++)
		{
			if (matrix[i][j] == 'M')
			{
				start_i = i;
				start_j = j;
			}
		}
	}

	int ans = wand(matrix, start_i, start_j, matrix.size(), matrix[0].length());

	return ans == k ? "Impressed": "Oops!";
}

int CountLuck::wand(vector<string> &matrix, int s_i, int s_j, int n, int m)
{
	if (matrix[s_i][s_j] == '*')
	{
		found = true;
		return 0;
	}

	int count = 0, ans = 0;

	matrix[s_i][s_j] = 'X';

	for (size_t i = 0; i < 4; i++)
	{
		if (canGo(matrix, s_i + tb[i], s_j + rl[i], n, m))
		{
			count += wand(matrix, s_i + tb[i], s_j + rl[i], n, m);
			ans++;
		}
	}

	if (found) return ans > 1 ? count + 1 : count;
	else return 0;
}

bool CountLuck::canGo(vector<string>& matrix, int s_i, int s_j, int n, int m)
{
	bool ans = false;

	if (s_i >= 0 && s_i < n && s_j >= 0 && s_j < m)
	{
		ans = true;
		if (matrix[s_i][s_j] == 'X') ans = false;
	}

	return ans;
}
