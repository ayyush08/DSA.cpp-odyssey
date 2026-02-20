// Number of distinct substrings in a string
// Given a string s, determine the number of distinct substrings (including the empty substring) of the given string.

// A string B is a substring of a string A if B can be obtained by deleting several characters (possibly none) from the start of A and several characters (possibly none) from the end of A.

// Two strings X and Y are considered different if there is at least one index i such that the character of X at index i is different from the character of Y at index i (X[i] != Y[i]).

// Example 1

// Input : s = "aba"

// Output : 6

// Explanation :

// The distinct substrings are "a", "ab", "ba", "b", "aba", "".

// Example 2

// Input : s = "abc"

// Output : 7

// Explanation :

// The distinct substrings are "a", "ab", "abc", "b", "bc", "c", "".

// Example 3

// Input : s = "aaabc"

// Output:

// 13
// Constraints

// 1 <= s.length <= 103
// s consist of only lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    Node()
    {
        for (int i = 0; i < 26; i++)
            links[i] = NULL;
    }
    Node *get(char c) { return links[c - 'a']; }
    bool containsKey(char c) { return links[c - 'a'] != NULL; }
    void put(char c, Node *node) { links[c - 'a'] = node; }
};
class Solution
{
public:
    int countDistinctSubstring(string s)
    {
        int n = s.size();
        Node *root = new Node();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            Node *node = root;
            for (int j = i; j < n; j++)
            {
                if (!node->containsKey(s[j]))
                {
                    ans++;
                    node->put(s[j], new Node());
                }
                node = node->get(s[j]);
            }
        }
        return ans + 1;
    }
};