// Minimum insertions to make string palindrome

// Given a string s, find the minimum number of insertions needed to make it a palindrome. A palindrome is a sequence that reads the same backward as forward. You can insert characters at any position in the string.

// Examples:
// Input: s = "abcaa"

// Output: 2

// Explanation: Insert 2 characters "c", and "b" to make "abcacba", which is a palindrome.

// Input: s = "ba"

// Output: 1

// Explanation: Insert "a" at the beginning to make "aba", which is a palindrome.

#include <bits/stdc++.h>
using namespace std;

// Intuition: Minimum insertions to make string palindrome = Length of string - Length of longest palindromic subsequence

class Solution
{
public:
    int longestPalindromeSubsequence(string a)
    {
        int n = a.size();
        string b = a;
        reverse(b.begin(), b.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i - 1] == b[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
    int minInsertion(string s)
    {
        return s.size() - longestPalindromeSubsequence(s);
    }
};
