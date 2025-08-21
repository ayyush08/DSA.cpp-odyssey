// Single Number - II

// Given an array nums where each integer in nums appears thrice except one. Find out the number that has appeared only once.

// Examples:
// Input : nums = [2, 2, 2, 3]

// Output : 3

// Explanation : The integers 3 has appeared only once.

// Input : nums = [1, 0, 3, 0, 1, 1, 3, 3, 10, 0]

// Output : 10

// Explanation : The integers 10 has appeared only once.

#include <bits/stdc++.h>
using namespace std;
//Brute- store freq of  each element, return the one with freq 1 (TC: O(n), SC: O(n))

//Better 1: for every bit index if (cnt % 3 == 1) then set that bit in the answer because For elements appearing three times, the bit count will be a multiple of three. The unique element's bit will not follow this pattern, using which it could be identified.
//TC: O(32 * n) = O(n)

class Solution1
{
public:
    int singleNumber(vector<int> &nums)
    {
        int x = 0;
        int ans = 0;
        for (int bitIndex = 0; bitIndex < 32; bitIndex++)
        {
            int cnt = 0;
            for (int n : nums)
            {
                if (n & (1 << bitIndex))
                    cnt++;
            }
            if (cnt % 3 == 1)
                ans |= (1 << bitIndex);
        }
        return ans;
    }
};

//Better 2: Sort and make buckets of 3, check each bucket . TC: O(nlogn)

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i += 3) {
            if (nums[i] != nums[i - 1]) {
                return nums[i - 1];
            }
        }
        
        /* If not found till now, then 
        the last number will be single */
        return nums[n - 1];
    }
};

//Optimal: use buckets of ones and twos
//TC: O(n)

class Solution3 {
public:
    int singleNumber(vector<int>& nums) {        
        int ones=0,twos=0;

        for(int n:nums){
            ones=(ones^n)&~twos;
            twos=(twos^n)&~ones;
        }

        return ones;
    }
};