// Longest Substring Without Repeating Characters
// Given a string, S. Find the length of the longest substring without repeating characters.

// Examples:
// Input : S = "abcddabac"

// Output : 4

// Explanation : The answer is "abcd" , with a length of 4.

// Input : S = "aaabbbccc"

// Output : 2

// Explanation : The answers are "ab" , "bc". Both have maximum length 2.

#include <bits/stdc++.h>
using namespace std;

// Brute - check all substrings using hash, O(n^2) ans space O(256)

class Solution
{
public:
    int longestNonRepeatingSubstring(string &s)
    {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            vector<int> hash(256, 0);
            for (int j = i; j < n; j++)
            {
                if (hash[s[j]] == 1)
                    break;

                hash[s[j]] = 1;

                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

// Optimal : Use hash window and update to next non repeating when found
class Solution2
{
public:
    int longestNonRepeatingSubstring(string &s)
    {
        int n = s.size();
        int ans = 0;
        int l = 0, r = 0;
        vector<int> hash(256, -1);
        while (r < n)
        {
            if (hash[s[r]] != -1)
            {
                l = max(hash[s[r]] + 1, l);
            }

            int window = r - l + 1;
            hash[s[r]] = r;

            ans = max(window, ans);
            r++;
        }
        return ans;

        return ans;
    }
};