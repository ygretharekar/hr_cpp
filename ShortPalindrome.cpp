#include "ShortPalindrome.h"

int ShortPalindrome::shortPalindrome(string s)
{
	//vector<long> c1(26, 0);
	//vector<vector<long>> c2(26, vector<long>(26, 0));
	//vector<vector<vector<long>>> c3(26, vector<vector<long>>(26, vector<long>(26, 0)));
	/*vector<vector<vector<vector<long>>>> c4(26, vector<vector<vector<long>>>(26, 
		vector<vector<long>>(26, vector<long>(26, 0))));*/

	int c1[26] = {};
	int c2[26][26] = {};
	int c3[26] = {};

	long ans = 0;
	const int cnst = 1000000007;

	for (auto c: s)
	{
		int asc = c - 'a';
		ans = (ans + c3[asc]) % cnst;
		for (size_t i = 0; i < 26; i++)
		{
			c3[i] = (c3[i] + c2[i][asc]) % cnst;
			c2[i][asc] = (c2[i][asc] + c1[i]) % cnst;
		}
		c1[asc]++;
	}

	return ans % cnst;
}
