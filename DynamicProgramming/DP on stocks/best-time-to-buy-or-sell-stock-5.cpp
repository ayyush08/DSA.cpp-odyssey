// 3573. Best Time to Buy and Sell Stock V
// You are given an integer array prices where prices[i] is the price of a stock in dollars on the ith day, and an integer k.

// You are allowed to make at most k transactions, where each transaction can be either of the following:

// Normal transaction: Buy on day i, then sell on a later day j where i < j. You profit prices[j] - prices[i].

// Short selling transaction: Sell on day i, then buy back on a later day j where i < j. You profit prices[i] - prices[j].

// Note that you must complete each transaction before starting another. Additionally, you can't buy or sell on the same day you are selling or buying back as part of a previous transaction.

// Return the maximum total profit you can earn by making at most k transactions.

// Example 1:

// Input: prices = [1,7,9,8,2], k = 2

// Output: 14

// Explanation:

// We can make $14 of profit through 2 transactions:
// A normal transaction: buy the stock on day 0 for $1 then sell it on day 2 for $9.
// A short selling transaction: sell the stock on day 3 for $8 then buy back on day 4 for $2.
// Example 2:

// Input: prices = [12,16,19,19,8,1,19,13,9], k = 3

// Output: 36

// Explanation:

// We can make $36 of profit through 3 transactions:
// A normal transaction: buy the stock on day 0 for $12 then sell it on day 2 for $19.
// A short selling transaction: sell the stock on day 3 for $19 then buy back on day 4 for $8.
// A normal transaction: buy the stock on day 5 for $1 then sell it on day 6 for $19.

// Constraints:

// 2 <= prices.length <= 103
// 1 <= prices[i] <= 109
// 1 <= k <= prices.length / 2

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long func(vector<int> &prices, vector<vector<vector<long long>>> &dp, int transactionType, int i, int k)
    {
        if (k == 0)
            return transactionType != 0 ? -1e9 : 0;
        if (i == prices.size())
            return transactionType != 0 ? -1e9 : 0;
        if (dp[i][transactionType][k] != -1)
            return dp[i][transactionType][k];

        if (transactionType == 0)
        { // no action - can normal transaction,short sell, or keep holding
            long long hold = func(prices, dp, 0, i + 1, k);
            long long normalBuy = -prices[i] + func(prices, dp, 1, i + 1, k);
            long long shortSell = prices[i] + func(prices, dp, 2, i + 1, k);
            return dp[i][transactionType][k] = max({hold, normalBuy, shortSell});
        }
        else if (transactionType == 1) // bought earlier, can either sell(normal) or hold
        {
            long long hold = func(prices, dp, 1, i + 1, k);
            long long normalSell = prices[i] + func(prices, dp, 0, i + 1, k - 1); // 0 cuz normal transaction over
            return dp[i][transactionType][k] = max(hold, normalSell);
        }
        else
        { // sold earlier, can either buy(short) or hold
            long long hold = func(prices, dp, 2, i + 1, k);
            long long shortBuy = -prices[i] + func(prices, dp, 0, i + 1, k - 1); // 0 as short sell transaction over
            return dp[i][transactionType][k] = max(hold, shortBuy);
        }
    }
    long long maximumProfit(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(3, vector<long long>(k + 1, -1)));

        return func(prices, dp, 0, 0, k);
    }
};

//Time Complexity: O(n*3*k)
//Space Complexity: O(n*3*k) + O(n) for recursion stack