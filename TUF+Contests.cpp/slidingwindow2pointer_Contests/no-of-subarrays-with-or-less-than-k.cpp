// Number of Subarrays with Or less than K
// Given an integer array nums and an integer k, return the number of subarrays whose bitwise OR of elements is less than or equal to k.

// Examples:
// Input: nums = [2, 3, 3, 2, 9, 2, 5], k = 4

// Output: 11

// Explanation: The satisfying subarrays are: [2], [2, 3], [2, 3, 3], [2, 3, 3, 2], [3], [3, 3], [3, 3, 2], [3], [3, 2], [2], [2].

// Note that the subarrays all have distinct left and right boundary indexes.

// Input: nums = [9, 2, 2, 5, 8, 6], k = 3

// Output: 3

// Explanation: The satisfying subarrays are: [2], [2, 2], [2].

// Constraints:
// 1 <= nums.length <= 104
// 0 <= nums[i] <= 104﻿
// 0 <= k <= 104

#include <bits/stdc++.h>
using namespace std;


// Brute - O(n^2)
class Solution
{
public:
    long long SubarrayOrLessThanKCount(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0;
        int l = 0, r = 0;
        int n = nums.size();
        long long sum = 0;
        long long ans = 0;
        while (r < n)
        {
            sum |= nums[r];
            while (sum > k)
            {
                l++;
                sum = 0;
                for (int i = l; i <= r; i++) //recompute OR
                    sum |= nums[i];
            }
            ans = ans + (r - l + 1);
            r++;
        }
        return ans;
    }
};

// Optimal - O(n) - Use bit manipulation

class Solution {
public:
    long long SubarrayOrLessThanKCount(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        int l = 0;
        int currOR = 0;
        int bitCount[32] = {0};

        for (int r = 0; r < n; r++) {
            // add nums[r]
            for (int b = 0; b < 32; b++) {
                if ((nums[r] >> b) & 1) { // if b-th bit is set in nums[r]
                    bitCount[b]++; // increment count of b-th bit
                    currOR |= (1 << b); // set b-th bit in currOR
                }
            }

            // shrink from left while OR > k
            while (currOR > k) {
                for (int b = 0; b < 32; b++) { 
                    if ((nums[l] >> b) & 1) { // if b-th bit is set in nums[l]
                        bitCount[b]--;// decrement count of b-th bit
                        if (bitCount[b] == 0) currOR &= ~(1 << b); // unset b-th bit in currOR if count is 0
                    }
                }
                l++;
            }

            ans += (r - l + 1); // all subarrays ending at r
        }

        return ans;
    }
};
