// Shortest common supersequence

// 38

// 100
// Hard

// Given two strings str1 and str2, find the shortest common supersequence.

// The shortest common supersequence is the shortest string that contains both str1 and str2 as subsequences.

// Examples:
// Input: str1 = "mno", str2 = "nop"

// Output: "mnop"

// Explanation: The shortest common supersequence is "mnop". It contains "mno" as the first three characters and "nop" as the last three characters, thus including both strings as subsequences.

// Input: str1 = "dynamic", str2 = "program"

// Output: "dynprogramic"

// Explanation: The shortest common supersequence is "dynprogramic". It includes all characters from both "dynamic" and "program", with minimal overlap. For example, "dynamic" appears as "dyn...amic" and "program" appears as "...program..." within "dynprogramic".

// Intuition; SCS = str1 + str2 - LCS(str1, str2)
// to reconstruct we can backtrack the lcs matrix taking into consideration the longest common subsequence as they will be part of the SCS only once

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2,
                                 vector<vector<int>> &dp)
    {
        int m = text1.size();
        int n = text2.size();

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
    string shortestCommonSupersequence(string str1, string str2)
    {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int lcs = longestCommonSubsequence(str1, str2, dp);
        int i = m, j = n;
        int idx = lcs - 1;
        string ans = "";
        while (i && j)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                ans += str1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans += str1[i - 1];
                i--;
            }
            else
            {
                ans += str2[j - 1];
                j--;
            }
        }
        while (i)
        {
            ans += str1[i - 1];
            i--;
        }
        while (j)
        {
            ans += str2[j - 1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//TIme Complexity: O(m*n)
//Space Complexity: O(m*n)
