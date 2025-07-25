// Given an integer array nums, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False.

// Examples:
// Input : nums = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3

// Output: True

// Explanation: The element 3 is present in the array. So, the answer is True.

// Input : nums = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 10

// Output: False

// Explanation:The element 10 is not present in the array. So, the answer is False.

// Input : nums = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 7

// Output:
// True

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchInARotatedSortedArrayII(vector<int> &nums, int k)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == k)
                return true;
            if (nums[l] == nums[mid] && nums[mid] == nums[r])
            {
                l++;
                r--;
                continue;
            }
            else if (nums[l] <= nums[mid])
            {
                if (nums[l] <= k && k <= nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if (nums[mid] <= k && k <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};