// Lexicographically Smallest String

// You are given a string s consisting of lowercase letters. Your task is to remove duplicate characters from s such that each character appears only once. Among all possible results, return the one that is the smallest in lexicographical order.

// The order of the remaining characters must preserve the relative positions of their first occurrences in s.

// Examples:
// Input: s = "ecbacd"

// Output: "ebacd"

// Explanation: By removing duplicates and maintaining lexicographical order, the result is "ecbacd".

// Input: s = "aaaabbbbcccc"

// Output: "abc"

// Explanation: After removing duplicates, the smallest lexicographical string is "abc".

// Constraints:
// 1 <= s.length <= 105

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string lexicographicallySmallestString(string s)
    {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        set<char> seen;
        string ans = "";
        for (char c : s)
        {
            freq[c - 'a']--;
            if (seen.count(c))
                continue;
            while (!ans.empty() && ans.back() > c && freq[ans.back() - 'a'] > 0)
            {
                seen.erase(ans.back());
                ans.pop_back();
            }
            ans += c;
            seen.insert(c);
        }
        return ans;
    }
};
