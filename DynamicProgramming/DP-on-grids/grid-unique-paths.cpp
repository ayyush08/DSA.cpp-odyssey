// Grid unique paths
// Given two integers m and n, representing the number of rows and columns of a 2d array named matrix. Return the number of unique ways to go from the top-left cell (matrix[0][0]) to the bottom-right cell (matrix[m-1][n-1]).

//  Movement is allowed only in two directions from a cell: right and bottom.

// Examples:
// Input: m = 3, n = 2

// Output: 3

// Explanation: There are 3 unique ways to go from the top left to the bottom right cell.

// 1) right -> down -> down

// 2) down -> right -> down

// 3) down -> down -> right

// Input: m = 2, n = 4

// Output: 4

// Explanation: There are 4 unique ways to go from the top left to the bottom right cell.

// 1) down -> right -> right -> right

// 2) right -> down -> right -> right

// 3) right -> right -> down -> right

// 4) right -> right -> right -> down

#include <bits/stdc++.h>
using namespace std;

// Memoization - O(m*n) time and O(m*n)+O(m+n) space
class Solution
{
public:
    int func(vector<vector<int>> &dp, int i, int j)
    {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int up = func(dp, i - 1, j);
        int left = func(dp, i, j - 1);

        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return func(dp, m - 1, n - 1);
    }
};

// Tabulation - O(m*n) time and O(m*n) space

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
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
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }
};


// Space Optimization - O(m*n) time and O(n) space

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    curr[j] = 1;
                    continue;
                }
                int up = 0, left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];

                curr[j] = up + left;
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};