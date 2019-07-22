#include "LilysHomework.h"

int LilysHomework::lilysHomework(vector<int> arr)
{
	map<int, int> mp1, mp2;

	int a_size = arr.size();

	vector<vector<int>> lists(3, vector<int>(a_size, 0));

	int a_count = 0, d_count = 0;

	for (size_t i = 0; i < a_size; i++)
	{
		lists[0][i] = lists[1][i] = lists[2][i] = arr[i];
		mp1[arr[i]] = i;
	}

	mp2 = mp1;

	sort(lists[0].begin(), lists[0].end());

	for (size_t i = 0; i < a_size; i++)
	{

		if (lists[0][i] != lists[1][i]) {
			a_count++;
			int tmp = lists[1][i];
			swap(lists[1][i], lists[1][mp1[lists[0][i]]]);
			mp1[tmp] = mp1[lists[0][i]];
		}
		if (lists[0][a_size - i - 1] != lists[2][i]) {
			d_count++;
			int tmp = lists[2][i];
			swap(lists[2][i], lists[2][mp2[lists[0][a_size - i - 1]]]);
			mp2[tmp] = mp2[lists[0][a_size - i - 1]];
		}
	}

	return min(a_count, d_count);
}
