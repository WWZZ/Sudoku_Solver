#include "sudoku.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<vector<int>> grid1 =
	{ { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
	};

	vector<vector<int>> subg =
	{ { 9, 8, 7, 6, 5, 4, 3, 2, 1 },
	{ 8, 7, 6, 5, 4, 3, 2, 1, 9 },
	{ 7, 6, 5, 4, 3, 2, 1, 9, 8 },
	{ 6, 5, 4, 3, 2, 1, 9, 8, 7 },
	{ 5, 4, 3, 2, 1, 9, 8, 7, 6 },
	{ 4, 3, 2, 1, 9, 8, 7, 6, 5 },
	{ 3, 2, 1, 9, 8, 7, 6, 5, 4 },
	{ 2, 1, 9, 8, 7, 6, 5, 4, 3 },
	{ 1, 9, 8, 7, 6, 5, 4, 3, 2 }
	};
	vector<vector<int>> easy =
	{ { 2, 9, 0, 0, 0, 0, 0, 7, 0 },
	{ 3, 0, 6, 0, 0, 8, 4, 0, 0 },
	{ 8, 0, 0, 0, 4, 0, 0, 0, 2 },
	{ 0, 2, 0, 0, 3, 1, 0, 0, 7 },
	{ 0, 0, 0, 0, 8, 0, 0, 0, 0 },
	{ 1, 0, 0, 9, 5, 0, 0, 6, 0 },
	{ 7, 0, 0, 0, 9, 0, 0, 0, 1 },
	{ 0, 0, 1, 2, 0, 0, 3, 0, 6 },
	{ 0, 3, 0, 0, 0, 0, 0, 5, 9 }
	};

	vector<vector<int>> hard =
	{ { 1, 0, 0, 0, 0, 7, 0, 9, 0 },
	{ 0, 3, 0, 0, 2, 0, 0, 0, 8 },
	{ 0, 0, 9, 6, 0, 0, 5, 0, 0 },
	{ 0, 0, 5, 3, 0, 0, 9, 0, 0 },
	{ 0, 1, 0, 0, 8, 0, 0, 0, 2 },
	{ 6, 0, 0, 0, 0, 4, 0, 0, 0 },
	{ 3, 0, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 4, 0, 0, 0, 0, 0, 0, 7 },
	{0, 0, 7, 0, 0, 0, 3, 0, 0}
	};

	sudoku su1(hard);
	cout << su1.solve_sudoku() << endl;
	su1.print_grid();



	cin.get();
	return 0;
}