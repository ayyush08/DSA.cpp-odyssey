// Shortest Common Supersequence
// Difficulty: MediumAccuracy: 55.62%Submissions: 130K+Points: 4
// Given two strings s1 and s2, find the length of the smallest string which has both s1 and s2 as its sub-sequences.
// Note: s1 and s2 can have both uppercase and lowercase English letters.

// Examples:

// Input: s1 = "geek", s2 = "eke"
// Output: 5
// Explanation: String "geeke" has both string "geek" and "eke" as subsequences.
// Input: s1 = "AGGTAB", s2 = "GXTXAYB"
// Output: 9
// Explanation: String "AGXGTXAYB" has both string "AGGTAB" and "GXTXAYB" as subsequences.
// Input: s1 = "geek", s2 = "ek"
// Output: 4
// Explanation: String "geek" has both string "geek" and "ek" as subsequences.
// Constraints:
// 1<= s1.size(), s2.size() <= 500



#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
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

public:
    int shortestCommonSupersequence(string &s1, string &s2)
    {
        // code here
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return m + n - fun(dp, m, n, s1, s2);
    }
};
