#pragma once

#include<vector>
#include<map>
#include<string>
#include<queue>
#include<algorithm>


using namespace std;

class GenaPlayingHanoi
{
public:
	int genaPlayingHanoi(int n, vector<int> a);
	unsigned move(unsigned state, int disc, int rod);
	int getMin(int n, unsigned state);
	int getDisc(int rod, int n, unsigned state);
};

