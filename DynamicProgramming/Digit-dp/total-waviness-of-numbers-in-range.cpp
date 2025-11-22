// You are given two integers num1 and num2 representing an inclusive range [num1, num2].
// The waviness of a number is defined as the total count of its peaks and valleys:

// A digit is a peak if it is strictly greater than both of its immediate neighbors.
// A digit is a valley if it is strictly less than both of its immediate neighbors.
// The first and last digits of a number cannot be peaks or valleys.
// Any number with fewer than 3 digits has a waviness of 0.
// Return the total sum of waviness for all numbers in the range [num1, num2].


// Example 1:
// Input: num1 = 120, num2 = 130
// Output: 3
// Explanation:
// In the range [120, 130]:
// 120: middle digit 2 is a peak, waviness = 1.
// 121: middle digit 2 is a peak, waviness = 1.
// 130: middle digit 3 is a peak, waviness = 1.
// All other numbers in the range have a waviness of 0.
// Thus, total waviness is 1 + 1 + 1 = 3.

// Example 2:
// Input: num1 = 198, num2 = 202
// Output: 3
// Explanation:
// In the range [198, 202]:
// 198: middle digit 9 is a peak, waviness = 1.
// 201: middle digit 0 is a valley, waviness = 1.
// 202: middle digit 0 is a valley, waviness = 1.
// All other numbers in the range have a waviness of 0.
// Thus, total waviness is 1 + 1 + 1 = 3.

// Example 3:
// Input: num1 = 4848, num2 = 4848
// Output: 2
// Explanation:
// Number 4848: the second digit 8 is a peak, and the third digit 4 is a valley, giving a waviness of 2.

// Constraints:
// 1 <= num1 <= num2 <= 1015​​​​​​​

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    struct Node
    {
        long long sum; // total waviness
        long long cnt; // how many numbers
    };

    Node dp[2][11][11][20][2];
    bool vis[2][11][11][20][2];
    string s;

public:
    Node dfs(int idx, int prev, int secondPrev, bool tight, bool leadingZero)
    {

        if (idx == s.size())
        {
            return {0, 1};
        }

        if (vis[tight][prev][secondPrev][idx][leadingZero])
            return dp[tight][prev][secondPrev][idx][leadingZero];

        vis[tight][prev][secondPrev][idx][leadingZero] = true;
        Node &res = dp[tight][prev][secondPrev][idx][leadingZero];
        res = {0, 0};

        int ub = tight ? (s[idx] - '0') : 9;

        for (int digit = 0; digit <= ub; digit++)
        {

            bool newTight = tight && (digit == ub);
            bool newLZ = leadingZero && (digit == 0);

            long long wavy = 0;
            if (prev != 10 && secondPrev != 10)
            {
                if ((prev > secondPrev && prev > digit) ||
                    (prev < secondPrev && prev < digit))
                    wavy = 1;
            }

            int newPrev = newLZ ? 10 : digit;
            int newSecondPrev = newLZ ? 10 : prev;

            Node child = dfs(idx + 1, newPrev, newSecondPrev, newTight, newLZ);

            res.sum += child.sum + wavy * child.cnt;
            res.cnt += child.cnt;
        }

        return res;
    }

    long long solveOne(long long x)
    {
        if (x < 0)
            return 0;
        s = to_string(x);
        memset(vis, 0, sizeof(vis));
        return dfs(0, 10, 10, true, true).sum;
    }

    long long totalWaviness(long long num1, long long num2)
    {
        return solveOne(num2) - solveOne(num1 - 1);
    }
};