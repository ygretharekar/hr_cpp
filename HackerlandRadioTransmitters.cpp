#include "HackerlandRadioTransmitters.h"

int HackerlandRadioTransmitters::hackerlandRadioTransmitters(vector<int> x, int k)
{

	sort(x.begin(), x.end());

	vector<int>::iterator it = x.begin();

	int transmitters = 0;

	while (it != x.end()) {
		transmitters++;
		while (it != x.end() && )
		it++;
	}

	return transmitters;
}
