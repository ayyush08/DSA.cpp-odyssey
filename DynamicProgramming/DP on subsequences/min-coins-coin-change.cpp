// Minimum coins
// Given an integer array of coins representing coins of different denominations and an integer amount representing a total amount of money. Return the fewest number of coins that are needed to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1. There are infinite numbers of coins of each type

// Examples:
// Input: coins = [1, 2, 5], amount = 11

// Output: 3

// Explanation: 11 = 5 + 5 + 1. We need 3 coins to make up the amount 11.

// Input: coins = [2, 5], amount = 3

// Output: -1

// Explanation: It's not possible to make amount 3 with coins 2 and 5. Since we can't combine the coin 2 and 5 to make the amount 3, the output is -1.

#include <bits/stdc++.h>
using namespace std;

// Memoization - O(N*amount) time, O(N*amount) + O(N) space

class Solution
{
public:
    int func(int i, int target, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            if (target % coins[i] == 0)
                return target / coins[i];
            else
                return 1e9;
        }
        if (dp[i][target] != -1)
            return dp[i][target];

        int notTake = 0 + func(i - 1, target, coins, dp);
        int take = 1e9;
        if (coins[i] <= target)
            take = 1 + func(i, target - coins[i], coins, dp);

        return dp[i][target] = min(take, notTake);
    }
    int MinimumCoins(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = func(n - 1, amount, coins, dp);
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};

// Tabulation - O(N*amount) time, O(N*amount) space

class Solution
{
public:
    int MinimumCoins(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
                dp[0][i] = 1e9;
        }

        for (int i = 1; i < n; i++)
        {
            for (int target = 0; target <= amount; target++)
            {
                int notTake = dp[i - 1][target];
                int take = 1e9;
                if (coins[i] <= target)
                    take = 1 + dp[i][target - coins[i]];

                dp[i][target] = min(take, notTake);
            }
        }
        if (dp[n - 1][amount] >= 1e9)
            return -1;
        return dp[n - 1][amount];
    }
};

// Space Optimization - O(N*amount) time, O(amount) space

class Solution
{
public:
    int MinimumCoins(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1, 0);
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                prev[i] = i / coins[0];
            else
                prev[i] = 1e9;
        }

        for (int i = 1; i < n; i++)
        {
            for (int target = 0; target <= amount; target++)
            {
                int notTake = prev[target];
                int take = 1e9;
                if (coins[i] <= target)
                    take = 1 + curr[target - coins[i]];

                curr[target] = min(take, notTake);
            }
            prev = curr;
        }
        if (prev[amount] >= 1e9)
            return -1;
        return prev[amount];
    }
};