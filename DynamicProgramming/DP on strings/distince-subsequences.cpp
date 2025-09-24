// Distinct subsequences/

// Given two strings s and t, return the number of distinct subsequences of s that equal t.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters. For example, "ace" is a subsequence of "abcde" while "aec" is not.

// The task is to count how many different ways we can form t from s by deleting some (or no) characters from s. Return the result modulo 109+7.

// Examples:
// Input: s = "axbxax", t = "axa"

// Output: 2

// Explanation: In the string "axbxax", there are two distinct subsequences "axa":

// (a)(x)bx(a)x

// (a)xb(x)(a)x

// Input: s = "babgbag", t = "bag"

// Output: 5

// Explanation: In the string "babgbag", there are five distinct subsequences "bag":

// (ba)(b)(ga)(g)

// (ba)(bg)(ag)

// (bab)(ga)(g)

// (bab)(g)(ag)

// (babg)(a)(g)

// Memoization - O(m*n) time and O(m*n)+O(m+n) space

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    int func(int i, int j, vector<vector<int>> &dp, string &s, string &t)
    {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int res = 0;
        if (s[i - 1] == t[j - 1])
        {
            int takeThis = func(i - 1, j - 1, dp, s, t);
            int leaveThis = func(i - 1, j, dp, s, t);
            res = (takeThis + leaveThis) % mod;
        }
        else
        {
            int proceed = func(i - 1, j, dp, s, t);
            res = proceed % mod;
        }
        return dp[i][j] = res;
    }
    int distinctSubsequences(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return func(m, n, dp, s, t);
    }
};

// Tabulation - O(m*n) time and O(m*n) space

class Solution
{
public:
    int mod = 1e9 + 7;
    int distinctSubsequences(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++)
            dp[i][0] = 1;
        // column 0 initialization not needd already 0
        for (int i = 1; i <= m; i++)
        {
            int res = 0;
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    int takeThis = dp[i - 1][j - 1];
                    int leaveThis = dp[i - 1][j];
                    res = (takeThis + leaveThis) % mod;
                }
                else
                {
                    res = dp[i - 1][j] % mod;
                }
                dp[i][j] = res;
            }
        }
        return dp[m][n];
    }
};

// Space Optimization - O(m*n) time and O(n) space

class Solution
{
public:
    int mod = 1e9 + 7;
    int distinctSubsequences(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        prev[0] = 1;
        // column 0 initialization not needd already 0
        for (int i = 1; i <= m; i++)
        {
            int res = 0;
            curr[0] = 1;
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    int takeThis = prev[j - 1];
                    int leaveThis = prev[j];
                    res = (takeThis + leaveThis) % mod;
                }
                else
                {
                    res = prev[j] % mod;
                }
                curr[j] = res;
            }
            prev = curr;
        }
        return prev[n];
    }
};

// Space Optimization 2 - O(m*n) time and O(n) space , we can use the 0-1 knapsack approach here also, by traversing j from n to 1, why? because we are using the previous row values only, so if we traverse j from n to 1, then we can use the same array for current and previous row

class Solution
{
public:
    int mod = 1e9 + 7;
    int distinctSubsequences(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        vector<int> prev(n + 1, 0);
        prev[0] = 1;
        // column 0 initialization not needd already 0
        for (int i = 1; i <= m; i++)
        {
            int res = 0;
            for (int j = n; j >= 1; j--)
            {
                if (s[i - 1] == t[j - 1])
                {
                    int takeThis = prev[j - 1];
                    int leaveThis = prev[j];
                    res = (takeThis + leaveThis) % mod;
                }
                else
                {
                    res = prev[j] % mod;
                }
                prev[j] = res;
            }
        }
        return prev[n];
    }
};