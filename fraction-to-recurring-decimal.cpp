// 166. Fraction to Recurring Decimal
// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses.

// If multiple answers are possible, return any of them.

// It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

// Example 1:

// Input: numerator = 1, denominator = 2
// Output: "0.5"
// Example 2:

// Input: numerator = 2, denominator = 1
// Output: "2"
// Example 3:

// Input: numerator = 4, denominator = 333
// Output: "0.(012)"

// Constraints:

// -231 <= numerator, denominator <= 231 - 1
// denominator != 0

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";
        string res;
        if ((numerator < 0) ^ (denominator < 0))
            res += '-';

        long long n = llabs(numerator);
        long long d = llabs(denominator);

        res += to_string(n / d);
        long long rem = n % d;

        if (rem == 0)
            return res;
        res += ".";
        unordered_map<long long, int> seen;
        while (rem)
        {
            if (seen.count(rem))
            {
                res.insert(seen[rem], "(");
                res += ")";
                break;
            }
            seen[rem] = res.size();
            rem *= 10;
            res += to_string(rem / d);
            rem = rem % d;
        }
        return res;
    }
};