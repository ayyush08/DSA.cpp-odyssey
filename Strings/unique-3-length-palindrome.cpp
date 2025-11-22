// 1930. Unique Length-3 Palindromic Subsequences
// Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

// Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

// A palindrome is a string that reads the same forwards and backwards.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".

// Example 1:

// Input: s = "aabca"
// Output: 3
// Explanation: The 3 palindromic subsequences of length 3 are:
// - "aba" (subsequence of "aabca")
// - "aaa" (subsequence of "aabca")
// - "aca" (subsequence of "aabca")
// Example 2:

// Input: s = "adc"
// Output: 0
// Explanation: There are no palindromic subsequences of length 3 in "adc".
// Example 3:

// Input: s = "bbcbaba"
// Output: 4
// Explanation: The 4 palindromic subsequences of length 3 are:
// - "bbb" (subsequence of "bbcbaba")
// - "bcb" (subsequence of "bbcbaba")
// - "bab" (subsequence of "bbcbaba")
// - "aba" (subsequence of "bbcbaba")

// Constraints:

// 3 <= s.length <= 105
// s consists of only lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

// Approach-1: store unique letters and for each letter find leftmost and rightmost occurrence and count unique letters in between

// Time Complexity: O(26 * N) ~ O(N)
// Space Complexity: O(1)
class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int n = s.size();
        unordered_set<char> letters;
        for (char c : s)
            letters.insert(c);

        int ans = 0;

        for (char letter : letters)
        {
            int leftMost = -1;
            int rightMost = -1;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == letter)
                {
                    if (leftMost == -1)
                        leftMost = i;
                    rightMost = i;
                }
            }

            unordered_set<char> st;
            for (int mid = leftMost + 1; mid <= rightMost - 1; mid++)
            {
                st.insert(s[mid]);
            }
            ans += st.size();
        }
        return ans;
    }
};

// Approach 2: Precompute leftMost and rightMost occurrence for each letter
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int n = s.size();
        vector<pair<int, int>> indices(26, {-1, -1});

        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            int idx = c - 'a';

            if (indices[idx].first == -1)
                indices[idx].first = i;
            indices[idx].second = i;
        }

        int ans = 0;

        for (int i = 0; i < 26; i++)
        {
            int leftMost = indices[i].first;
            int rightMost = indices[i].second;
            if (leftMost == -1)
                continue;
            unordered_set<char> st;
            for (int mid = leftMost + 1; mid <= rightMost - 1; mid++)
            {
                st.insert(s[mid]);
            }
            ans += st.size();
        }
        return ans;
    }
};