// Longest String Chain

// Given an array of strings words[], the task is to return the longest string chain. A string chain is defined as a sequence of words where:

// Each word (except the first) can be formed by inserting exactly one character into the previous word.

// The first word of the chain can be any word from the words[] array.

// The task is to determine the length of the longest chain.

// Examples:
// Input: words = ["a", "ab", "abc", "abcd", "abcde"]

// Output: 5

// Explanation: The longest chain is ["a", "ab", "abc", "abcd", "abcde"].

// Each word in the chain is formed by adding exactly one character to the previous word.

// Input: words = ["dog", "dogs", "dots", "dot", "d", "do"]

// Output: 4

// Explanation: The longest chain is ["d", "do", "dot", "dots"].

// Each word is formed by inserting one character into the previous word.

#include <bits/stdc++.h>
using namespace std;

// simply sort words by length and apply LIS type DP with chain checking function

//Time Complexity: O(N^2 * L) where N is the number of words and L is the maximum length of a word.
//Space Complexity: O(N) for the dp array.
class Solution
{
public:
    static bool comp(string &s, string &t)
    {
        return s.size() < t.size();
    }
    bool isChain(string a, string b)
    {
        if (a.size() != b.size() + 1)
            return false;
        int first = 0, second = 0;
        while (first < a.size())
        {
            if (second < b.size() && a[first] == b[second])
            {
                first++;
                second++;
            }
            else
                first++;
        }
        return (first == a.size() && second == b.size());
    }
    int longestStringChain(vector<string> &words)
    {
        int n = words.size();
        vector<int> dp(n, 1);
        int ans = 0;
        sort(words.begin(), words.end(), comp);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (isChain(words[i], words[j]) && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
