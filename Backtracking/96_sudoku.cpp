#include <bits/stdc++.h> 

// TC - O(9^m) where m is no of empty cells
// SC - O(1) 

bool isSafe(int row, int col, vector<vector<int>>& sudoku, int n, int val)
{

    for (int i=0; i<sudoku.size(); i++)
    {
        if (sudoku[i][col]==val or sudoku[row][i]==val)
            return false;
        
        if (sudoku[3*(row/3)+i/3][3*(col/3)+i%3] == val)
            return false;
    }
    return true;
}

bool solve3000(vector<vector<int>> &sudoku, int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (sudoku[i][j] == 0)
            {
                for (int k=1; k<=n; k++)
                {
                    if (isSafe(i, j, sudoku, n, k))
                    {
                        sudoku[i][j] = k;
                        bool isReallySafe = solve3000(sudoku, n);

                        if (isReallySafe)
                            return true;
                        else
                        {
                            sudoku[i][j] = 0;
                        }
                    }
                }
            return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
    int n = sudoku[0].size();
    bool t = solve3000(sudoku, n);
    return ;
}