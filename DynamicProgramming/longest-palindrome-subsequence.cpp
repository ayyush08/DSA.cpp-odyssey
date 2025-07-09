// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".
// Example 2:

// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".

// Constraints:

// 1 <= s.length <= 1000
// s consists only of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

// 1. Top-down approach using recursion with memoization

class Solution
{
private:
    int fun(vector<vector<int>> &dp, int i, int j, string &s)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == j)
            return 1;
        if (s[i] == s[j])
        {
            return dp[i][j] = 2 + fun(dp, i + 1, j - 1, s);
        }
        return dp[i][j] = max(fun(dp, i + 1, j, s), fun(dp, i, j - 1, s));
    }

public:
    int longestPalindromeSubseq(string s)
    {
        int m = s.size();
        // dp[i][j] = length of LPS in subarray[i...j]
        vector<vector<int>> dp(m, vector<int>(m, -1));
        int left = 0, right = m - 1;
        return fun(dp, left, right, s);
    }
};

// 2. Bottom-up approach using dynamic programming

class Solution2
{
public:
    int longestPalindromeSubseq(string s)
    {
        int m = s.size();
        // dp[i][j] = length of LPS in subarray[i...j]
        vector<vector<int>> dp(m, vector<int>(m, 0));
        int left = 0, right = m - 1;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = i; j < m; j++)
            {
                if (s[i] == s[j])
                {
                    if (i == j)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][m - 1];
    }
};
