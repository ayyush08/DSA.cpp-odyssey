// 1411. Number of Ways to Paint N × 3 Grid
// Hard
// You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).

// Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.

// Example 1:

// Input: n = 1
// Output: 12
// Explanation: There are 12 possible way to paint the grid as shown.
// Example 2:

// Input: n = 5000
// Output: 30228214

// Constraints:

// n == grid.length
// 1 <= n <= 5000

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    int N;
    int func(vector<vector<vector<vector<int>>>> &dp, int i, int c1, int c2, int c3)
    {
        if (i == 0)
        {
            return c1 != c2 && c2 != c3;
        }
        if (dp[i][c1][c2][c3] != -1)
            return dp[i][c1][c2][c3];

        long long ways = 0;

        for (int red = 0; red < 3; red++)
        {
            for (int yellow = 0; yellow < 3; yellow++)
            {
                for (int green = 0; green < 3; green++)
                {
                    if (red == yellow || yellow == green)
                        continue;
                    if (red == c1 || yellow == c2 || green == c3)
                        continue;

                    ways = (ways + func(dp, i - 1, red, yellow, green)) % mod;
                }
            }
        }
        return dp[i][c1][c2][c3] = ways;
    }
    int numOfWays(int n)
    {
        N = n;
        vector<vector<vector<vector<int>>>> dp(
            n, vector<vector<vector<int>>>(
                   3, vector<vector<int>>(3, vector<int>(3, -1))));
        long long ways = 0;
        for (int red = 0; red < 3; red++)
        {
            for (int yellow = 0; yellow < 3; yellow++)
            {
                for (int green = 0; green < 3; green++)
                {
                    if (red != yellow && yellow != green)
                    {
                        ways = (ways + func(dp, n - 1, red, yellow, green)) % mod;
                    }
                }
            }
        }
        return ways;
    }
};