#pragma once
#include<vector>
#include<map>
#include<string>

#include "pch.h"

using namespace std;

class CountLuck
{
	int tb[4] = {0, 0, 1, -1};
	int rl[4] = {1, -1, 0, 0};
	bool found = false;
	int cnt = 0;
public:
	string countLuck(vector<string> matrix, int k);
	bool wand(vector<string> &matrix, int s_i, int s_j, int n, int m);
	//int wand(vector<string> &matrix, int s_i, int s_j, int n, int m);
	bool canGo(vector<string> &matrix, int s_i, int s_j, int n, int m);
};

