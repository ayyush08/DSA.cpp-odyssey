// Maximum Good Subarray Length
// Given two integer array nums and badNumbers, return the maximum length good subarray.

// A subarray is good if it does not contain every number in badNumbers. All elements in badNumbers are distinct.

// Examples:
// Input: nums = [2, 7, 3, 4, 5, 3], badNumbers = [7, 5]

// Output: 4

// Explanation: The optimal subarray is [3, 4, 5, 3], which does not contain all elements in badNumbers = [5, 7]

// Input: nums = [8, 7, 3, 0, 2, 3, 6], badNumbers = [3, 7]

// Output: 5

// Explanation: The optimal subarray is [3, 0, 2, 3, 6], which does not contain all elements in badNumbers = [3, 7]

// Constraints:
// 1 <= nums.length <= 105
// 1 <= badNumbers.length <= 20
// -104 <= nums[i], badNumbers[i] <= 104
// all elements in badNumbers are distinct.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxGoodSubarray(vector<int> &nums, vector<int> &badNumbers)
    {
        int n = nums.size();
        int m = badNumbers.size();

        unordered_set<int> badSet(badNumbers.begin(), badNumbers.end());
        unordered_map<int, int> freq;
        int covered = 0;
        int ans = 0;

        int l = 0;
        for (int r = 0; r < n; r++)
        {
            if (badSet.count(nums[r]))
            {
                if (++freq[nums[r]] == 1)
                {
                    covered++;
                }
            }
            while (covered == m)
            {
                if (badSet.count(nums[l]))
                {
                    if (--freq[nums[l]] == 0)
                    {
                        covered--;
                    }
                }
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};