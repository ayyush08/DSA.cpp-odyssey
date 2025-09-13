// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve.

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.
// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Total profit is 4.
// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

// Constraints:

// 1 <= prices.length <= 3 * 104
// 0 <= prices[i] <= 104

// Intuition: we need to buy stock at days after ith day (includig ith day) and sell it at ith day, so we can buy stock at ith day and sell it at i+1th day, then buy it at i+2th day and sell it at i+3th day and so on. So we can just add all the profits of all the days where prices[i] < prices[i+1].

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
            int sell = prices[i] + buse(dp, prices, 1, i + 1);
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
/*
Time Complexity:O(n), where n is the size of the input array due to the memoization avoiding redundant calculations.
Space Complexity:O(n), due to the dp table of size n*2 and the recursion stack space in the worst case.

*/

// Tabulation

class Solution2
{
public:
    int stockBuySell(vector<int> arr, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Base case: dp[n][0] = dp[n][1] = 0 already filled

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buyornot = 0; buyornot <= 1; buyornot++)
            {
                if (buyornot)
                {
                    int buy = -arr[i] + dp[i + 1][0];
                    int dont_buy = dp[i + 1][1];
                    dp[i][buyornot] = max(buy, dont_buy);
                }
                else
                {
                    int sell = arr[i] + dp[i + 1][1];
                    int dont_sell = dp[i + 1][0];
                    dp[i][buyornot] = max(sell, dont_sell);
                }
            }
        }

        return dp[0][1];
    }
};

// Space Optimized - O(1) Space

class Solution
{
public:
    int stockBuySell(vector<int> arr, int n)
    {
        vector<int> ahead(2, 0), curr(2, 0); //0 for buy, 1 for sell

        // Base case: ahead = {0,0} (i == n)

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buyornot = 0; buyornot <= 1; buyornot++)
            {
                if (buyornot)
                {
                    int buy = -arr[i] + ahead[0];
                    int dont_buy = ahead[1];
                    curr[buyornot] = max(buy, dont_buy);
                }
                else
                {
                    int sell = arr[i] + ahead[1];
                    int dont_sell = ahead[0];
                    curr[buyornot] = max(sell, dont_sell);
                }
            }
            ahead = curr; // move one step back
        }

        return ahead[1]; 
    }
};
