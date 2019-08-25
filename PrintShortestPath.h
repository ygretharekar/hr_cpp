#pragma once
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;

class PrintShortestPath
{
public:
	void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end);
	bool possible(int n, int x, int y);
};

