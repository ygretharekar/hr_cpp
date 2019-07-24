#include "HackerlandRadioTransmitters.h"

int HackerlandRadioTransmitters::hackerlandRadioTransmitters(vector<int> x, int k)
{
	sort(x.begin(), x.end());

	vector<int>::iterator it = x.begin();

	int transmitters = 0;

	while (it != x.end()) {
		transmitters++;

		int loc = *it;

		while (it != x.end() && loc + k >= *it) it++;

		loc = *--it;

		while (it != x.end() && loc + k >= *it) it++;
	}

	return transmitters;
}
