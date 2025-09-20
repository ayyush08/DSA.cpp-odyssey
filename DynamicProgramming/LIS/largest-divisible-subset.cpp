// Largest Divisible Subset
// Given an array nums of positive integers, the task is to find the largest subset such that every pair (a, b) of elements in the subset satisfies a % b == 0 or b % a == 0.

// Return the subset in any order. If there are multiple solutions, return any one of them.

// Note: As there can be multiple correct answers, the compiler returns 1 if the answer is valid, else 0.

// Examples:
// Input: nums = [3, 5, 10, 20]

// Output: [5, 10, 20]

// Explanation:

// The subset [5, 10, 20] satisfies the divisibility condition: 10 % 5 == 0 and 20 % 10 == 0.

// Input: nums = [16, 8, 2, 4, 32]

// Output: [2, 4, 8, 16, 32]

// Explanation:

// The entire array forms a divisible subset since 32 % 16 == 0, 16 % 8 == 0, and so on.

#include <bits/stdc++.h>
using namespace std;
//Tabulation - O(n^2) time and O(n) space
// similar to longest increasing subsequence just change the condition after sorting the array (longest divisible subsequence)
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> parent(n);

        int last = 0;
        int lis = 0;
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > lis)
            {
                last = i;
                lis = dp[i];
            }
        }
        int idx = last;
        vector<int> ans;
        while (parent[idx] != idx)
        {
            ans.push_back(nums[idx]);
            idx = parent[idx];
        }
        ans.push_back(nums[idx]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
