#include "GenaPlayingHanoi.h"

int GenaPlayingHanoi::genaPlayingHanoi(int n, vector<int> a)
{
	unsigned state = 0;

	for (size_t i = 0; i < n; i++)
	{
		int rod = a[i];
		state = move(state, i, --rod);
	}
	int ans = getMin(n, state);
	return ans;
}

unsigned GenaPlayingHanoi::move(unsigned state, int disc, int rod)
{
	return state & ~(3 << 2*disc) | (rod << 2*disc);
}

int GenaPlayingHanoi::getDisc(int rod, int n, unsigned state)
{
	int disc = n + 1;
	for (int i = n; i >= 0; i--)
	{
		unsigned r = 3 & state >> 2 * i;
		if (r == rod) disc = i;
	}
	return disc;
}

int GenaPlayingHanoi::getMin(int n, unsigned state)
{
	queue<unsigned> topdiscs;
	unsigned win = 0;
	if (state == win) return 0;
	vector<unsigned> depth(1<<(2*n), 0);

	topdiscs.push(state);

	while (true)
	{
		unsigned s = topdiscs.front();
		topdiscs.pop();
		int d[4] = {};
		for (size_t i = 0; i < 4; i++)
		{
			d[i] = getDisc(i, n, s);
		}
		for (size_t i = 0; i < 4; i++)
		{
			if (getDisc(i, n, s) == n + 1) continue;
			for (size_t j = 0; j < 4; j++)
			{
				if (d[i] < d[j])
				{
					unsigned n_s = move(s, d[i], j);
					if (n_s == 0) return depth[s] + 1;
					if (!depth[n_s] && n_s != state)
					{
						depth[n_s] = 1 + depth[s];
						topdiscs.push(n_s);
					}
				}
			}
		}
	}
	return -1;
}
