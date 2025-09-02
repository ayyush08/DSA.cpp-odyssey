// Longest Substring With At Most K Distinct Characters

// Given a string s and an integer k.Find the length of the longest substring with at most k distinct characters.

// Examples:
// Input : s = "aababbcaacc" , k = 2
// Output : 6
// Explanation : The longest substring with at most two distinct characters is "aababb".
// The length of the string 6.

// Input : s = "abcddefg" , k = 3
// Output : 4
// Explanation : The longest substring with at most three distinct characters is "bcdd".
// The length of the string 4.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kDistinctChar(string &s, int k)
    {
        int l = 0, r = 0;
        int n = s.size();
        int ans = 0;
        unordered_map<char, int> seen;
        while (r < n)
        {
            seen[s[r]]++;
            if (seen.size() > k)
            {
                seen[s[l]]--;
                if (seen[s[l]] == 0)
                    seen.erase(s[l]);
                l++;
            }
            int len = r - l + 1;
            ans = max(ans, len);
            r++;
        }
        return ans;
    }
};