// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation:
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')

// Constraints:

// 0 <= word1.length, word2.length <= 500
// word1 and word2 consist of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

// Recursive approach with memoization (Top-down approach) - O(m*n) time and O(m*n) space {Might give TLE for large inputs}
class Solution
{
private:
    int fun(vector<vector<int>> &dp, int i, int j, string &word1, string &word2)
    {
        if (i == 0 && j == 0)
            return 0;
        if (i == 0)
            return j;
        if (j == 0)
            return i;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (word1[i - 1] == word2[j - 1])
        {
            return dp[i][j] = fun(dp, i - 1, j - 1, word1, word2);
        }
        else
        {
            return dp[i][j] = 1 + min(fun(dp, i - 1, j, word1, word2), min(fun(dp, i - 1, j - 1, word1, word2), fun(dp, i, j - 1, word1, word2)));
        }
    }

public:
    int minDistance(string word1, string word2)
    {
        // ones insertion is others deletion
        // dp[i][j] - min ops to make s[0..i-1] and t[0..i-1] equal
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return fun(dp, m, n, word1, word2);
    }
};

// Tabulation (Bottom-up approach) - O(m*n) time and O(m*n) space
class Solution
{
public:
    int editDistance(string start, string target)
    {
        int m = start.size();
        int n = target.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++)
            dp[i][0] = i;
        for (int j = 0; j <= n; j++)
            dp[0][j] = j;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (start[i - 1] == target[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    int dontTake = dp[i - 1][j - 1];
                    int leaveStart = dp[i - 1][j];
                    int leaveTarget = dp[i][j - 1];
                    dp[i][j] = 1 + min({dontTake, leaveStart, leaveTarget});
                }
            }
        }
        return dp[m][n];
    }
};

// Space Optimization - O(m*n) time and O(n) space
class Solution
{
public:
    int editDistance(string start, string target)
    {
        int m = start.size();
        int n = target.size();  
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        for (int j = 0; j <= n; j++)
            prev[j] = j;
        for (int i = 1; i <= m; i++)
        {
            curr[0] = i;
            for (int j = 1; j <= n; j++)
            {
                if (start[i - 1] == target[j - 1])
                {
                    curr[j] = prev[j - 1];
                }
                else
                {
                    int dontTake = prev[j - 1];
                    int leaveStart = prev[j];
                    int leaveTarget = curr[j - 1];
                    curr[j] = 1 + min({dontTake, leaveStart, leaveTarget});
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};
