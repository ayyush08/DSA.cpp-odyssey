// Neighbours within k distance

// 0

// 100
// Easy
// Given an integer array nums with n values and a value k, return an array containing the number of neighbours for each element of the array.

// An element x is the neighbour of element y if x falls in the range [y-k, y+k] (inclusive).

// Examples:
// Input: nums = [1, 4, 7, 8, 9], k = 3

// Output: [2, 3, 4, 3, 3]

// Explanation: Neighbours of 1 = [1, 4]

// Neighbours of 4 = [1, 4, 7]

// Neighbours of 7 = [4, 7, 8, 9]

// Neighbours of 8 = [7, 8, 9]

// Neighbours of 9 = [7, 8, 9]

// Input: nums = [10, 3, 6, 9, 4], k = 4

// Output: [3, 3, 5, 3, 3]

// Explanation: Neighbours of 10 = [6, 9, 10]

// Neighbours of 3 = [3, 4, 6]

// Neighbours of 6 = [3, 4, 6, 9, 10]

// Neighbours of 9 = [6, 9, 10]

// Neighbours of 4 = [3, 4, 6]

// Constraints:
// n == Number of elements in nums
// 1 <= n <= 105
// -1000 <= nums[i] <= 1000
// 0 <= k <= 104

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> neighboursWithKDistance(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        for (int n : nums)
        {
            int left = lower_bound(sorted_nums.begin(), sorted_nums.end(), n - k) - sorted_nums.begin();
            int right = upper_bound(sorted_nums.begin(), sorted_nums.end(), n + k) - sorted_nums.begin();
            ans.push_back(right - left);
        }
        return ans;
    }
};
