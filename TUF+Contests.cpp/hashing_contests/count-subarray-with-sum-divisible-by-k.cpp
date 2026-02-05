// Count of Subarrays with Sum Divisible by K

// 0

// 100
// Easy
// Given an array of integers, nums, and an integer k, the task is to find the total number of subarrays whose sum is divisible by k. A subarray is a contiguous portion of the array.

// Examples:
// Input: nums = [3, 1, 4, 1], k = 3

// Output: 3

// Explanation: The subarrays whose sum is divisible by 3 are: [3], [1, 4, 1], [3, 1, 4, 1].

// Input: nums = [5, 10, -5, 20], k = 7

// Output: 0

// Explanation: There is no subarray whose sum is divisible by 7.

// Constraints:
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 2 <= k <= 104

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySumDivisbleByK(vector<int> &nums, int k)
    {
            unordered_map<int, int> mp;
            int sum = 0, cnt = 0;
            mp[0] = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                sum += nums[i];
                int rem = sum % k;
                if (rem < 0)
                    rem += k; // To handle negative remainders, we adjust them to be in the range [0, k-1]

                cnt += mp[rem];

                mp[rem]++;
            }
            return cnt;
    }
};