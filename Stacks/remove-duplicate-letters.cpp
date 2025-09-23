// Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

// Example 1:

// Input: s = "bcabc"
// Output: "abc"
// Example 2:

// Input: s = "cbacdcbc"
// Output: "acdb"

// Constraints:

// 1 <= s.length <= 104
// s consists of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
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