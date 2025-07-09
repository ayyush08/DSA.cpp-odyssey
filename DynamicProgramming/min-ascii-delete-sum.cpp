// Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

// Example 1:

// Input: s1 = "sea", s2 = "eat"
// Output: 231
// Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
// Deleting "t" from "eat" adds 116 to the sum.
// At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
// Example 2:

// Input: s1 = "delete", s2 = "leet"
// Output: 403
// Explanation: Deleting "dee" from "delete" to turn the string into "let",
// adds 100[d] + 101[e] + 101[e] to the sum.
// Deleting "e" from "leet" adds 101[e] to the sum.
// At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
// If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

// Constraints:

// 1 <= s1.length, s2.length <= 1000
// s1 and s2 consist of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

// Top-down approach using recursion with memoization

class Solution
{
private:
    int fun(vector<vector<int>> &dp, int i, int j, string &s1, string &s2,
            vector<int> &prefixS1, vector<int> &prefixS2)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == 0 && j == 0)
            return 0;
        if (i == 0)
            return prefixS2[j];
        if (j == 0)
            return prefixS1[i];
        if (s1[i - 1] == s2[j - 1])
            return dp[i][j] = fun(dp, i - 1, j - 1, s1, s2, prefixS1, prefixS2);
        else
        {
            return dp[i][j] =
                       min((fun(dp, i - 1, j, s1, s2, prefixS1, prefixS2) +
                            s1[i - 1]),
                           (fun(dp, i, j - 1, s1, s2, prefixS1, prefixS2) +
                            s2[j - 1]));
        }
        return dp[i][j];
    }

public:
    int minimumDeleteSum(string s1, string s2)
    {
        // dp[i][j] = min ascii sum of deleted chasrs i s[0..i-1] and t[0...i-1]
        // become equal
        int m = s1.size();
        int n = s2.size();
        vector<int> prefixS1(m + 1, 0), prefixS2(n + 1, 0);
        //pre-compute prefix sums to avoid extra for loop in the recursive function
        for (int i = 1; i <= m; i++)
            prefixS1[i] = prefixS1[i - 1] + s1[i - 1];
        for (int j = 1; j <= n; j++)
            prefixS2[j] = prefixS2[j - 1] + s2[j - 1];
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return fun(dp, m, n, s1, s2, prefixS1, prefixS2);
    }
};