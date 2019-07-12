#include "FullCountingSort.h"

void FullCountingSort::solution(vector<vector<string>> arr)
{
	int len = arr.size();

	string num[100];

	for (int i = 0; i < len; i++)
	{
		if (i < len / 2) num[stoi(arr[i][0])] += "- ";
		else num[stoi(arr[i][0])] += arr[i][1] + " ";
	}

	for (string s : num) {
		cout << s << " ";
	}

	cout << endl;

	cout << len << endl;
}
