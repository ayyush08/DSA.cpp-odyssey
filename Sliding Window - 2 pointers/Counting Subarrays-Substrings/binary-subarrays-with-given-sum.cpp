// Binary Subarrays With Sum

// Given a binary array nums and an integer goal. Return the number of non-empty subarrays with a sum goal.
// A subarray is a continuous part of the array.

// Examples:
// Input : nums = [1, 1, 0, 1, 0, 0, 1] , goal = 3
// Output : 4
// Explanation : The subarray with sum 3 are
// [1, 1, 0, 1]
// [1, 1, 0, 1, 0]
// [1, 1, 0, 1, 0, 0]
// [1, 0, 1, 0, 0, 1].

// Input : nums = [0, 0, 0, 0, 1] , goal = 0
// Output : 10
// Explanation : Some of the subarray with sum 0 are
// [0]
// [0, 0]
// [0, 0, 0]
// [0, 0, 0, 0]

// Constraints:
// 1 <= nums.length <= 3*104
// 0 <= goal <= nums.length
// nums consist of only 0 and 1.

#include <bits/stdc++.h>
using namespace std;

//Intuition - see template 3
//TC: O(2*2N)
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return getSubarrays(nums, goal) - getSubarrays(nums, goal - 1);
    }
    int getSubarrays(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;
        int l = 0, r = 0;
        int sum = 0, ans = 0;

        while (r < nums.size())
        {
            sum += nums[r];
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
