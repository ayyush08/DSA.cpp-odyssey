// Rod cutting problem

// Given a rod of length N inches and an array price[] where price[i] denotes the value of a piece of rod of length i inches (1-based indexing). Determine the maximum value obtainable by cutting up the rod and selling the pieces. Make any number of cuts, or none at all, and sell the resulting pieces.

// Examples:
// Input: price = [1, 6, 8, 9, 10, 19, 7, 20], N = 8

// Output: 25

// Explanation: Cut the rod into lengths of 2 and 6 for a total price of 6 + 19= 25.

// Input: price = [1, 5, 8, 9], N = 4

// Output: 10

// Explanation: Cut the rod into lengths of 2 and 2 for a total price of 5 + 5 = 10.

#include <bits/stdc++.h>
using namespace std;

// Memoization - O(N*N) time, O(N*N) + O(N) space

class Solution
{
public:
    int func(int i, int target, vector<int> &price, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            return (target * price[0]);
        }
        if (dp[i][target] != -1)
            return dp[i][target];
        int notTake = func(i - 1, target, price, dp);
        int take = -1e9;
        if (target >= (i + 1))
            take = price[i] + func(i, target - (i + 1), price, dp);

        return dp[i][target] = max(take, notTake);
    }
    int rodCutting(vector<int> price, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return func(n - 1, n, price, dp);
    }
};

// Tabulation - O(N*N) time, O(N*N) space

class Solution
{
public:
    int rodCutting(vector<int> price, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = price[0] * i;
        }

        for (int i = 1; i < n; i++)
        {
            for (int target = 0; target <= n; target++)
            {
                int notTake = dp[i - 1][target];
                int take = -1e9;
                if (target >= (i + 1))
                    take = price[i] + dp[i][target - (i + 1)];

                dp[i][target] = max(take, notTake);
            }
        }

        return dp[n - 1][n];
    }
};

// Space Optimization - O(N*N) time, O(N) space

class Solution
{
public:
    int rodCutting(vector<int> price, int n)
    {
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            prev[i] = price[0] * i;
        }

        for (int i = 1; i < n; i++)
        {
            for (int target = 0; target <= n; target++)
            {
                int notTake = prev[target];
                int take = -1e9;
                if (target >= (i + 1))
                    take = price[i] + curr[target - (i + 1)];

                curr[target] = max(take, notTake);
            }
            prev = curr;
        }

        return prev[n];
    }
};
