// Wildcard matching
// Given a string str and a pattern pat, implement a pattern matching function that supports the following special characters:

// '?' Matches any single character.

// '*' Matches any sequence of characters (including the empty sequence).

// The pattern must match the entire string.

// Examples:
// Input: str = "xaylmz", pat = "x?y*z"

// Output: true

// Explanation:

// The pattern "x?y*z" matches the string "xaylmz":

// - '?' matches 'a'

// - '*' matches "lm"

// - 'z' matches 'z'

// Input: str = "xyza", pat = "x*z"

// Output: false

// Explanation:

// The pattern "x*z" does not match the string "xyza" because there is an extra 'a' at the end of the string that is not matched by the pattern.

#include <bits/stdc++.h>
using namespace std;

// Memoization - O(m*n) time and O(m*n)+O(m+n) space

class Solution
{
public:
    int func(int i, int j, vector<vector<int>> &dp, string &str, string &pat)
    {
        if (i < 0 && j < 0)
            return 1;
        if (j < 0 && i >= 0)
            return 0;
        if (i < 0 && j >= 0)
        {
            for (int k = 0; k <= j; k++)
            {
                if (pat[k] != '*')
                    return 0;
            }
            return 1;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (str[i] == pat[j] || pat[j] == '?')
        {
            return dp[i][j] = func(i - 1, j - 1, dp, str, pat);
        }
        else if (pat[j] == '*')
        {
            return dp[i][j] = func(i - 1, j, dp, str, pat) ||
                              func(i, j - 1, dp, str, pat);
        }
        return dp[i][j] = 0;
    }
    bool wildCard(string str, string pat)
    {
        int m = str.size();
        int n = pat.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return func(m - 1, n - 1, dp, str, pat);
    }
};

// Tabulation - O(m*n) time and O(m*n) space

class Solution
{
public:
    bool wildCard(string str, string pat)
    {
        int m = str.size();
        int n = pat.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
        dp[0][0] = true;
        // dp[0][j] = true only if pat[0..j-1] are all '*'
        for (int j = 1; j <= n; j++)
        {
            dp[0][j] = (pat[j - 1] == '*') && dp[0][j - 1];
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str[i - 1] == pat[j - 1] || pat[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (pat[j - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

// Space Optimized - O(m*n) time and O(n) space

class Solution
{
public:
    bool wildCard(string str, string pat)
    {
        int m = str.size();
        int n = pat.size();
        vector<bool> prev(n + 1, false);
        vector<bool> curr(n + 1, false);
        prev[0] = true;
        for (int j = 1; j <= n; j++)
        {
            prev[j] = (pat[j - 1] == '*') && prev[j - 1];
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str[i - 1] == pat[j - 1] || pat[j - 1] == '?')
                {
                    curr[j] = prev[j - 1];
                }
                else if (pat[j - 1] == '*')
                {
                    curr[j] = prev[j] || curr[j - 1];
                }
                else
                {
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};
