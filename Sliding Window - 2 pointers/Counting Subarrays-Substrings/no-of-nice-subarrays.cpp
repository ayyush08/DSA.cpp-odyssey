// Count number of Nice subarraysd

// Given an array nums and an integer k. An array is called nice if and only if it contains k odd numbers. Find the number of nice subarrays in the given array nums.
// A subarray is continuous part of the array.

// Examples:
// Input : nums = [1, 1, 2, 1, 1] , k = 3
// Output : 2

// Explanation : The subarrays with three odd numbers are
// [1, 1, 2, 1]
// [1, 2, 1, 1]

// Input : nums = [4, 8, 2] , k = 1
// Output : 0
// Explanation : The array does not contain any odd number.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfOddSubarrays(vector<int> &nums, int k)
    {
        return getSubarrays(nums, k) - getSubarrays(nums, k - 1);
    }
    int getSubarrays(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;
        int l = 0, r = 0;
        int sum = 0, ans = 0;

        while (r < nums.size())
        {
            sum += (nums[r] & 1);
            while (sum > goal)
            {
                sum -= nums[l];
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
};