// 90. Subsets II
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> subset;
            bool valid = true;
            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1)
                {
                    if (j > 0 && nums[j] == nums[j - 1] && ((i >> (j - 1)) & 1) == 0) //check if previous element is same and not included i.e, the previous bit is not set
                    {
                        valid = false;
                        break;
                    }
                    subset.push_back(nums[j]);
                }
            }

            if (valid)
                ans.push_back(subset);
        }
        return ans;
    }
};