// Unbounded knapsack

// Given two integer arrays, val and wt, each of size N, representing the values and weights of N items respectively, and an integer W, representing the maximum capacity of a knapsack, determine the maximum value achievable by selecting a subset of the items such that the total weight of the selected items does not exceed the knapsack capacity W. The goal is to maximize the sum of the values of the selected items while keeping the total weight within the knapsack's capacity.

// An infinite supply of each item can be assumed.

// Examples:
// Input: val = [5, 11, 13], wt = [2, 4, 6], W = 10

// Output: 27

// Explanation: Select 2 items with weights 4 and 1 item with weight 2 for a total value of 11+11+5 = 27.

// Input: val = [10, 40, 50, 70], wt = [1, 3, 4, 5], W = 8

// Output: 110

// Explanation: Select items with weights 3 and 5 for a total value of 40 + 70 = 110.

#include <bits/stdc++.h>
using namespace std;

// Memoization - O(N*W) time, O(N*W) + O(N) space

class Solution
{
public:
    int func(int i, int target, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            return val[i] * (target / wt[i]);
        }
        if (dp[i][target] != -1)
            return dp[i][target];
        int notTake = func(i - 1, target, wt, val, dp);
        int take = -1e9;
        if (target >= wt[i])
            take = val[i] + func(i, target - wt[i], wt, val, dp);

        return dp[i][target] = max(take, notTake);
    }
    int unboundedKnapsack(vector<int> &wt, vector<int> &val, int n, int W)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return func(n - 1, W, wt, val, dp);
    }
};

// Tabulation - O(N*W) time, O(N*W) space

class Solution
{
public:
    int unboundedKnapsack(vector<int> &wt, vector<int> &val, int n, int W)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        for (int i = wt[0]; i <= W; i++)
        {
            dp[0][i] = val[0] * (i / wt[0]);
        }
        for (int i = 1; i < n; i++)
        {
            for (int target = 0; target <= W; target++)
            {
                int notTake = dp[i - 1][target];
                int take = -1e9;
                if (target >= wt[i])
                    take = val[i] + dp[i][target - wt[i]];

                dp[i][target] = max(take, notTake);
            }
        }
        return dp[n - 1][W];
    }
};

// Space Optimization - O(N*W) time, O(W) space

class Solution
{
public:
    int unboundedKnapsack(vector<int> &wt, vector<int> &val, int n, int W)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        vector<int> prev(W + 1, 0);
        vector<int> curr(W + 1, 0);
        for (int i = wt[0]; i <= W; i++)
        {
            prev[i] = val[0] * (i / wt[0]);
        }
        for (int i = 1; i < n; i++)
        {
            for (int target = 0; target <= W; target++)
            {
                int notTake = prev[target];
                int take = -1e9;
                if (target >= wt[i])
                    take = val[i] + curr[target - wt[i]];

                curr[target] = max(take, notTake);
            }
            prev = curr;
        }
        return prev[W];
    }
};
