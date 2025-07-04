// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

// Example 1:

// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.
// Example 2:

// Input: nums = [-1,0]
// Output: [-1,0]
// Example 3:

// Input: nums = [0,1]
// Output: [1,0]

// Constraints:

// 2 <= nums.length <= 3 * 104
// -231 <= nums[i] <= 231 - 1
// Each integer in nums will appear twice, only two integers will appear once.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        long long totxor = 0;
        for (int num : nums)
            totxor ^= num;
        int x1 = 0, x2 = 0;
        long long rbit = totxor & -totxor;

        for (int num : nums)
        {
            if ((rbit & num) == 0)
                x1 ^= num;
            else
                x2 ^= num;
        }
        return {x1, x2};
    }
};


//Approach:
// 1. Calculate the XOR of all elements in the array, which gives us the XOR of the two unique numbers.
// 2. Find a bit that is set in the XOR result(here we use the rightmost set bit).
// 3. Partition the numbers into two groups based on whether they have that rightmost set bit set or not.
// 4. XOR the numbers in each group to find the two unique numbers.
// Time Complexity: O(n), where n is the number of elements in the input array.
// Space Complexity: O(1), since we are using only a constant amount of extra space.