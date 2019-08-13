#include "GenaPlayingHanoi.h"

int GenaPlayingHanoi::genaPlayingHanoi(int n, vector<int> a)
{
	return 0;
}

unsigned GenaPlayingHanoi::move(unsigned state, int disc, int rod)
{
	return state & ~(3 << 2*disc) | (rod << 2*disc);
}

int GenaPlayingHanoi::getDisc(int rod, int n, unsigned state)
{
	int disc = n + 1;
	return 3 & state >> 2*n;
}

int GenaPlayingHanoi::getMin(int n, unsigned state)
{
	queue<unsigned> topdiscs;
	unsigned win = 0;
	if (state == win) return 0;
	vector<unsigned> depth((long)1<<(2*n), 0);

	topdiscs.push(state);

	while (true)
	{
		unsigned s = topdiscs.front();
		topdiscs.pop();
		int d[4] = {};
		for (size_t i = 0; i < 4; i++)
		{
			//d[i] = getDisc();
		}
	}
	return 0;
}
