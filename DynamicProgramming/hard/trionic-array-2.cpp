// 3640. Trionic Array II
// You are given an integer array nums of length n.

// A trionic subarray is a contiguous subarray nums[l...r] (with 0 <= l < r < n) for which there exist indices l < p < q < r such that:

// nums[l...p] is strictly increasing,
// nums[p...q] is strictly decreasing,
// nums[q...r] is strictly increasing.
// Return the maximum sum of any trionic subarray in nums.

// Example 1:

// Input: nums = [0,-2,-1,-3,0,2,-1]

// Output: -4

// Explanation:

// Pick l = 1, p = 2, q = 3, r = 5:

// nums[l...p] = nums[1...2] = [-2, -1] is strictly increasing (-2 < -1).
// nums[p...q] = nums[2...3] = [-1, -3] is strictly decreasing (-1 > -3)
// nums[q...r] = nums[3...5] = [-3, 0, 2] is strictly increasing (-3 < 0 < 2).
// Sum = (-2) + (-1) + (-3) + 0 + 2 = -4.
// Example 2:

// Input: nums = [1,4,2,7]

// Output: 14

// Explanation:

// Pick l = 0, p = 1, q = 2, r = 3:

// nums[l...p] = nums[0...1] = [1, 4] is strictly increasing (1 < 4).
// nums[p...q] = nums[1...2] = [4, 2] is strictly decreasing (4 > 2).
// nums[q...r] = nums[2...3] = [2, 7] is strictly increasing (2 < 7).
// Sum = 1 + 4 + 2 + 7 = 14.

// Constraints:

// 4 <= n = nums.length <= 105
// -109 <= nums[i] <= 109
// It is guaranteed that at least one trionic subarray exists.

#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization (Time Complexity: O(N)  Space Complexity: O(N))

class Solution
{
public:
    vector<vector<long long>> dp;
    int n;
    long long func(int i, int trend, vector<int> &nums)
    {
        if (i == n)
            return trend == 3 ? 0 : LLONG_MIN / 2;
        if (dp[i][trend] != LLONG_MIN)
            return dp[i][trend];

        long long notTake = LLONG_MIN / 2;
        long long take = LLONG_MIN / 2;
        if (trend == 0)
            notTake = func(i + 1, 0, nums);
        if (trend == 3)
            take = nums[i];
        if (i + 1 < n)
        {
            int curr = nums[i];
            int next = nums[i + 1];
            if (trend == 0 && next > curr)
            {
                take = max(take, curr + func(i + 1, 1, nums));
            }
            else if (trend == 1)
            {
                if (next > curr)
                    take = max(take, curr + func(i + 1, 1, nums));
                else if (next < curr)
                    take = max(take, curr + func(i + 1, 2, nums));
            }
            else if (trend == 2)
            {
                if (next < curr)
                    take = max(take, curr + func(i + 1, 2, nums));
                else if (next > curr)
                    take = max(take, curr + func(i + 1, 3, nums));
            }
            else if (trend == 3 && next > curr)
                take = max(take, curr + func(i + 1, 3, nums));
        }
        return dp[i][trend] = max(take, notTake);
    }
    long long maxSumTrionic(vector<int> &nums)
    {
        n = nums.size();
        dp.assign(n + 1, vector<long long>(4, LLONG_MIN));
        return func(0, 0, nums);
    }
};

// Tabulation (Time Complexity: O(N)  Space Complexity: O(N))

class Solution
{
public:
    vector<vector<long long>> dp;
    int n;
    long long MIN_NEG = LLONG_MIN / 2;
    long long maxSumTrionic(vector<int> &nums)
    {
        n = nums.size();
        dp.assign(n + 1, vector<long long>(4, MIN_NEG));

        dp[n][3] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int trend = 0; trend <= 3; trend++)
            {
                long long notTake = MIN_NEG;
                long long take = MIN_NEG;
                if (trend == 0)
                    notTake = dp[i + 1][0];
                if (trend == 3)
                    take = nums[i];
                if (i + 1 < n)
                {
                    int curr = nums[i];
                    int next = nums[i + 1];
                    if (trend == 0 && next > curr)
                    {
                        take = max(take, curr + dp[i + 1][1]);
                    }
                    else if (trend == 1)
                    {
                        if (next > curr)
                            take = max(take, curr + dp[i + 1][1]);
                        else if (next < curr)
                            take = max(take, curr + dp[i + 1][2]);
                    }
                    else if (trend == 2)
                    {
                        if (next < curr)
                            take = max(take, curr + dp[i + 1][2]);
                        else if (next > curr)
                            take = max(take, curr + dp[i + 1][3]);
                    }
                    else if (trend == 3 && next > curr)
                        take = max(take, curr + dp[i + 1][3]);
                }
                dp[i][trend] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};

// Space Optimization - (Time Complexity: O(n), Space: O(1))

class Solution
{
public:
    vector<long long> curr;
    vector<long long> next;
    int n;
    long long MIN_NEG = LLONG_MIN / 2;
    long long maxSumTrionic(vector<int> &nums)
    {
        n = nums.size();
        next.assign(4, MIN_NEG);
        curr.assign(4, MIN_NEG);

        next[3] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int trend = 0; trend <= 3; trend++)
            {
                long long notTake = MIN_NEG;
                long long take = MIN_NEG;
                if (trend == 0)
                    notTake = next[0];
                if (trend == 3)
                    take = nums[i];
                if (i + 1 < n)
                {
                    int currVal = nums[i];
                    int nextVal = nums[i + 1];
                    if (trend == 0 && nextVal > currVal)
                    {
                        take = max(take, currVal + next[1]);
                    }
                    else if (trend == 1)
                    {
                        if (nextVal > currVal)
                            take = max(take, currVal + next[1]);
                        else if (nextVal < currVal)
                            take = max(take, currVal + next[2]);
                    }
                    else if (trend == 2)
                    {
                        if (nextVal < currVal)
                            take = max(take, currVal + next[2]);
                        else if (nextVal > currVal)
                            take = max(take, currVal + next[3]);
                    }
                    else if (trend == 3 && nextVal > currVal)
                        take = max(take, currVal + next[3]);
                }
                curr[trend] = max(take, notTake);
            }
            next = curr;
        }
        return next[0];
    }
};