// 4 Sum
// Given an integer array nums and an integer target. Return all quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// ·      a, b, c, d are all distinct valid indices of nums.

// ·      nums[a] + nums[b] + nums[c] + nums[d] == target.

// Notice that the solution set must not contain duplicate quadruplets. One element can be a part of multiple quadruplets. The output and the quadruplets can be returned in any order.

// Examples:
// Input: nums = [1, -2, 3, 5, 7, 9], target = 7

// Output: [[-2, 1, 3, 5]]

// Explanation: nums[1] + nums[0] + nums[2] + nums[3] = 7

// Input: nums = [7, -7, 1, 2, 14, 3], target = 9

// Output: []

// Explanation: No quadruplets are present which add upto 9

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> fourLets;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int k = j + 1;
                int l = n - 1;

                while (k < l)
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target)
                    {
                        fourLets.push_back(
                            {nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < target)
                        k++;
                    else
                        l--;
                }
            }
        }
        return fourLets;
    }
};

//optimal approach by using two pointers
//better is to  use hashset
//brute is 4 nested loops as usual