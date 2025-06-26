// N Queen
// The challenge of arranging n queens on a n × n chessboard so that no two queens attack one another is known as the "n-queens puzzle."
// Return every unique solution to the n-queens puzzle given an integer n. The answer can be returned in any sequence.
// Every solution has a unique board arrangement for the placement of the n-queens, where 'Q' and '.' stand for a queen and an empty space, respectively.

// Examples:
// Input : n = 4
// Output : [[".Q.." , "...Q" , "Q..." , "..Q."] , ["..Q." , "Q..." , "...Q" , ".Q.."]]
// Explanation : There are two possible combinations as shown below.

// Input : n = 2
// Output : [ [] ]
// Explanation : There is no possible combination for placing two queens on a board of size 2*2.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPlaceAble(vector<string> &board, int row, int col)
    {
        int r = row, c = col;
        while (r >= 0 && c >= 0)
        {
            if (board[r][c] == 'Q')
            {
                return false;
            }
            r--;
            c--;
        }
        r = row;
        c = col;
        while (c >= 0)
        {
            if (board[r][c] == 'Q')
            {
                return false;
            }
            c--;
        }
        r = row;
        c = col;
        while (c >= 0 && r < board.size())
        {
            if (board[r][c] == 'Q')
            {
                return false;
            }
            r++;
            c--;
        }
        r = row;
        c = col;
        return true;
    }
    void func(int pos, vector<vector<string>> &ans, vector<string> &board)
    {
        if (pos == board.size())
        {
            ans.push_back(board);
            return;
        }
        for (int r = 0; r < board.size(); r++)
        {
            if (isPlaceAble(board, r, pos))
            {
                board[r][pos] = 'Q';
                func(pos + 1, ans, board);
                board[r][pos] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        // your code goes here
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        func(0, ans, board);
        return ans;
    }
};

int main()
{
    int n = 4;
    Solution obj;
    vector<vector<string>> result = obj.solveNQueens(n);
    for (const auto &solution : result)
    {
        for (const auto &row : solution)
        {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}
// Time Complexity: O(N!)
// Space Complexity: O(N^2) - The space complexity is O(N^2) because we are using a 2D vector to store the board configuration, which has N rows and N columns.