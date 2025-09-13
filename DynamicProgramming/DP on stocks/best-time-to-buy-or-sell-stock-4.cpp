// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Example 1:

// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
// Example 2:

// Input: k = 2, prices = [3,2,6,5,0,3]
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

// Constraints:

// 1 <= k <= 100
// 1 <= prices.length <= 1000
// 0 <= prices[i] <= 1000

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int buse(vector<vector<vector<int>>> &dp, vector<int> &prices, int buyorsell, int i, int k)
    {
        if (k == 0)
            return 0;
        if (i == prices.size())
        {
            return 0;
        }
        if (dp[i][buyorsell][k] != -1)
            return dp[i][buyorsell][k];

        if (buyorsell)
        {
            int buy = -prices[i] + buse(dp, prices, 0, i + 1, k);
            int dont_buy = buse(dp, prices, 1, i + 1, k);
            return dp[i][buyorsell][k] = max(buy, dont_buy);
        }
        else
        {
            int sell = prices[i] + buse(dp, prices, 1, i + 1, k - 1);
            int dont_sell = buse(dp, prices, 0, i + 1, k);
            return dp[i][buyorsell][k] = max(sell, dont_sell);
        }
        return dp[i][buyorsell][k];
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return buse(dp, prices, 1, 0, k);
    }
};

//Simply keep a state for transaction count k in the dp array, so that we can keep track of how many transactions we have done so far. The rest of the logic remains the same as in the previous problem. If transactions cross k we return 0, as we cannot do more than k transactions.