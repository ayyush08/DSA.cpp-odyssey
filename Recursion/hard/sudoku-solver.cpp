// Sudoko Solver
// Create a program that fills in the blank cells in a Sudoku puzzle to solve it.

// Every sudoku solution needs to follow to these guidelines:

// 1) In every row, the numbers 1 through 9 must appear exactly once.

// 2) In every column, the numbers 1 through 9 must appear exactly once.

// 3) In each of the grid's nine 3x3 sub-boxes, the numbers 1 through 9 must appear exactly once.

// Empty cells are indicated by the '.' character.

// Examples:
// Input : board = [ ["5", "3", ".", ".", "7", ".", ".", ".", "."] , ["6", ".", ".", "1", "9", "5", ".", ".", "."] , [".", "9", "8", ".", ".", ".", ".", "6", "."] , ["8", ".", ".", ".", "6", ".", ".", ".", "3"] , ["4", ".", ".", "8", ".", "3", ".", ".", "1"] , ["7", ".", ".", ".", "2", ".", ".", ".", "6"] , [".", "6", ".", ".", ".", ".", "2", "8", "."] , [".", ".", ".", "4", "1", "9", ".", ".", "5"] , [".", ".", ".", ".", "8", ".", ".", "7", "9"] ]

// Output : [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]

// Explanation : The Input and Output boards are shown above.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFill(vector<vector<char>> &board, char digit, int row, int col)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == digit || board[i][col] == digit)
                return false;
        }

        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;
        for (int i = sr; i < sr + 3; i++)
        {
            for (int j = sc; j < sc + 3; j++)
            {
                if (board[i][j] == digit)
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char d = '1'; d <= '9'; d++)
                    {
                        if (canFill(board, d, i, j))
                        {
                            board[i][j] = d;
                            if (solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};

// Time Complexity: O(9E), where E (<= 81) is the number of empty cells.
// As each empty cell can be filled with 1 to 9 digits.

// Space Complexity: O(E), because of the recursive stack space.