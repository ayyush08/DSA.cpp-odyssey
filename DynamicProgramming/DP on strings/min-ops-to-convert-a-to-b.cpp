// Minimum insertions or deletions to convert string A to B

// Hints

// Given two strings str1 and str2, find the minimum number of insertions and deletions in string str1 required to transform str1 into str2.

// Insertion and deletion of characters can take place at any position in the string.

// Examples:
// Input: str1 = "kitten", str2 = "sitting"

// Output: 5

// Explanation: To transform "kitten" to "sitting", delete "k" and insert "s" to get "sitten", then insert "i" to get "sittin", and insert "g" at the end to get "sitting".

// Input: str1 = "flaw", str2 = "lawn"

// Output: 2

// Explanation: To transform "flaw" to "lawn", delete "f" and insert "n" at the end. Hence minimum number of operations required is 2".

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lcs(string a, string b)
    {
        int m = a.size();
        int n = b.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
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
        return dp[m][n];
    }
    int minOperations(string str1, string str2)
    {
        int l = lcs(str1, str2);
        return (str1.size() - l) + (str2.size() - l); // deletions + insertions will be equal to size of str1 - lcs + size of str2 - lcs because we do not need the common part in the operations
    }
};