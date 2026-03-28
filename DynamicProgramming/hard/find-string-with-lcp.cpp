// 2573. Find the String with LCP
// We define the lcp matrix of any 0-indexed string word of n lowercase English letters as an n x n grid such that:

// lcp[i][j] is equal to the length of the longest common prefix between the substrings word[i,n-1] and word[j,n-1].
// Given an n x n matrix lcp, return the alphabetically smallest string word that corresponds to lcp. If there is no such string, return an empty string.

// A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b. For example, "aabd" is lexicographically smaller than "aaca" because the first position they differ is at the third letter, and 'b' comes before 'c'.

// Example 1:

// Input: lcp = [[4,0,2,0],[0,3,0,1],[2,0,2,0],[0,1,0,1]]
// Output: "abab"
// Explanation: lcp corresponds to any 4 letter string with two alternating letters. The lexicographically smallest of them is "abab".
// Example 2:

// Input: lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,1]]
// Output: "aaaa"
// Explanation: lcp corresponds to any 4 letter string with a single distinct letter. The lexicographically smallest of them is "aaaa".
// Example 3:

// Input: lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,3]]
// Output: ""
// Explanation: lcp[3][3] cannot be equal to 3 since word[3,...,3] consists of only a single letter; Thus, no answer exists.

// Constraints:

// 1 <= n == lcp.length == lcp[i].length <= 1000
// 0 <= lcp[i][j] <= n

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Greedy Allocation + Finding LCP and comparing

class Solution
{
public:
    vector<vector<int>> checkLcp(string &word)
    {
        int n = word.size();
        vector<vector<int>> lcpDP(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            lcpDP[i][n - 1] = (word[i] == word[n - 1]);

        for (int j = 0; j < n; j++)
            lcpDP[n - 1][j] = (word[n - 1] == word[j]);

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                if (word[i] == word[j])
                {
                    lcpDP[i][j] = 1 + lcpDP[i + 1][j + 1];
                }
                else
                    lcpDP[i][j] = 0;
            }
        }
        return lcpDP;
    }
    string findTheString(vector<vector<int>> &lcp)
    {
        int n = lcp.size();

        string word(n, '#');

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < i; j++)
            {
                if (lcp[j][i])
                {
                    word[i] = word[j];
                    break;
                }
            }

            if (word[i] == '#')
            {
                vector<bool> notAllowed(26, false);
                for (int j = 0; j < i; j++)
                {
                    if (!lcp[j][i])
                        notAllowed[word[j] - 'a'] = true;
                }

                for (int c = 0; c < 26; c++)
                {
                    if (!notAllowed[c])
                    {
                        word[i] = c + 'a';
                        break;
                    }
                }

                if (word[i] == '#')
                    return ""; // never filled
            }
        }
        return checkLcp(word) == lcp ? word : "";
    }
};

// Approach 2: Greedy Allocation + Checking LCP on the fly
class Solution
{
public:
    bool checkLcp(string &word, vector<vector<int>> &lcp)
    {
        int n = word.size();

        for (int i = 0; i < n; i++)
            // lcpDP[i][n - 1] = (word[i] == word[n - 1]);
            if (word[i] != word[n - 1])
            {
                if (lcp[i][n - 1] != 0)
                    return false;
            }
            else
            {
                if (lcp[i][n - 1] != 1)
                    return false;
            }

        for (int j = 0; j < n; j++)
            // lcpDP[n - 1][j] = (word[n - 1] == word[j]);
            if (word[n - 1] != word[j])
            {
                if (lcp[n - 1][j] != 0)
                    return false;
            }
            else
            {
                if (lcp[n - 1][j] != 1)
                    return false;
            }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                if (word[i] == word[j])
                {
                    // lcpDP[i][j] = 1 + lcpDP[i + 1][j + 1];
                    if (lcp[i][j] != 1 + lcp[i + 1][j + 1])
                        return false;
                }
                else
                    // lcpDP[i][j] = 0;
                    if (lcp[i][j] != 0)
                        return false;
            }
        }
        return true;
    }
    string findTheString(vector<vector<int>> &lcp)
    {
        int n = lcp.size();

        string word(n, '#');

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < i; j++)
            {
                if (lcp[j][i])
                {
                    word[i] = word[j];
                    break;
                }
            }

            if (word[i] == '#')
            {
                vector<bool> notAllowed(26, false);
                for (int j = 0; j < i; j++)
                {
                    if (!lcp[j][i])
                        notAllowed[word[j] - 'a'] = true;
                }

                for (int c = 0; c < 26; c++)
                {
                    if (!notAllowed[c])
                    {
                        word[i] = c + 'a';
                        break;
                    }
                }

                if (word[i] == '#')
                    return ""; // never filled
            }
        }
        return checkLcp(word, lcp) ? word : "";
    }
};