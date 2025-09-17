// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

#include <bits/stdc++.h>
using namespace std;


//INTUITION - use DLL like a queue to maintain the order of usage of keys, and store the address of each node in a map for O(1) access.
class Node
{
public:
    int key, val;
    Node *next;
    Node *prev;

    Node()
    {
        key = val = -1;
        next = prev = NULL;
    }

    Node(int k, int value)
    {
        key = k;
        val = value;
        next = prev = NULL;
    }
};

class LRUCache
{
public:
    int cap;
    unordered_map<int, Node *> mp;
    Node *head;
    Node *tail;
    LRUCache(int capacity)
    {
        cap = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    void disconnect(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insertAfterHead(Node *node)
    {
        if (node->next && node->prev)
            disconnect(node);
        Node *afterHead = head->next;
        node->next = afterHead;
        node->prev = head;
        head->next = node;
        afterHead->prev = node;
    }
    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            insertAfterHead(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            node->val = value;
            insertAfterHead(node);
        }
        else
        {
            if (mp.size() == cap)
            {
                Node *lru = tail->prev;
                mp.erase(lru->key);
                disconnect(lru);
                delete lru;
            }
            Node *node = new Node(key, value);
            mp[key] = node;
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */