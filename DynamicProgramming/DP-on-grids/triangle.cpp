// Triangle

// Given a 2d integer array named triangle with n rows. Its first row has 1 element and each succeeding row has one more element in it than the row above it.

// Return the minimum falling path sum from the first row to the last.

// Movement is allowed only to the bottom or bottom-right cell from the current cell.

// Examples:
// Input: triangle = [[1], [1, 2], [1, 2, 4]]

// Output: 3

// Explanation:

// One possible route can be:

// Start at 1st row -> bottom -> bottom.

// Input: triangle = [[1], [4, 7], [4,10, 50], [-50, 5, 6, -100]]

// Output: -42

// Explanation:

// One possible route can be:

// Start at 1st row -> bottom-right -> bottom-right -> bottom-right

#include <bits/stdc++.h>
using namespace std;

// Memoization  - O(n^2) due to visiting each cell in the DP table once. Space Complexity:O(n^2) for the DP table and O(n) for the recursion call stack.

class Solution
{
public:
    int func(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == m - 1)
            return triangle[m - 1][j];

        int down = triangle[i][j] + func(i + 1, j, triangle, dp);
        int diagonal = triangle[i][j] + func(i + 1, j + 1, triangle, dp);

        return dp[i][j] = min(down, diagonal);
    }
    int minTriangleSum(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return func(0, 0, triangle, dp);
    }
};

// Tabulation - O(n^2) time complexity due to the nested loops iterating over the DP table. Space Complexity:O(n^2) for the DP table.

class Solution
{
public:
    int minTriangleSum(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int b = 0; b < n; b++)
        {
            dp[n - 1][b] = triangle[n - 1][b];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min(down, diagonal);
            }
        }
        return dp[0][0];
    }
};

// Space Optimization - O(n^2) time complexity due to the nested loops iterating over the DP table. Space Complexity:O(n) for the two 1D arrays used to store the current and previous rows of the DP table.

class Solution
{
public:
    int minTriangleSum(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> prev(n, -1);
        vector<int> curr(n, -1);
        for (int b = 0; b < n; b++)
        {
            prev[b] = triangle[n - 1][b];
        }

        for (int i = n - 2; i >= 0; i--)
        {

            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + prev[j];
                int diagonal = triangle[i][j] + prev[j + 1];

                curr[j] = min(down, diagonal);
            }
            prev = curr;
        }
        return prev[0];
    }
};