// 854. K-Similar Strings
// Strings s1 and s2 are k-similar (for some non-negative integer k) if we can swap the positions of two letters in s1 exactly k times so that the resulting string equals s2.

// Given two anagrams s1 and s2, return the smallest k for which s1 and s2 are k-similar.

// Example 1:

// Input: s1 = "ab", s2 = "ba"
// Output: 1
// Explanation: The two string are 1-similar because we can use one swap to change s1 to s2: "ab" --> "ba".
// Example 2:

// Input: s1 = "abc", s2 = "bca"
// Output: 2
// Explanation: The two strings are 2-similar because we can use two swaps to change s1 to s2: "abc" --> "bac" --> "bca".

// Constraints:

// 1 <= s1.length <= 20
// s2.length == s1.length
// s1 and s2 contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}.
// s2 is an anagram of s1.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kSimilarity(string s1, string s2)
    {
        queue<pair<string, int>> q;
        unordered_set<string> seen;
        seen.insert(s1);
        q.push({s1, 0});
        while (q.size())
        {
            string s = q.front().first;
            int k = q.front().second;
            q.pop();
            if (s == s2)
                return k;

            int mismatchIndex = 0;
            while (mismatchIndex < s.size() && s[mismatchIndex] == s2[mismatchIndex])
                mismatchIndex++;

            for (int j = mismatchIndex + 1; j < s.size(); j++)
            {
                if (s[j] == s2[mismatchIndex] && s[j] != s2[j])
                {
                    string next = s;
                    swap(next[mismatchIndex], next[j]);
                    if (!seen.count(next))
                    {
                        seen.insert(next);
                        q.push({next, k + 1});
                    }
                }
            }
        }
        return -1;
    }
};

//Time Complexity: O(N^2 * N!) where N is the length of the string, factorial because of permutations
//Space Complexity: O(N * N!) for storing all the permutations in the worst case

//Intuition: We can use BFS to explore all the possible strings we can get by swapping characters in s1. Each level of BFS represents one swap operation. We start with s1 and explore all possible strings that can be formed by swapping characters to match s2. We keep track of the number of swaps (k) and return it when we reach s2. To optimize, we only swap characters that will help us match s2 and avoid revisiting already seen strings.