// Find Distinct Expressions
// Given an integer array nums, return all distinct values obtained by inserting mathematical ' + ' (addition) or ' - ' (subtraction) between each element of nums and evaluating the resulting expression.

// Return the results in increasing order.

// Examples:
// Input: nums = [1, 2, 3]

// Output: [-4, 0, 2, 6]

// Explanation: 1 + 2 + 3 = 6,

// 1 + 2 - 3 = 0,

// 1 - 2 + 3 = 2

// 1 - 2 - 3 = -4

// Input: nums = [98, 71, 30]

// Output: [-3, 57, 139, 199]

// Explanation: 98 + 71 + 30 = 199

// 98 + 71 - 30 = 139

// 98 - 71 - 30 = -3

// 98 - 71 + 30 = 57

// Constraints:
// 1 <= nums.length <= 10
// 1 <= nums[i] <= 1000

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void func(int i, vector<int> &nums, unordered_set<int> &ans, int op)
    {
        if (i == nums.size())
        {
            ans.insert(op);
            return;
        }

        func(i + 1, nums, ans, op + nums[i]);
        func(i + 1, nums, ans, op - nums[i]);
    }
    vector<int> distinctExpressions(vector<int> &nums)
    {
        unordered_set<int> ans;
        func(1, nums, ans, nums[0]);
        vector<int> res(ans.begin(), ans.end());
        sort(res.begin(), res.end());
        return res;
    }
};

// Time Complexity:O(2^n + mlogm) where n is the size of nums and m is the number of distinct expressions
// Space Complexity:O(2^n) due to the unordered set potentially storing all possible sums and differences and the recursion depth.