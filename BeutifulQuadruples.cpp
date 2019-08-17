#include "BeutifulQuadruples.h"

int BeutifulQuadruples::beautifulQuadruples(int a, int b, int c, int d)
{
	vector<int> bq{ a, b, c, d };
	sort(bq.begin(), bq.end());

	int cnt = 0;



	for (size_t i = 1; i <= bq[0]; i++)
	{
		for(size_t j = i; j <= bq[1]; j++)
		{

			cnt++;
		}
	}
	
	return 0;
}
