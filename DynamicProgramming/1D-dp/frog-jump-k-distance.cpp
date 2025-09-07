// Frog jump with K distances
// A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k.

// To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists. Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.

// Examples:
// Input: heights = [10, 5, 20, 0, 15], k = 2

// Output: 15

// Explanation:

// 0th step -> 2nd step, cost = abs(10 - 20) = 10

// 2nd step -> 4th step, cost = abs(20 - 15) = 5

// Total cost = 10 + 5 = 15.

// Input: heights = [15, 4, 1, 14, 15], k = 3

// Output: 2

// Explanation:

// 0th step -> 3rd step, cost = abs(15 - 14) = 1

// 3rd step -> 4th step, cost = abs(14 - 15) = 1

// Total cost = 1 + 1 = 2.

#include <bits/stdc++.h>
using namespace std;

// Memoization

class Solution
{
public:
    int func(int i, vector<int> &heights, int k, vector<int> &dp)
    {
        if (i == 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int steps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {

            if (i - j >= 0)
            {
                int jumpStep = func(i - j, heights, k, dp) + abs(heights[i] - heights[i - j]);
                steps = min(jumpStep, steps);
            }
        }
        return dp[i] = steps;
    }
    int frogJump(vector<int> &heights, int k)
    {
        int n = heights.size();
        vector<int> dp(n, -1);

        return func(n - 1, heights, k, dp);
    }
};

// Tabulation

class Solution
{
public:
    int frogJump(vector<int> &heights, int k)
    {
        int n = heights.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int steps = INT_MAX;
            for (int j = 1; j <= k; j++)
            {
                if (i - j >= 0)
                {
                    int jumpStep = dp[i - j] + abs(heights[i] - heights[i - j]);
                    steps = min(jumpStep, steps);
                    dp[i] = steps;
                }
            }
        }
        return dp[n - 1];
    }
};


// Space Optimization - Not needed as we can only reduce space to O(k) which is not significant because k can be equal to n in worst case. but the intuition would be to store last k states and use them to calculate the current state.