// hr_cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ConnectedCellsInAGrid.h"


int main()
{
	ConnectedCellsInAGrid sol = ConnectedCellsInAGrid();

	int ans = sol.connectedCell(
		vector<vector<int>> {
			vector<int>{1, 1, 0, 0, 0},
			vector<int>{0, 1, 1, 0, 0},
			vector<int>{0, 0, 1, 0, 1},
			vector<int>{1, 0, 0, 0, 1},
			vector<int>{0, 1, 0, 1, 1}
		}
	);

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
