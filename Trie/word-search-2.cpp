// 212. Word Search II
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Given an m x n board of characters and a list of strings words, return all words on the board.

// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

// Example 1:


// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
// Output: ["eat","oath"]
// Example 2:


// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []
 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 12
// board[i][j] is a lowercase English letter.
// 1 <= words.length <= 3 * 104
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// All the strings of words are unique.
 

#include <bits/stdc++.h>
using namespace std;

//Approach: Trie + Backtracking (Store the words in Trie and then do backtracking on board to find the words in Trie,instead of marking each prefix in Trie here store the word itself after reaching the end of word in Trie making it optimal to get the word in O(1) time instead of O(k) time where k is the length of prefix)

//Time Complexity: O(m*n*4^k) where k is the length of longest word in words and Space Complexity: O(m*n+k) where k is the length of longest word in words
// Space Complexity : O(m*n+k) where k is the length of longest word in words and m*n is the space taken by board in worst case when all characters are same and we have to explore all the cells in board for each word in words and k is the space taken by Trie for storing the words in words

struct Node {
    Node* links[26];
    bool isEnding = false;
    string word = "";
    Node() {
        for (int i = 0; i < 26; i++)
            links[i] = NULL;
    }
    bool containsKey(char c) { return links[c - 'a'] != NULL; }
    void put(char c, Node* node) { links[c - 'a'] = node; }
    Node* get(char c) { return links[c - 'a']; }
    void setEnd() { isEnding = true; }
    bool isEnd() { return isEnding; }
};
struct Trie {
    Node* root;
    void init() { root = new Node(); }
    void insert(string word) {
        Node* node = root;
        for (char c : word) {
            if (!node->containsKey(c)) {
                node->put(c, new Node());
            }
            node = node->get(c);
        }
        node->word = word;
        node->setEnd();
    }
};
class Solution {
public:
    int m;
    int n;
    Trie trie;
    vector<string> ans;
    vector<int> dir = {-1, 1, 0, 0};
    vector<int> dic = {0, 0, 1, -1};
    void dfs(int i, int j, Node* node, vector<vector<char>>& board) {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;
        char c = board[i][j];
        if (c == '$')
            return;
        if (!node->containsKey(c))
            return;
        node = node->get(c);

        if (node->word.size()) {
            ans.push_back(node->word);
            node->word = "";
        }
        board[i][j] = '$';
        for (int k = 0; k < 4; k++) {
            int ni = dir[k] + i;
            int nj = dic[k] + j;
            dfs(ni, nj, node, board);
        }
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        trie.init();
        for (string word : words)
            trie.insert(word);
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j, trie.root, board);
            }
        }
        return ans;
    }
};