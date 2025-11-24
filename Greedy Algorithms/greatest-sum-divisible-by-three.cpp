// 1262. Greatest Sum Divisible by Three
// Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.

// Example 1:

// Input: nums = [3,6,5,1,8]
// Output: 18
// Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
// Example 2:

// Input: nums = [4]
// Output: 0
// Explanation: Since 4 is not divisible by 3, do not pick any number.
// Example 3:

// Input: nums = [1,2,3,4,4]
// Output: 12
// Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).

// Constraints:

// 1 <= nums.length <= 4 * 104
// 1 <= nums[i] <= 104

#include <bits/stdc++.h>
using namespace std;

// Approach-1: Using Greedy Algorithm

// Store remainder 1 and remainder 2 elements in two separate arrays. sort them

// check if total sum is divisible by 3 if yes return total sum
// Else check if remainder is 1 or 2
// If remainder is 1 then we have two options either remove one smallest element from remainder 1 array or remove two smallest elements from remainder 2 array
// If remainder is 2 then we have two options either remove one smallest element from remainder 2 array or remove two smallest elements from remainder 1 array
class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        vector<int> rem1, rem2;
        for (int num : nums)
        {
            sum += num;
            if (num % 3 == 1)
                rem1.push_back(num);
            else if (num % 3 == 2)
                rem2.push_back(num);
        }
        if (sum % 3 == 0)
            return sum;

        sort(rem1.begin(), rem1.end());
        sort(rem2.begin(), rem2.end());

        int ans = 0;
        int remainder = sum % 3;
        if (remainder == 1)
        {
            int del1 = rem1.size() >= 1 ? rem1[0] : INT_MAX;
            int del2 = rem2.size() >= 2 ? rem2[0] + rem2[1] : INT_MAX;

            ans = max(ans, sum - min(del1, del2));
        }
        else
        {
            int del1 = rem2.size() >= 1 ? rem2[0] : INT_MAX;
            int del2 = rem1.size() >= 2 ? rem1[0] + rem1[1] : INT_MAX;

            ans = max(ans, sum - min(del1, del2));
        }
        return ans;
    }
};

// Approach-2: Using DP - Memoization (Pick or Not Pick)

class Solution
{
public:
    int func(int i, int rem, vector<vector<int>> &dp, vector<int> &nums)
    {
        if (i >= nums.size())
            return (rem == 0) ? 0 : INT_MIN;
        if (dp[i][rem] != -1)
            return dp[i][rem];

        int notTake = func(i + 1, rem, dp, nums);

        int take = nums[i] + func(i + 1, (rem + nums[i]) % 3, dp, nums);

        return dp[i][rem] = max(take, notTake);
    }
    int maxSumDivThree(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return func(0, 0, dp, nums);
    }
};