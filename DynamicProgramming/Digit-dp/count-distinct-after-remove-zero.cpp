
// You are given a positive integer n.

// For every integer x from 1 to n, we write down the integer obtained by removing all zeros from the decimal representation of x.

// Return an integer denoting the number of distinct integers written down.

// Example 1:

// Input: n = 10

// Output: 9

// Explanation:

// The integers we wrote down are 1, 2, 3, 4, 5, 6, 7, 8, 9, 1. There are 9 distinct integers (1, 2, 3, 4, 5, 6, 7, 8, 9).

// Example 2:

// Input: n = 3

// Output: 3

// Explanation:

// The integers we wrote down are 1, 2, 3. There are 3 distinct integers (1, 2, 3).

// Constraints:

// 1 <= n <= 1015

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long dp[20][2][2];
    // dp[pos][tight][leading_zero]

    string s;

    long long func(int idx, int tight, int leading_zero)
    {
        if (idx == s.size())
        {
            return leading_zero ? 0 : 1;
        }

        long long &res = dp[idx][tight][leading_zero];
        if (dp[idx][tight][leading_zero] != -1)
            return dp[idx][tight][leading_zero];

        res = 0;
        int limit = tight ? (s[idx] - '0') : 9;

        for (int d = 0; d <= limit; d++)
        {

            if (d == 0 && !leading_zero)
            {
                continue;
            }

            int newTight = (tight && (d == limit));
            int newLead = (leading_zero && (d == 0));

            res += func(idx + 1, newTight, newLead);
        }

        return res;
    }
    long long countDistinct(long long n)
    {
        s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return func(0, 1, 1);
    }
};