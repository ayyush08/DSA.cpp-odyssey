// Trie Implementation and Operations
// Hard

// Hints
// Company
// Implement the Trie class:

// Trie(): Initializes the trie object.

// void insert (String word): Inserts the string word into the trie.

// boolean search (String word): Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.

// boolean startsWith (String prefix): Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

// Example 1

// Input : ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]

// [ [] , "apple", "apple", "app", "app", "app", "app" ]

// Output : [null, null, true, false, true, null, true]

// Explanation :

// Trie trie = new Trie()

// trie.insert("apple")

// trie.search("apple")  // return True

// trie.search("app")   // return False

// trie.startsWith("app") // return True

// trie.insert("app")

// trie.search("app")   // return True

// Example 2

// Input : ["Trie" , "insert" , "insert" , "startsWith" , "search" ]

// [ [] , "takeu" , "banana" , "bana" , "takeu" ]

// Output : [null, null, null, true, true]

// Explanation :

// Trie trie = new Trie()

// trie.insert("takeu")

// trie.insert("banana")

// trie.startsWith("bana") // return True

// trie.search("takeu")   // return True

// Now your turn!

// Input : ["Trie" , "insert" , "insert" , "startsWith" , "search" ]

// [ [] , "caterpiller" , "cat" , "cat" , "cat" ]

// Output:

// Pick your answer

// [null, null, null, false, true]

// [null, null, null, false, false]

// [null, null, null, true, false]

// [null, null, null, true, true]
// Constraints

// 1 <= word.length , prefix.length <= 2000
// word and prefix consist only of lowercase English letters.
// At most 3*104 calls in total will be made to insert, search and startsWith.


#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    bool isEnd = false;
    bool containsKey(char c){
        return links[c-'a']!=NULL;
    }
    void put(char c,Node* node){
        links[c-'a']=node;
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
    //O(length of word)
    void insert(string word) {
           Node* node = root;
           for(int i=0;i<word.size();i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i],new Node());
                }
                node = node->get(word[i]); //moves to reference trie
           }
           node->setEnd();
    }
    //O(n)
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnding();
    }
    //O(n)
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])) return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */