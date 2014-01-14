#include <vector>
#include <iostream>

using namespace std;

class sudoku
{
public:
	sudoku(vector <vector<int>> input) 
	{
		if (input.size() != 9)
		{
			cerr << "Error not 9x9 grid" << endl;
			cin.get();
		}
		for (auto& vec : input)
		{
			if (vec.size() != 9)
			{
				cerr << "Error not 9x9 grid" << endl;
				cin.get();
			}
			grid.push_back(vec);
		}
	}
	bool check_sudoku(vector<vector<int>> Tgrid);
	bool solve_sudoku();
	bool try_grid(vector<vector<int>> &t, int row, int col);
	bool done(vector<vector<int>> Tgrid);
	void copyVec(vector<vector<int>> &v, vector<vector<int>> &t);
	bool find_Z(vector<vector<int>> t, int &row, int &col);
	void print_grid();

private:
	vector<vector<int>> grid;
	bool check_Arr(vector <int> v);
	void print_grid(vector<vector<int>> &t);

};

bool sudoku::check_sudoku(vector<vector<int>> Tgrid)
{
	vector<int> row, colmn;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			row.push_back(Tgrid[i][j]);
			colmn.push_back(Tgrid[j][i]);
		}
		if (!check_Arr(row) || !check_Arr(colmn))
			return false;
		row.clear();
		colmn.clear();
	}

	for (int x1 = 0; x1 < 3; x1++) //check 3x3 subgrids
	{
		for (int y1 = 0; y1 < 3; y1++)
		{
			int x = x1 * 3;
			int y = y1 * 3;
			row.push_back(Tgrid[x][y]);
			row.push_back(Tgrid[x][y + 1]);
			row.push_back(Tgrid[x][y + 2]);
			row.push_back(Tgrid[x + 1][y]);
			row.push_back(Tgrid[x + 1][y + 1]);
			row.push_back(Tgrid[x + 1][y + 2]);
			row.push_back(Tgrid[x + 2][y]);
			row.push_back(Tgrid[x + 2][y + 1]);
			row.push_back(Tgrid[x + 2][y + 2]);
			if (!check_Arr(row))
				return false;
			row.clear();
		}
	}
	return true;
}

bool sudoku::check_Arr(vector<int> v) 
{
	int valid[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto& i : v)
	{
		if (i < 0 || i > 9)
			return false;
		else if (i == 0)
			continue;
		else if (valid[i - 1] == -1)
			return false;
		else valid[i - 1] = -1;
	}
	return true;
}

bool sudoku::solve_sudoku()
{
	
	if (done(grid))
	{
		if (!check_sudoku(grid))
			return false;
	}
	vector<vector<int>> tempGrid;
	copyVec(grid, tempGrid);
	int row = 0, col = 0;

	if (try_grid(tempGrid, row, col))
	{
		copyVec(tempGrid, grid);
		return true;
	}
	else return false; //no solution found

}

bool sudoku::try_grid(vector<vector<int>> &t, int row, int col)
{
	if (!check_sudoku(t))
	{
		t[row][col] = 0; //backtrack
		return false;
	}
	if (done(t))
		return true;
	
	int startRow = row, startCol = col;
	while (find_Z(t, row, col))
	{
		for (int i = 1; i <= 9; i++)
		{
			t[row][col] = i;
			if (try_grid(t, row, col))
			{
				return true;
			}
			else t[row][col] = 0;
		}
		return false;
	}
}

bool sudoku::find_Z(vector<vector<int>> t, int &row, int &col)
{
	for (row = 0; row < 9; row++)
	{
		for (col = 0; col < 9; col++)
		{
			if (t[row][col] == 0)
				return true;
		}
	}
	return false;
}

void sudoku::copyVec(vector<vector<int>> &v, vector<vector<int>> &t)
{
	t.clear();
	for (auto& i : v)
		t.push_back(i);
}

bool sudoku::done(vector<vector<int>> Tgrid)
{
	for (auto& x : Tgrid)
	{
		for (auto& y : x)
			if (y == 0)
				return false;
	}
	return true;
}

void sudoku::print_grid()
{
	for (auto& x : grid)
	{
		for (auto& y : x)
			cout << y << " ";
		cout << endl;
	}
}

void sudoku::print_grid(vector<vector<int>> &t)
{
	for (auto& x : t)
	{
		for (auto& y : x)
			cout << y << " ";
		cout << endl;
	}
	cout << endl;
}
