// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> sets;
        for (int i = 0; i < (1 << n); i++) //All bits from 0 to n-1, (if u left shift 1 by n, it will give 2^n)
        {
            vector<int> sset;
            for (int j = 0; j < n; j++) //Check each bit of i
            {
                if ((i >> j) & 1) //If jth bit of i is set, then include nums[j] in the current subset, (if you right shift i by j and check if the last bit is set with & 1 and if it results in 1, then the jth bit is set else it is not set)
                {
                    sset.push_back(nums[j]);    
                }
            }
            sets.push_back(sset);
        }
        return sets;
    }
};

//Approach:
// 1. The number of subsets of a set with n elements is 2^n
// 2. We can represent each subset as a binary number of n bits, where each bit indicates whether the corresponding element is included in the subset.
// 3. We iterate through all numbers from 0 to 2^n - 1, and for each number, we check which bits are set.
// 4. If a bit is set, we include the corresponding element in the current subset
// 5. Finally, we return the list of all subsets.
