// hr_cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PrintShortestPath.h"


int main()
{
	PrintShortestPath sol = PrintShortestPath();

	int ans = 0;
	sol.printShortestPath(6, 5, 1, 0, 5);





	cout << ans << std::endl;

    std::cout << "Hello World!\n";

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

/*
 * hakcerearth code arena
 * raise them bones
 /*

// Write your code here
#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

int swampThing(int n, int r, int e, map<int, vector<vector<int>>> rds)
{
	map<int, int> visited;
	map<int, int> dist;
	map<int, int> energy;
	queue<vector<int>> q;

	int en = e;
	int dd = 0;

	q.push(vector<int>{1, 0, e});

	visited[1] = 1;

	while (true)
	{
		vector<int> loc = q.front();
		q.pop();
		for (auto i : rds[loc[0]])
		{
			q.push(vector<int>{i[0], loc[1] + i[1], loc[2] - i[2]});

			if (en > loc[2] - i[2] && visited.find(i[0]) != visited.end() && visited.find(i[0]) == n) {
				en = loc[2] - i[2];
				dd = loc[1] + i[1];
			}

			if (visited.find(i[0]) == visited.end())
			{
				visited[i[0]] = 1;
			}
			else
			{
				visited[i[0]] += 1;
			}
		}

		if (q.empty()) break;
	}

	return dd;
}

int main()
{
	int n, r, e;
	cin >> n >> r >> e;

	map<int, vector<vector<int>>> rds;
	for (int i = 0; i < r; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		if (rds.find(a) == rds.end())
		{
			rds[a] = vector<vector<int>>{ vector<int>{b, c, d} };
		}
		else
		{
			auto it = rds.find(a);
			it->second.push_back(vector<int>{b, c, d});
		}
	}

	int ans = swampThing(n, r, e, rds);

	cout << ans << endl;

	return 0;
}

*/