// 29. Divide Two Integers
// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

// The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

// Return the quotient after dividing dividend by divisor.

// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

// Example 1:

// Input: dividend = 10, divisor = 3
// Output: 3
// Explanation: 10/3 = 3.33333.. which is truncated to 3.
// Example 2:

// Input: dividend = 7, divisor = -3
// Output: -2
// Explanation: 7/-3 = -2.33333.. which is truncated to -2.

// Constraints:

// -231 <= dividend, divisor <= 231 - 1
// divisor != 0

#include <bits/stdc++.h>
using namespace std;

// Brute - Repeatedly add divisor and keep count until it crosses dividend (Time Limit Exceeded Approach)

// Optimized - Bit Manipulation
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        
        if (dividend == divisor)
            return 1;
        if (divisor == 1)
            return dividend;
        if (dividend == INT_MIN && divisor == -1) //Overflow
            return INT_MAX;
        bool sign = true;
        if (dividend >= 0 && divisor < 0)
            sign = false;
        if (dividend < 0 && divisor >= 0)
            sign = false;

        long numerator = abs((long)dividend); // Convert to long to handle INT_MIN case
        long denominator = abs((long)divisor); // Convert to long to handle INT_MIN case

        long ans = 0;
        while (numerator >= denominator)
        {
            int cnt = 0;
            while (numerator >= (denominator << (cnt + 1))) // Find the largest power of 2 which can be removed from numerator
                cnt++;

            ans += (1 << cnt); // Add the found power of 2 to the answer

            numerator -= (denominator << cnt); //remove the found power of 2 from numerator
        }
        ans = sign ? ans : -ans;
        if (ans >= INT_MAX) // Check for overflow
            return INT_MAX;
        if (ans <= INT_MIN) // Check for underflow
            return INT_MIN;
        return ans;
    }
};