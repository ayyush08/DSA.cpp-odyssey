// Maximum sum of non adjacent elements
// Given an integer array nums of size n. Return the maximum sum possible using the elements of nums such that no two elements taken are adjacent in nums.

// Examples:
// Input: nums = [1, 2, 4]

// Output: 5

// Explanation: [1, 2, 4], the underlined elements are taken to get the maximum sum.

// Input: nums = [2, 1, 4, 9]

// Output: 11

// Explanation: [2, 1, 4, 9], the underlined elements are taken to get the maximum sum.

#include <bits/stdc++.h>
using namespace std;

// Memoization
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
    int nonAdjacent(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return func(n - 1, nums, dp);
    }
};

// Tabulation

class Solution {
public:
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick = nums[i]+dp[i-2];
            int dontPick = dp[i-1];
            dp[i] = max(pick,dontPick);
        }
        return dp[n-1];
    }
};

// Space Optimization

class Solution {
public:
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        int prev=nums[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int pick = nums[i]+prev2;
            int dontPick = prev;
            int curr_i= max(pick,dontPick);
            prev2=prev;
            prev=curr_i;
        }
        return prev;
    }
};