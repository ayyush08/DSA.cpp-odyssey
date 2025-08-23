// Odd Subsets
// Given an array of unique elements nums, return all subsets of nums whose elements sum up to an odd value.

// A subset of an array is any selection of its elements, including the empty set. Answers can be returned in any order.

// Examples:
// Input: nums = [1, 2, 3, 4]

// Output: [[1], [1, 2], [1, 2, 4], [1, 4], [2, 3], [2, 3, 4], [3], [3, 4]]

// Explanation: all these subsets have an odd sum value.

// Input: nums = [1, 3, 5, 7]

// Output: [[1], [1, 3, 5], [1, 3, 7], [1, 5, 7], [3], [3, 5, 7], [5], [7]]

// Explanation: all these subsets have an odd sum value.

// Constraints:
// 1 <= nums.length <= 10
// -104 <= nums[i] <= 104
// All elements are unique

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> setsWithOddSum(vector<int> nums)
    {
        int n = nums.size();
        vector<vector<int>> oddsets;
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> subset;
            int runningSum = 0;
            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1)
                {
                    subset.push_back(nums[j]);
                    runningSum += nums[j];
                }
            }
            if (runningSum & 1)
                oddsets.push_back(subset);
        }
        return oddsets;
    }
};