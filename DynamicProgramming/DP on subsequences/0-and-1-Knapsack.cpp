// 0 and 1 Knapsack
// Given two integer arrays, val and wt, each of size N, which represent the values and weights of N items respectively, and an integer W representing the maximum capacity of a knapsack, determine the maximum value achievable by selecting a subset of the items such that the total weight of the selected items does not exceed the knapsack capacity W.

// Each item can either be picked in its entirety or not picked at all (0-1 property). The goal is to maximize the sum of the values of the selected items while keeping the total weight within the knapsack's capacity.

// Examples:
// Input: val = [60, 100, 120], wt = [10, 20, 30], W = 50

// Output: 220

// Explanation: Select items with weights 20 and 30 for a total value of 100 + 120 = 220.

// Input: val = [10, 40, 30, 50], wt = [5, 4, 6, 3], W = 10

// Output: 90

// Explanation: Select items with weights 4 and 3 for a total value of 40 + 50 = 90.

#include <bits/stdc++.h>
using namespace std;

// Memoization - O(N*W) time, O(N*W) + O(N) space

class Solution
{
public:
    int func(int i, int w, vector<vector<int>> &dp, vector<int> &wt, vector<int> &val)
    {
        if (i == 0)
        {
            if (wt[i] <= w)
                return val[i];
            else
                return 0;
        }
        if (dp[i][w] != -1)
            return dp[i][w];
        int notTake = func(i - 1, w, dp, wt, val);
        int take = INT_MIN;
        if (wt[i] <= w)
            take = val[i] + func(i - 1, w - wt[i], dp, wt, val);

        int mx = max(take, notTake);

        return dp[i][w] = mx;
    }
    int knapsack01(vector<int> &wt, vector<int> &val, int n, int W)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return func(n - 1, W, dp, wt, val);
    }
};

// Tabulation - O(N*W) time, O(N*W) space

class Solution
{
public:
    int knapsack01(vector<int> &wt, vector<int> &val, int n, int W)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        for (int i = wt[0]; i <= W; i++)
            dp[0][i] = val[0];
        for (int i = 1; i < n; i++)
        {
            for (int w = 0; w <= W; w++)
            {
                int notTake = dp[i - 1][w];
                int take = INT_MIN;
                if (wt[i] <= w)
                    take = val[i] + dp[i - 1][w - wt[i]];
                dp[i][w] = max(take, notTake);
            }
        }
        return dp[n - 1][W];
    }
};

// Space Optimization - O(N*W) time, O(W) space

class Solution
{
public:
    int knapsack01(vector<int> &wt, vector<int> &val, int n, int W)
    {
        vector<int> prev(W + 1, 0);
        for (int i = wt[0]; i <= W; i++)
            prev[i] = val[0];
        for (int i = 1; i < n; i++)
        {
            for (int w = W; w >= 0; w--)
            {
                int notTake = prev[w];
                int take = INT_MIN;
                if (wt[i] <= w)
                    take = val[i] + prev[w - wt[i]];
                prev[w] = max(take, notTake);
            }
        }
        return prev[W];
    }
};
