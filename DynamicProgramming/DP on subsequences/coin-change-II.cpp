// Coin change II
// Give an array coins of n integers representing coin denominations. Your task is to find the number of distinct combinations that sum up to a specified amount of money. If it's impossible to achieve the exact amount with any combination of coins, return 0.

// Single coin can be used any number of times.

// Return your answer with modulo 109+7.

// Examples:
// Input: coins = [2, 4,10], amount = 10

// Output: 4

// Explanation: The four combinations are:

// 10 = 10

// 10 = 4 + 4 + 2

// 10 = 4 + 2 + 2 + 2

// 10 = 2 + 2 + 2 + 2 + 2

// Input: coins = [5], amount = 5

// Output: 1

// Explanation: There is one combination: 5 = 5.

// Memoization - O(N*amount) time, O(N*amount) + O(N) space

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int m = 1e9 + 7;
    int func(int i, int target, vector<vector<int>> &dp, vector<int> &coins)
    {
        if (i == 0)
        {
            return target % coins[i] == 0;
        }
        if (dp[i][target] != -1)
            return dp[i][target];

        int notTake = func(i - 1, target, dp, coins);
        int take = 0;
        if (target >= coins[i])
            take = func(i, target - coins[i], dp, coins);

        return dp[i][target] = (take + notTake) % m;
    }
    int count(vector<int> &coins, int n, int amount)
    {

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return func(n - 1, amount, dp, coins);
    }
};

// Tabulation - O(N*amount) time, O(N*amount) space

class Solution
{
public:
    int m = 1e9 + 7;
    int count(vector<int> &coins, int n, int amount)
    {
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
            {
                dp[0][i] = 1;
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int target = 0; target <= amount; target++)
            {
                int notTake = dp[i - 1][target];
                int take = 0;
                if (target >= coins[i])
                    take = dp[i][target - coins[i]];

                dp[i][target] = (take + notTake) % m;
            }
        }
        return dp[n - 1][amount];
    }
};

// Space Optimization - O(N*amount) time, O(amount) space

class Solution
{
public:
    int m = 1e9 + 7;
    int count(vector<int> &coins, int n, int amount)
    {
        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1, 0);
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
            {
                prev[i] = 1;
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int target = 0; target <= amount; target++)
            {
                int notTake = prev[target];
                int take = 0;
                if (target >= coins[i])
                    take = curr[target - coins[i]];

                curr[target] = (take + notTake) % m;
            }
            prev = curr;
        }
        return prev[amount];
    }
};
