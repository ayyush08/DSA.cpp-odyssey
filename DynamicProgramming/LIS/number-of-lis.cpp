// Number of Longest Increasing Subsequences

// Given an integer array nums, find the number of Longest Increasing Subsequences (LIS) in the array.

// Examples:
// Input: nums = [1, 3, 5, 4, 7]

// Output: 2

// Explanation: There are two LIS of length 4:

// [1, 3, 4, 7]

// [1, 3, 5, 7].

// Input: nums = [2, 2, 2, 2, 2]

// Output: 5

// Explanation: All elements are the same, so every single element can form an LIS of length 1. There are 5 such subsequences.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfLIS(vector<int> nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> counter(n, 1);
        if (n == 0)
            return 0;
        int maxi = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (dp[i] < dp[j] + 1)
                    {

                        dp[i] = 1 + dp[j];
                        counter[i] = counter[j];
                    }
                    else if (dp[i] == dp[j] + 1)
                    {
                        counter[i] += counter[j];
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxi)
                cnt += counter[i];
        }
        return cnt;
    }
};
