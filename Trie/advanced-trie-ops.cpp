// Trie Implementation and Advanced Operations
// Implement "TRIE” data structure from scratch with the following functions.

// Trie(): Initialize the object of this “TRIE” data structure.

// insert(“WORD”): Insert the string “WORD” into this “TRIE” data structure.

// countWordsEqualTo(“WORD”): Return how many times this “WORD” is present in this “TRIE”.

// countWordsStartingWith(“PREFIX”): Return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

// erase(“WORD”): Delete one occurrence of the string “WORD” from the “TRIE”.

// Example 1

// Input : ["Trie", "insert", "countWordsEqualTo", "insert", "countWordsStartingWith", "erase", "countWordsStartingWith"]

// [ "apple", "apple", "app", "app", "apple", "app" ]

// Output : [null, null, 1, null, 2, null, 1]

// Explanation :

// Trie trie = new Trie()

// trie.insert("apple")

// trie.countWordsEqualTo("apple")  // return 1

// trie.insert("app")

// trie.countWordsStartingWith("app") // return 2

// trie.erase("apple")

// trie.countWordsStartingWith("app")   // return 1

// Example 2

// Input : ["Trie", "insert", "countWordsEqualTo", "insert", "erase", "countWordsStartingWith"]

// [ "mango", "apple", "app", "app", "mango" ]

// Output : [null, null, 0, null, null, 1]

// Explanation :

// Trie trie = new Trie()

// trie.insert("mango")

// trie.countWordsEqualTo("apple")  // return 0

// trie.insert("app")

// trie.erase("app")

// trie.countWordsStartingWith("mango") // return 1

// Now your turn!

// Input : ["Trie", "insert", "insert", "erase", "countWordsEqualTo", "insert", "countWordsStartingWith"]

// ["abcde","fghij","abcde", "bcde", "abcde", "fgh"]

// Output:

// Pick your answer

// [null, null, null, null, 0, null, 1]

// [null, null, null, null, 0, 0, null]

// [null, null, null, 0, null, null, 0]

// [null, null, null, 0, null, 0, null]
// Constraints

// 1 <= word.length , prefix.length <= 2000
// word and prefix consist only of lowercase English letters.
// At most 3*104 calls in total will be made to insert, countWordsEqualTo , countWordsStartingWith and erase.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    int cntPrefix = 0;
    int cntEnds = 0;

    bool containsKey(char c)
    {
        return links[c - 'a'] != NULL;
    }
    void put(char c, Node *node)
    {
        links[c - 'a'] = node;
    }
    Node *get(char c)
    {
        return links[c - 'a'];
    }
    void incrementPrefix()
    {
        cntPrefix++;
    }
    void incrementEnd()
    {
        cntEnds++;
    }
    void reducePrefix()
    {
        cntPrefix--;
    }
    void reduceEnd()
    {
        cntEnds--;
    }
    int getPrefix()
    {
        return cntPrefix;
    }
    int getEnd()
    {
        return cntEnds;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (char c : word)
        {
            if (!node->containsKey(c))
            {
                node->put(c, new Node());
            }
            node = node->get(c);
            node->incrementPrefix();
        }
        node->incrementEnd();
    }

    int countWordsEqualTo(string word)
    {
        Node *node = root;
        for (char c : word)
        {
            if (!node->containsKey(c))
                return 0;
            node = node->get(c);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string word)
    {
        Node *node = root;
        for (char c : word)
        {
            if (!node->containsKey(c))
                return 0;
            node = node->get(c);
        }
        return node->getPrefix();
    }

    void erase(string word)
    {
        Node *node = root;
        for (char c : word)
        {
            if (!node->containsKey(c))
                return;
            node = node->get(c);
            node->reducePrefix();
        }
        node->reduceEnd();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */