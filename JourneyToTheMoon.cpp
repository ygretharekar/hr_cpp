#include "JourneyToTheMoon.h"

int JourneyToTheMoon::journeyToMoon(int n, vector<vector<int>> astronaut)
{
	vector<int> links(n, -1);
	map<int, int> contries;

	for (vector<int> a_pair: astronaut)
	{
		links[a_pair[0]] = links[a_pair[0]] == -1 ? a_pair[0] : links[a_pair[0]];
		links[a_pair[1]] = links[a_pair[1]] == -1 ? a_pair[1] : links[a_pair[1]];

		int temp = links[a_pair[1]];
		links[a_pair[1]] = links[a_pair[0]];

		//int a_id = 1;
		for (size_t i = 0; i < n; i++)
		{
			if (links[i] == temp) links[i] = links[a_pair[1]];
		}
	}

	for (int i : links)
	{
		auto itr = contries.find(i);
		if (itr == contries.end())
		{
			contries.insert(pair<int, int>(i, 1));
		}
		else
		{
			itr->second = itr->second + 1;
		}
	}

	long alone = 0;

	vector<int> count(contries.size());
	int j = 0;
	for (auto p: contries)
	{
		if (p.first == -1)
		{
			alone = p.second;
			continue;
		}
		count[j++] = p.second;
	}



	return 0;
}
