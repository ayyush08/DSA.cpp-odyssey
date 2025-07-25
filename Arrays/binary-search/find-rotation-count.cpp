// Given an integer array nums of size n, sorted in ascending order with distinct values. The array has been right rotated an unknown number of times, between 0 and n-1 (including). Determine the number of rotations performed on the array.

// Examples:
// Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]

// Output: 4

// Explanation: The original array should be [0, 1, 2, 3, 4, 5, 6, 7]. So, we can notice that the array has been rotated 4 times.

// Input: nums = [3, 4, 5, 1, 2]

// Output: 3

// Explanation: The original array should be [1, 2, 3, 4, 5]. So, we can notice that the array has been rotated 3 times.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKRotation(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX, idx = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[low] <= nums[high]) //Already sorted (low represent rotation count)
            {
                if (nums[low] < ans)
                {
                    ans = nums[low];
                    idx = low;
                }
                break;
            }
            if (nums[low] <= nums[mid]) //left sorted
            {
                if (nums[low] < ans) //Check if the leftmost element is less than the current minimum
                {
                    ans = nums[low];
                    idx = low;
                }
                low = mid + 1;
            }
            else //right sorted
            {
                if (nums[mid] < ans) //Check if the mid element is less than the current minimum
                {
                    idx = mid;
                    ans = nums[mid];
                }
                high = mid - 1;
            }
        }
        return idx;
    }
};