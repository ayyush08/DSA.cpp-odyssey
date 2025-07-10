// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int buse(vector<vector<int>> &dp, vector<int> &prices, int buyorsell, int i)
    {
        if (i == prices.size())
        {
            return 0;
        }
        if (dp[i][buyorsell] != -1)
            return dp[i][buyorsell];

        if (buyorsell)
        {
            int buy = -prices[i] + buse(dp, prices, 0, i + 1);
            int dont_buy = buse(dp, prices, 1, i + 1);
            return dp[i][buyorsell] = max(buy, dont_buy);
        }
        else
        {
            int sell = prices[i]; //Single Transaction only
            int dont_sell = buse(dp, prices, 0, i + 1);
            return dp[i][buyorsell] = max(sell, dont_sell);
        }
        return dp[i][buyorsell];
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return buse(dp, prices, 1, 0);
    }
};