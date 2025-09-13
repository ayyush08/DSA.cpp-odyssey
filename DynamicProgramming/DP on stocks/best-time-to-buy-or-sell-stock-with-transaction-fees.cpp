// Best time to buy and sell stock with transaction fees

// Given an array arr where arr[i] represents the price of a given stock on the ith day. Additionally, you are given an integer fee representing a transaction fee for each trade. The task is to determine the maximum profit you can achieve such that you need to pay a transaction fee for each buy and sell transaction. The Transaction Fee is applied when you sell a stock.

// You may complete as many transactions. You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before buying again).

// Examples:
// Input: arr = [1, 3, 4, 0, 2], fee = 1

// Output: 3

// Explanation: Buy at day 1, sell at day 3, then, buy at day 4, sell at day 5.

// Profit calculation: ((4 - 1) - 1) + ((2 - 0) - 1) = 2 + 1 = 3.

// Input: arr = [1, 3, 2, 8, 4, 9], fee = 2

// Output: 8

// Explanation: Buy at day 1 (price = 1), sell at day 4 (price = 8), then Buy at day 5 (price = 4), sell at day 6 (price = 9),

// Profit calculation: ((9 - 4) - 2) + ((8 - 1) - 2)= 8.

#include <bits/stdc++.h>
using namespace std;

// Memoization - O(n^2)+O(n) Space

class Solution
{
public:
    int buse(vector<vector<int>> &dp, vector<int> &prices, int buyorsell, int i, int fee)
    {
        if (i == prices.size())
        {
            return 0;
        }
        if (dp[i][buyorsell] != -1)
            return dp[i][buyorsell];

        if (buyorsell)
        {
            int buy = -prices[i] + buse(dp, prices, 0, i + 1, fee);
            int dont_buy = buse(dp, prices, 1, i + 1, fee);
            return dp[i][buyorsell] = max(buy, dont_buy);
        }
        else
        {
            int sell = prices[i] + buse(dp, prices, 1, i + 1, fee);
            int dont_sell = buse(dp, prices, 0, i + 1, fee);
            return dp[i][buyorsell] = max(sell - fee, dont_sell);
        }
        return dp[i][buyorsell];
    }

    int stockBuySell(vector<int> arr, int n, int fee)
    {
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return buse(dp, arr, 1, 0, fee);
    }
};

// Tabulation - O(n^2) Space

class Solution
{
public:
    int stockBuySell(vector<int> &prices, int n, int fee)
    {
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                {
                    dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                }
                else
                {
                    dp[i][buy] = max(prices[i] - fee + dp[i + 1][1], dp[i + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
};
