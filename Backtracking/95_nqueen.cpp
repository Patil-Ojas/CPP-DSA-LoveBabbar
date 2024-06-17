#include <bits/stdc++.h> 

// a more optimized approach is by using hashmaps, for rows its easy for diagnoals is using (row+col) indice, lower and upper diagonal separate, one hashmap each


void fillans(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
	vector<int> temp;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{	
	int x = row;
	int y = col;

	// checking col
	while (y>=0)
	{
		if (board[x][y]==1)
			return false;
		y--;
	}

	x = row;
	y = col;

	// check up diagonal
	while (x>=0 and y>=0)
	{
		if (board[x][y]==1)
			return false;
		x--;
		y--;
	}

	x = row;
	y = col;
	// check down diagonal
	while (x<n and y>=0)
	{
		if (board[x][y]==1)
			return false;
		x++;
		y--;
	}

	return true;
}

void solve3000(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
	// base case
	if (col==n)
	{
		fillans(board, ans, n);
		return ;
	}

	// go thru all rows
	for (int row=0; row<n; row++)
	{
		if (isSafe(row, col, board, n))
		{
			board[row][col] = 1;
			solve3000(col+1, board, ans, n);
			board[row][col] = 0;
		}
	}
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n, vector<int>(n, 0));
	vector<vector<int>> ans;


	solve3000(0, board, ans, n);

	return ans;
}