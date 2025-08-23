// Twin Numbers
// Given an array of integers nums, where each element occurs thrice, except one which occurs twice. Return the element which repeats twice.

// Examples:
// Input: nums = [1, 1, 2, 2, 2, 3, 3, 3]

// Output: 1

// Explanation: Element with value 1 occurs twice, others occur thrice.

// Input: nums = [9, 0, 9, 9, 0]

// Output: 0

// Explanation: Element with value 0 occurs twice, others occur thrice.

// Constraints:
// 2 <= nums.length <= 105
// 0 <= nums[i] <= 104
// There will always be an element that occurs twice.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOccursTwice(vector<int> nums)
    {
        int ones = 0, twos = 0;
        for (int n : nums)
        {
            ones = (ones ^ n) & ~twos;
            twos = (twos ^ n) & ~ones;
        }
        return twos;
    }
};