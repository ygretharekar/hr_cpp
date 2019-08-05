// hr_cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GridlandMetro.h"



int main()
{
	GridlandMetro sol = GridlandMetro();

	/*
	4 5 7
1 1 2
1 4 4
2 1 2
2 2 3
2 4 5
4 1 2
4 4 5
	*/


	std::vector<vector<int>> inp{ 
		//vector<int>{4, 5, 7},
		vector<int>{1, 1, 2},
		vector<int>{1, 4, 4},
		vector<int>{2, 1, 2},
		vector<int>{2, 2, 3},
		vector<int>{2, 4, 5},
		vector<int>{4, 1, 2},
		vector<int>{4, 4, 5},
	};
	//std::vector<vector<int>> inp{ 
	//	//vector<int>{4, 5, 7},
	//	vector<int>{1, 3, 6},
	//	vector<int>{1, 2, 4},
	//	vector<int>{1, 1, 1},
	//	vector<int>{1, 7, 7},
	//	vector<int>{1, 4, 5},
	//	vector<int>{1, 1, 8},
	//	//vector<int>{4, 4, 5},
	//};

	cout << sol.gridlandMetro(4, 5, 7, inp) << std::endl;

    std::cout << "Hello World!\n";
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
