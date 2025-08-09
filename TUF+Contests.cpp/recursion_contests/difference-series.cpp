// Different Series
// Return the nth term of the series given by:

// xi = i + xi-1 + 1, where n1 is the 1st term of the series and has value = 1.

// Examples:
// Input: n = 3

// Output: 8

// Explanation: n2 = 2 + n1 + 1 = 2 + 1 + 1 = 4

// n3 = 3 + n2 + 1 = 3 + 4 + 1 = 8

// Input: n = 4

// Output: 13

// Explanation: n4 = 4 + n3 + 1 = 4 + 8 + 1 = 13

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int series(int n, int i)
    {
        if (i == 1)
            return 1;

        return n + series(n - 1, i - 1) + 1;
    }
    int nthSpecialElement(int n)
    {
        return series(n, n);
    }
};

// Time Complexity:O(n^2) due to the recursive calls where series(n, n) calls series(n-1, n-1) and so on, resulting in n levels of recursion, each with n operations effectively.
// Space Complexity:O(n) due to the recursive call stack, which can grow up to n frames deep.