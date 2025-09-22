// Longest common substring

// Given two strings str1 and str2, find the length of their longest common substring.

// A substring is a contiguous sequence of characters within a string.

// Examples:
// Input: str1 = "abcde", str2 = "abfce"

// Output: 2

// Explanation: The longest common substring is "ab", which has a length of 2.

// Input: str1 = "abcdxyz", str2 = "xyzabcd"

// Output: 4

// Explanation: The longest common substring is "abcd", which has a length of 4.

// Input: str1 = "abcdef", str2 = "ghijkl"

// Output:
// 0

#include <bits/stdc++.h>
using namespace std;

// Memoization - will need 3 states (i, j, count) which can be messy and complex

// Tabulation - 2 states (i, j) . O(m*n) time and O(m*n) space

class Solution
{
public:
    int longestCommonSubstr(string str1, string str2)
    {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};

// Space optimization - O(m*n) time and O(n) space
class Solution
{
public:
    int longestCommonSubstr(string str1, string str2)
    {
        int m = str1.size();
        int n = str2.size();
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                    ans = max(ans, curr[j]);
                }
                else
                {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
        return ans;
    }
};
