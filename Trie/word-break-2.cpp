// 140. Word Break II
// Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Example 1:

// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]
// Example 2:

// Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
// Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
// Explanation: Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: []

// Constraints:

// 1 <= s.length <= 20
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 10
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.
// Input is generated in a way that the length of the answer doesn't exceed 105.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool isEnd = false;
    bool containsKey(char c) { return links[c - 'a'] != NULL; }
    void put(char c, Node *node) { links[c - 'a'] = node; }
    Node *get(char c) { return links[c - 'a']; }
    void setEnd() { isEnd = true; }
    bool isEnding() { return isEnd; }
};
class Solution
{
private:
    Node *root;
    unordered_map<int, vector<string>> dp;
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]); // moves to reference trie
        }
        node->setEnd();
    }
    vector<string> dfs(int i, string &s)
    {
        if (dp.count(i))
            return dp[i];

        vector<string> words;

        if (i == s.size())
        {
            words.push_back("");
            return dp[i] = words;
        }
        Node *node = root;

        for (int j = i; j < s.size(); j++)
        {
            char c = s[j];
            if (!node->containsKey(c))
                break;

            node = node->get(c);

            if (node->isEnding())
            {
                string word = s.substr(i, j - i + 1);
                vector<string> furtherWords = dfs(j + 1, s);

                for (string w : furtherWords)
                {
                    if (w == "")
                        words.push_back(word);
                    else
                        words.push_back(word + " " + w);
                }
            }
        }
        return dp[i] = words;
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        root = new Node();
        for (string word : wordDict)
            insert(word);
        return dfs(0, s);
    }
};