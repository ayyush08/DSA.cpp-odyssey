// Q4. Number of Balanced Integers in a Range
// Solved
// Hard
// 7 pt.
// You are given two integers low and high.
// An integer is called balanced if it satisfies both of the following conditions:

// It contains at least two digits.
// The sum of digits at even positions is equal to the sum of digits at odd positions (the leftmost digit has position 1).
// Return an integer representing the number of balanced integers in the range [low, high] (both inclusive).

//  

// Example 1:

// Input: low = 1, high = 100

// Output: 9

// Explanation:

// The 9 balanced numbers between 1 and 100 are 11, 22, 33, 44, 55, 66, 77, 88, and 99.

// Example 2:

// Input: low = 120, high = 129

// Output: 1

// Explanation:

// Only 121 is balanced because the sum of digits at even and odd positions are both 2.

// Example 3:

// Input: low = 1234, high = 1234

// Output: 0

// Explanation:

// 1234 is not balanced because the sum of digits at odd positions (1 + 3 = 4) does not equal the sum at even positions (2 + 4 = 6).

//  

// Constraints:

// 1 <= low <= high <= 1015

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dp[16][2][2][2][289]; // idx,tight, leading_zero,diff,parity

    long long func(string& s, long long tight, long long i, bool leading_zero,
                   long long diff, bool parity) {
        if (i == s.size()) {
            if (leading_zero)
                return 0;
            if (s.size() < 2)
                return 0;
            if (diff)
                return 0;
            return 1;
        }

        if (dp[i][tight][leading_zero][parity][diff+144] != -1)
            return dp[i][tight][leading_zero][parity][diff+144];

        long long lb = 0;
        long long ub = tight ? (s[i] - '0') : 9;
        long long res = 0;

        for (long long digit = lb; digit <= ub; digit++) {
            if (leading_zero && digit == 0) {
                res +=
                    func(s, (tight && digit == ub), i + 1, true, diff, parity);
            } else {
                long long newDiff = parity ? diff - digit : diff + digit;
                bool newParity = parity^1;
                res += func(s, (tight && digit == ub), i + 1, false, newDiff,
                            newParity);
            }
        }
        return dp[i][tight][leading_zero][parity][diff+144] = res;
    }
    long long solve(long long a, long long b) {
        string left = to_string(a - 1);
        string right = to_string(b);
        memset(dp, -1, sizeof(dp));
        long long leftAns = func(left, 1, 0,true, 0, 0);
        memset(dp, -1, sizeof(dp));
        long long rightAns = func(right, 1, 0,true, 0,0);
        return rightAns - leftAns;
    }
    long long countBalanced(long long low, long long high) {
        return solve(low,high);
    }
};


//Time Complexity: O(Length of number * 2 * 2 * 2 * 289 * 10) ~ O(100000) ~ O(1)
//Space Complexity: O(Length of number * 2 * 2 * 2 * 289) ~ O(20000) ~ O(1)
//Length of number = 16 (as high can be 10^15)

//Explanation:
// This is a Digit DP where we count numbers digit-by-digit while tracking balance between odd and even positions. The DP state keeps the index, tight flag, leading-zero flag, position parity (odd/even from the first non-zero digit), and diff = sumOdd − sumEven. Leading zeros don’t affect parity or diff; once a non-zero digit appears, it’s placed at the current parity, added or subtracted from diff, and parity flips. At the end, a number is valid only if it has started, has at least two digits, and diff == 0. We memoize states, shift diff to stay in bounds, and compute the range answer using count(high) − count(low−1).