// Minimum Falling Path Sum

// Given a 2d array called matrix consisting of integer values. Return the minimum path sum that can be obtained by starting at any cell in the first row and ending at any cell in the last row.

// Movement is allowed only to the bottom, bottom-right, or bottom-left cell of the current cell.

// Examples:
// Input: matrix = [[1, 2, 10, 4], [100, 3, 2, 1], [1, 1, 20, 2], [1, 2, 2, 1]]

// Output: 6

// Explanation:

// One optimal route can be:-

// Start at 1st cell of 1st row -> bottom-right -> bottom -> bottom-left.

// Input: matrix = [[1, 4, 3, 1], [2, 3, -1, -1], [1, 1, -1, 8]]

// Output: -1

// Explanation:

// One optimal route can be:-

// Start at 4th cell of 1st row -> bottom-left -> bottom.

#include <bits/stdc++.h>
using namespace std;

// Memoization - O(n*m) time and O(n*m)+O(n) space

class Solution
{
public:
    int func(int i, int j, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (j < 0 || j >= n)
            return 1e9;
        if (i == 0)
            return matrix[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];

        int up = matrix[i][j] + func(i - 1, j, n, matrix, dp);
        int leftUp = matrix[i][j] + func(i - 1, j - 1, n, matrix, dp);
        int rightUp = matrix[i][j] + func(i - 1, j + 1, n, matrix, dp);

        return dp[i][j] = min({up, leftUp, rightUp});
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = INT_MAX;

        for (int c = 0; c < n; c++)
        {
            ans = min(ans, func(m - 1, c, n, matrix, dp));
        }
        return ans;
    }
};

// Tabulation - O(n*m) time and O(n*m) space

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = INT_MAX;

        for (int c = 0; c < n; c++)
        {
            dp[0][c] = matrix[0][c];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int up = matrix[i][j] + dp[i - 1][j];

                int leftUp = matrix[i][j];
                if (j - 1 < 0)
                    leftUp = 1e9;
                else
                    leftUp += dp[i - 1][j - 1];

                int rightUp = matrix[i][j];
                if (j + 1 >= n)
                    rightUp = 1e9;
                else
                    rightUp += dp[i - 1][j + 1];

                dp[i][j] = min({up, leftUp, rightUp});
            }
        }

        for (int c = 0; c < n; c++)
        {
            ans = min(ans, dp[m - 1][c]);
        }
        return ans;
    }
};

// Space Optimization - O(n*m) time and O(n) space

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> prev(n, 0);
        vector<int> curr(n, 0);

        for (int j = 0; j < n; j++)
            prev[j] = matrix[0][j];

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int up = matrix[i][j] + prev[j];

                int leftUp = matrix[i][j];
                if (j - 1 < 0)
                    leftUp = 1e9;
                else
                    leftUp += prev[j - 1];

                int rightUp = matrix[i][j];
                if (j + 1 >= n)
                    rightUp = 1e9;
                else
                    rightUp += prev[j + 1];

                curr[j] = min({up, leftUp, rightUp});
            }
            prev = curr;
        }
        int ans = INT_MAX;
        for (int c = 0; c < n; c++)
        {
            ans = min(ans, prev[c]);
        }
        return ans;
    }
};