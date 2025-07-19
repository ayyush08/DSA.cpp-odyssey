// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value. If the target is not found in the array, return [-1, -1].

// Examples:
// Input: nums = [5, 7, 7, 8, 8, 10], target = 8

// Output: [3, 4]

// Explanation:The target is 8, and it appears in the array at indices 3 and 4, so the output is [3,4]

// Input: nums = [5, 7, 7, 8, 8, 10], target = 6

// Output: [-1, -1]

// Expalantion: The target is 6, which is not present in the array. Therefore, the output is [-1, -1].

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lowerBound(vector<int> &nums, int x)
    {
        int l = 0, r = nums.size() - 1;
        int ans = nums.size();
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] >= x)
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return ans;
    }
    int upperBound(vector<int> &nums, int x)
    {
        int l = 0, r = nums.size() - 1;
        int ans = nums.size();
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] > x)
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int lb = lowerBound(nums, target);
        if (lb == nums.size() || nums[lb] != target)
            return {-1, -1};
        int up = upperBound(nums, target);
        return {lb, up - 1};
    }
};