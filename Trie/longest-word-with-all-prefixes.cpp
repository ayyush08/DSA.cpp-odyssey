// Longest Word with All Prefixes
// Given a string array nums of length n. A string is called a complete string if every prefix of this string is also present in the array nums.

// Find the longest complete string in the array nums.

// If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None" (without quotes).

// Example 1

// Input : nums = [ "n", "ni", "nin", "ninj" , "ninja" , "nil" ]

// Output : ninja

// Explanation :

// The word "ninja" is the longest word which has all its prefixes present in the array.

// Example 2

// Input : nums = [ "ninja" , "night" , "nil" ]

// Output : None

// Explanation :

// There is no string that has all its prefix present in array. So we return None.

// Example 3

// Input : nums = [ "cat" , "car" , "cow", "c", "ca", "t", "r", "w" ]

// Output:

// car
// Constraints

// 1 <= n <= 105
// 1 <= nums[i].length <= 105
// 1 <= sum(nums[i].length) <= 105
// nums[i] consist only of lowercase English characters

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

    bool isEnd = false;
    bool containsKey(char c) { return links[c - 'a']; }
    void put(char c, Node *node) { links[c - 'a'] = node; }
    Node *get(char c) { return links[c - 'a']; }
    void setEnd() { isEnd = true; }
    bool isEnding() { return isEnd; }
};
struct Trie
{
public:
    Node *root;
    void init() { root = new Node; }
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                node->put(word[i], new Node());
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool containsPrefix(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                if (!node->isEnding())
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};
class Solution
{
public:
    string completeString(vector<string> &nums)
    {
        Trie trie;
        trie.init();
        sort(nums.begin(), nums.end());
        for (auto word : nums)
        {
            trie.insert(word);
        }
        string longest = "";
        for (auto word : nums)
        {
            if (trie.containsPrefix(word))
            {
                if (word.size() > longest.size())
                    longest = word;
                else if (word.size() == longest.size() && word < longest)
                    longest = word;
            }
        }

        return longest.size() ? longest : "None";
    }
};