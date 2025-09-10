// Unique paths II
// Given an m x n 2d array named matrix, where each cell is either 0 or 1. Return the number of unique ways to go from the top-left cell (matrix[0][0]) to the bottom-right cell (matrix[m-1][n-1]). A cell is blocked if its value is 1, and no path is possible through that cell.

// Movement is allowed in only two directions from a cell - right and bottom.

// Examples:
// Input: matrix = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]

// Output: 2

// Explanation:

// The two possible paths are:

// 1) down -> down-> right -> right

// 2) right -> right -> down -> down

// Input: matrix = [[0, 0, 0], [0, 0, 1], [0, 1, 0]]

// Output: 0

// Explanation:

// There is no way to reach the bottom-right cell.

#include <bits/stdc++.h>
using namespace std;

// Memoization - O(m*n) time and O(m*n)+O(m+n) space
class Solution
{
public:
    int func(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j)
    {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;
        if (matrix[i][j] == 1)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int up = func(matrix, dp, i - 1, j);
        int left = func(matrix, dp, i, j - 1);

        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        if (matrix[0][0] == 1)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return func(matrix, dp, m - 1, n - 1);
    }
};

// Tabulation - O(m*n) time and O(m*n) space

class Solution2
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        if (matrix[0][0] == 1)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }
                int up = 0, left = 0;
                if (matrix[i][j] == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];

        // return func(matrix,dp, m - 1, n - 1);
    }
};