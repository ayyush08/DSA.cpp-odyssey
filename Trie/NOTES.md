# Trie

A Trie (pronounced "try") is a tree-like data structure that is used to store a dynamic set of strings, where the keys are usually strings. It is particularly useful for tasks such as autocomplete, spell checking, and IP routing.
Edges in a Trie represent characters, and each path from the root to a node represents a prefix of a string.
Mark the end of a string with a special marker (often `None` or a specific character).

This way space used is very efficient, especially when many strings share common prefixes.


```cpp

struct Node{
    int children[26];
    bool isEnd = false; // true if this node marks the end of a string
    void init(){
        fill(children, children + 26, -1); 
    }
};

struct Trie{
    vector<Node> trie;
    void init(){
        Node root;
        root.init();
        trie.push_back(root);
    }
    void insert(string &s){
        int r = 0; // root index
        for(char c: s){
            int idx = c - 'a'; 
            if(trie[r].children[idx] == -1){
                trie[r].children[idx] = trie.size();
                Node temp;
                temp.init();
                trie.push_back(temp);
            }
            r = trie[r].children[idx];
        }
        trie[r].isEnd = true; // mark the end of the string
    }
    bool search(string &s){
        int r = 0; // root index
        for(char c: s){
            int idx = c - 'a';
            if(trie[r].children[idx] == -1) return false; // character not found
            r = trie[r].children[idx];
        }
        return trie[r].isEnd; // return true if this node marks the end of a string
    }
};

```