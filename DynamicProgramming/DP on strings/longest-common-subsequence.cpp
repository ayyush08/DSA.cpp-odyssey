// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

// Example 1:

// Input: text1 = "abcde", text2 = "ace"
// Output: 3
// Explanation: The longest common subsequence is "ace" and its length is 3.
// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.
// Example 3:

// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.

// Constraints:

// 1 <= text1.length, text2.length <= 1000
// text1 and text2 consist of only lowercase English characters.

#include <bits/stdc++.h>
using namespace std;

// Recursive approach with memoization (Top-down approach)
class Solution
{
public:
    int fun(vector<vector<int>> &dp, int m, int n, string &txt1, string &txt2)
    {
        if (m <= 0 || n <= 0)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];
        if (txt1[m - 1] == txt2[n - 1])
            return dp[m][n] = 1 + fun(dp, m - 1, n - 1, txt1, txt2);

        else if (txt1[m - 1] != txt2[n - 1])
            return dp[m][n] = max(fun(dp, m - 1, n, txt1, txt2), fun(dp, m, n - 1, txt1, txt2));
        return dp[m][n];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        // dp[i][j] = length of LCS in first i chars of s and first j chars of t
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return fun(dp, m, n, text1, text2);
    }
};

// Another approach using dynamic programming with bottom-up approach
class Solution2
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        // dp[i][j] = length of LCS in first i chars of s and first j chars of t
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // dp[0][0] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

// Space Optimization    - O(m*n) time and O(n) space

class Solution
{
public:
    int lcs(string str1, string str2)
    {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                }
                else
                {
                    curr[j] = max(curr[j - 1], prev[j]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};
