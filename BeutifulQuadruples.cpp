#include "BeutifulQuadruples.h"

int BeutifulQuadruples::beautifulQuadruples(int a, int b, int c, int d)
{
	vector<int> bq{ a, b, c, d };
	sort(bq.begin(), bq.end());

	int acc = 0;

	vector<vector<long>> cnt(bq[3] + 1, vector<long>(pow(2, ceil(log2(bq[3] + 1)))));
	vector<long> total(bq[3] + 1);

	for (size_t i = 1; i <= bq[0]; i++)
	{
		for(size_t j = i; j <= bq[1]; j++)
		{
			cnt[j][i ^ j]++;
			total[j]++;
		}
	}

	for (size_t i = 0; i < pow(2, ceil(log2(bq[3] + 1))); i++)
	{
		for (size_t j = 1; j <= bq[3]; j++)
		{
			cnt[j][i] += cnt[j - 1][i];
		}
	}

	for (size_t i = 1; i <= bq[3]; i++)
	{
			total[i] += total[i - 1];
	}

	int result = 0;

	for (size_t i = 1; i <= bq[2]; i++)
	{
		for (size_t j = i; j <= bq[3]; j++)
		{
			result += (total[i] - cnt[i][i^j]);
		}
	}

	return result;
}
