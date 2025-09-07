// House robber
// A robber is targeting to rob houses from a street. Each house has security measures that alert the police when two adjacent houses are robbed. The houses are arranged in a circular manner, thus the first and last houses are adjacent to each other.

// Given an integer array money, where money[i] represents the amount of money that can be looted from the (i+1)th house. Return the maximum amount of money that the robber can loot without alerting the police.

// Examples:
// Input: money = [2, 1, 4, 9]

// Output: 10

// Explanation: [2, 1, 4, 9] The underlined houses would give the maximum loot.

// Note that we cannot loot the 1st and 4th houses together.

// Input: money = [1, 5, 2, 1, 6]

// Output: 11

// Explanation: [1, 5, 2, 1, 6] The underlined houses would give the maximum loot.

#include <bits/stdc++.h>
using namespace std;

// Memoization - Same as max sum of non adjacent elements but we have to consider that first and last element are adjacent so we will take two cases one excluding first element and one excluding last element and take the maximum of both cases.

class Solution
{
public:
    int func(int i, vector<int> &nums, vector<int> &dp)
    {
        if (i < 0)
            return 0;
        if (i == 0)
            return nums[i];
        if (dp[i] != -1)
            return dp[i];

        int pick = nums[i] + func(i - 2, nums, dp);
        int dontPick = func(i - 1, nums, dp);

        return dp[i] = max(pick, dontPick);
    }
    int houseRobber(vector<int> &money)
    {
        int n = money.size();
        if (n == 1)
            return money[0];
        vector<int> withoutFirst, withoutLast;
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (i != n - 1)
                withoutLast.push_back(money[i]);
            if (i != 0)
                withoutFirst.push_back(money[i]);
        }
        int ans1 = func(withoutFirst.size() - 1, withoutFirst, dp1);
        int ans2 = func(withoutLast.size() - 1, withoutLast, dp2);

        return max(ans1, ans2);
    }
};
// Tabulation - similar manner