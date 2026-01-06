// 1444. Number of Ways of Cutting a Pizza

// Hard

// Hint
// Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts.

// For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.

// Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.

// Example 1:

// Input: pizza = ["A..","AAA","..."], k = 3
// Output: 3
// Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.
// Example 2:

// Input: pizza = ["A..","AA.","..."], k = 3
// Output: 1
// Example 3:

// Input: pizza = ["A..","A..","..."], k = 1
// Output: 1

// Constraints:

// 1 <= rows, cols <= 50
// rows == pizza.length
// cols == pizza[i].length
// 1 <= k <= 10
// pizza consists of characters 'A' and '.' only.

#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(m * n * k * (m + n)) where m is the number of rows and n is the number of columns in the pizza.
//Space Complexity: O(m * n * k) for the dp and apples array.

class Solution
{
public:
    int m, n;
    int dp[55][55][15];
    int apples[55][55];
    long long MOD = 1e9 + 7;

    int solve(int i, int j, int k)
    {

        if (apples[i][j] < k)
            return 0;

        if (k == 1)
        {
            return (apples[i][j] >= 1) ? 1 : 0;
        }
        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        dp[i][j][k] = 0;

        for (int h = i + 1; h < m; h++)
        {

            if (apples[i][j] - apples[h][j] > 0 && apples[h][j] >= k - 1)
            {

                dp[i][j][k] =
                    (dp[i][j][k] % MOD + solve(h, j, k - 1) % MOD) % MOD;
            }
        }

        for (int v = j + 1; v < n; v++)
        {

            if (apples[i][j] - apples[i][v] > 0 && apples[i][v] >= k - 1)
            {
                dp[i][j][k] =
                    (dp[i][j][k] % MOD + solve(i, v, k - 1) % MOD) % MOD;
            }
        }

        return dp[i][j][k];
    }

    int ways(vector<string> &pizza, int k)
    {
        m = pizza.size();
        n = pizza[0].length();

        memset(apples, 0, sizeof(apples));

        for (int i = m - 1; i >= 0; i--)
        {

            for (int j = n - 1; j >= 0; j--)
            {

                apples[i][j] = apples[i][j + 1];

                for (int l = i; l < m; l++)
                {
                    apples[i][j] += (pizza[l][j] == 'A');
                }
            }
        }
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, k);
    }
};