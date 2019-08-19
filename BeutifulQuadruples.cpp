#include "BeutifulQuadruples.h"

int BeutifulQuadruples::beautifulQuadruples(int a, int b, int c, int d)
{
	vector<int> bq{ a, b, c, d };
	sort(bq.begin(), bq.end());

	int acc = 0;

	vector<long> cnt(pow(2, ceil(log2(bq[3] + 1))));

	for (size_t i = 1; i <= bq[0]; i++)
	{
		for(size_t j = i; j <= bq[1]; j++)
		{
			cnt[i ^ j]++;
			acc++;
		}
	}



	S
	int result = 0;
	int copies = 0;

	for (size_t i = 1; i <= bq[2]; i++)
	{
		for(size_t j = i; j <= bq[3]; j++)
		{
			result += (acc - cnt[i ^ j] - copies);
			copies++;
		}
	}

	return result;
}
