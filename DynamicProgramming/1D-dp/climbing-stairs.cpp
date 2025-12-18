// Climbing stairs
// Given an integer n, there is a staircase with n steps, starting from the 0th step. Determine the number of unique ways to reach the nth step, given that each move can be either 1 or 2 steps at a time.

// Examples:
// Input: n = 2

// Output: 2

// Explanation: There are 2 unique ways to climb to the 2nd step:

// 1) 1 step + 1 step

// 2) 2 steps

// Input: n = 3

// Output: 3

// Explanation: There are 3 unique ways to climb to the 3rd step:

// 1) 1 step + 1 step + 1 step

// 2) 2 steps + 1 step

// 3) 1 step + 2 steps
w    s
#include <bits/stdc++.h>
using namespace std;

// Memoization

class Solution
{
public:
    int func(vector<int> &dp, int n)
    {
        if (n <= 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];

        return dp[n] = func(dp, n - 1) + func(dp, n - 2);
    }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);

        return func(dp, n);
    }
};

// Tabulation

class Solution2
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);

        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};