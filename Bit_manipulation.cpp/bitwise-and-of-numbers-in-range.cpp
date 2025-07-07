// Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

// Example 1:

// Input: left = 5, right = 7
// Output: 4
// Example 2:

// Input: left = 0, right = 0
// Output: 0
// Example 3:

// Input: left = 1, right = 2147483647
// Output: 0

// Constraints:

// 0 <= left <= right <= 231 - 1

// Approach 1: Use Bit Manipulation to find the common prefix of left and right by right shifting both by 1, track the count of right shifts, and then left shift the result back by the count of shifts.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int cnt = 0;
        while (left != right)
        {
            right = right >> 1;
            left = left >> 1;
            cnt++;
        }
        return right << cnt;
    }
};

// Approach 2: Use a while loop to keep reducing the right value by performing a bitwise AND with (right - 1) until left is no longer less than right. This effectively finds the common bits in the range , rather the overall AND of the range.
class Solution2
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        while (left < right)
        {
            right = right & (right - 1);
        }
        return right;
    }
};


//Time Complexity: O(log2(N)). as bit representation of numbers is log2(N) in height. 