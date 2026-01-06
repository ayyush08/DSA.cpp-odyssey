// 211. Design Add and Search Words Data Structure

// Design a data structure that supports adding new words and finding if a string matches any previously added string.

// Implement the WordDictionary class:

// WordDictionary() Initializes the object.
// void addWord(word) Adds word to the data structure, it can be matched later.
// bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

// Example:

// Input
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
// [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
// Output
// [null,null,null,null,false,true,true,true]

// Explanation
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("bad");
// wordDictionary.addWord("dad");
// wordDictionary.addWord("mad");
// wordDictionary.search("pad"); // return False
// wordDictionary.search("bad"); // return True
// wordDictionary.search(".ad"); // return True
// wordDictionary.search("b.."); // return True

// Constraints:

// 1 <= word.length <= 25
// word in addWord consists of lowercase English letters.
// word in search consist of '.' or lowercase English letters.
// There will be at most 2 dots in word for search queries.
// At most 104 calls will be made to addWord and search.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool isEnd = false;
    bool containsKey(char c) { return (links[c - 'a'] != NULL); }
    void put(char c, Node *node) { links[c - 'a'] = node; }
    bool isEnding() { return isEnd; }
    void markEnd() { isEnd = true; }
    Node *get(char c) { return links[c - 'a']; }
};
class WordDictionary
{
private:
    Node *root;
    bool dfs(int i, string &word, Node *node)
    {
        if (!node)
            return false;

        if (i == word.size())
            return node->isEnding();

        char c = word[i];

        if (c == '.')
        {
            for (int ch = 0; ch < 26; ch++)
            {
                if (node->links[ch])
                {
                    if (dfs(i + 1, word, node->links[ch]))
                        return true;
                }
            }
            return false;
        }
        else
        {
            if (!node->containsKey(c))
                return false;
            return dfs(i + 1, word, node->get(c));
        }
    }

public:
    WordDictionary() { root = new Node(); }

    void addWord(string word)
    {
        Node *node = root;
        for (char c : word)
        {
            if (!node->containsKey(c))
                node->put(c, new Node());
            node = node->get(c);
        }
        node->markEnd();
    }

    bool search(string word) { return dfs(0, word, root); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */