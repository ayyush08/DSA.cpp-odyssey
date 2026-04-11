// 3844. Longest Almost-Palindromic Substring
// You are given a string s consisting of lowercase English letters.

// A substring is almost-palindromic if it becomes a palindrome after removing exactly one character from it.

// Return an integer denoting the length of the longest almost-palindromic substring in s.

// Example 1:

// Input: s = "abca"

// Output: 4

// Explanation:

// Choose the substring "abca".

// Remove "abca".
// The string becomes "aba", which is a palindrome.
// Therefore, "abca" is almost-palindromic.
// Example 2:

// Input: s = "abba"

// Output: 4

// Explanation:

// Choose the substring "abba".

// Remove "abba".
// The string becomes "aba", which is a palindrome.
// Therefore, "abba" is almost-palindromic.
// Example 3:

// Input: s = "zzabba"

// Output: 5

// Explanation:

// Choose the substring "zzabba".

// Remove "zabba".
// The string becomes "abba", which is a palindrome.
// Therefore, "zabba" is almost-palindromic.

// Constraints:

// 2 <= s.length <= 2500
// s consists of only lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

// Memoization : if mismatch count 1 then check if remaining string is palindrome or not
//Time Complexity: O(n^3) and Space Complexity: O(n^2)

class Solution
{
    public:
        int n;
        vector<vector<int>> dp;
        int solve(int i, int j, string &s)
        {
            if (i >= j)
                return 0;
            if (dp[i][j] != -1)
                return dp[i][j];

            if (s[i] == s[j])
                return dp[i][j] = solve(i + 1, j - 1, s);
            else
                return dp[i][j] = 1 + min(solve(i + 1, j, s), solve(i, j - 1, s));
        }
        int almostPalindromic(string s)
        {
            n = s.size();
            dp.assign(n, vector<int>(n, -1));
            int laps = 1;
            for (int i = 0; i < n; i++)
            {
                for (int j = i; j < n; j++)
                {
                    if (solve(i, j, s) <= 1)
                        laps = max(laps, j - i + 1);
                }
            }
            return laps;
        }
};

// 2. Tabulation : if mismatch count 1 then check if remaining string is palindrome or not
//Time Complexity: O(n^2) and Space Complexity: O(n^2)

class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int almostPalindromic(string s) {
        n = s.size();
        dp.assign(n,vector<int>(n,0));
        int laps = 1;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i>=j) dp[i][j] = 0;
                else if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1];
                else{
                    dp[i][j] = 1+min(dp[i+1][j],dp[i][j-1]);
                }
                if(dp[i][j]<=1) laps = max(laps,j-i+1);
            }
        }
        return laps;
    }
};