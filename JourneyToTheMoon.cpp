#include "JourneyToTheMoon.h"

int JourneyToTheMoon::journeyToMoon(int n, vector<vector<int>> astronaut)
{
	vector<int> links(n, -1);

	for (vector<int> a_pair: astronaut)
	{
		links[a_pair[0]] = links[a_pair[0]] == -1 ? a_pair[0] : links[a_pair[0]];
		links[a_pair[1]] = links[a_pair[0]] == -1 ? a_pair[1] : links[a_pair[1]];

		int temp = links[a_pair[1]];
		links[a_pair[1]] = links[a_pair[0]];

		//int a_id = 1;


	}

	return 0;
}
