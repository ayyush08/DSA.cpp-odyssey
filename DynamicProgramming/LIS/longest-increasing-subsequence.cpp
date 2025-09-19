// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

// Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

// Example 1:

// Input: arr = [1,15,7,9,2,5,10], k = 3
// Output: 84
// Explanation: arr becomes [15,15,15,9,10,10,10]
// Example 2:

// Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
// Output: 83
// Example 3:

// Input: arr = [1], k = 1
// Output: 1

// Constraints:

// 1 <= arr.length <= 500
// 0 <= arr[i] <= 109
// 1 <= k <= arr.length

#include <bits/stdc++.h>
using namespace std;

// Tabulation - can also give TLE for large inputs (10^4 or more)
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // dp[i] - length of LIS ending at i
        int n = nums.size();
        vector<int> dp(n, 1);
        if (n == 0)
            return 0;
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {

                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// Memoization - can give TLE for large inputs

class Solution
{
public:
    int func(int i, vector<int> &nums, vector<int> &dp)
    {
        if (i <= 0)
            return 1;
        if (dp[i] != -1)
            return dp[i];
        int ans = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
                ans = max(ans, 1 + func(j, nums, dp));
        }
        return dp[i] = ans;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        int ans = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            ans = max(ans, func(i, nums, dp));
        }
        return ans;
    }
};

// 2d DP

class Solution
{
public:
    int func(int i, int recent, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i == nums.size())
            return 0;
        if (dp[i][recent + 1] != -1)
            return dp[i][recent + 1];

        int notTake = func(i + 1, recent, nums, dp);
        int take = 0;
        if (recent == -1 || nums[i] > nums[recent])
            take = 1 + func(i + 1, i, nums, dp);

        return dp[i][recent + 1] = max(take, notTake);
    }
    int LIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return func(0, -1, nums, dp);
    }
};
// gives runtime error for large inputs

// Optimal - Works for all inputs
// use binary search (lower_bound)

class Solution
{
public:
    int LIS(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> temp;

        temp.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > temp.back())
                temp.push_back(nums[i]);
            else
            {
                int toReplace = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();

                temp[toReplace] = nums[i];
            }
        }
        return temp.size();
    }
};