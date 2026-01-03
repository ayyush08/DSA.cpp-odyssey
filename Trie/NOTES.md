# Trie

A **Trie** (pronounced "try") is a tree structure used to store strings efficiently.

**Key Points:**
- Each node has 26 pointers (for 'a' to 'z')
- Each path from root to a node represents a prefix
- A boolean flag marks if a node is the end of a complete word
- Great for autocomplete, spell check, and prefix searches

**Time Complexity:**
- Insert: O(length of word)
- Search: O(length of word)
- Starts With: O(length of prefix)

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    bool isEnd = false;
    
    bool containsKey(char c){
        return links[c-'a'] != NULL;
    }
    void put(char c, Node* node){
        links[c-'a'] = node;
    }
    Node* get(char c){
        return links[c-'a'];
    }
    void setEnd(){
        isEnd = true;
    }
    bool isEnding(){
        return isEnd;
    }
};

class Trie{
private:
    Node* root;
    
public:
    Trie(){
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]); // move to next node
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnding();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++){
            if(!node->containsKey(prefix[i])) return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};
```
