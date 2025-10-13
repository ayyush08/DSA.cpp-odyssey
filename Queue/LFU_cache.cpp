// LFU Cache

// Design and implement a data structure for a Least Frequently Used (LFU) cache.

// Implement the LFUCache class with the following functions:

// LFUCache(int capacity): Initialize the object with the specified capacity.

// int get(int key): Retrieve the value of the key if it exists in the cache; otherwise, return -1.
// void put(int key, int value): Update the value of the key if it is present in the cache, or insert the key if it is not already present. If the cache has reached its capacity, invalidate and remove the least frequently used key before inserting a new item. In case of a tie (i.e., two or more keys with the same frequency), invalidate the least recently used key.

// A use counter is maintained for each key in the cache to determine the least frequently used key. The key with the smallest use counter is considered the least frequently used.
// When a key is first inserted into the cache, its use counter is set to 1 due to the put operation. The use counter for a key in the cache is incremented whenever a get or put operation is called on it.

// Ensure that the functions get and put run in O(1) average time complexity.

// Examples:
// Input:
// ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]

// Output:
// [null, null, null, 1, null, -1, 3, null, -1, 3, 4]

// Explanation:
// // cnt(x) = the use counter for key x
// // cache=[] will show the last used order for tiebreakers (leftmost element is most recent)
// LFUCache lfu = new LFUCache(2);
// lfu.put(1, 1);  // cache=[1,_], cnt(1)=1
// lfu.put(2, 2);  // cache=[2,1], cnt(2)=1, cnt(1)=1
// lfu.get(1);   // return 1
//          // cache=[1,2], cnt(2)=1, cnt(1)=2
// lfu.put(3, 3);  // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
//          // cache=[3,1], cnt(3)=1, cnt(1)=2
// lfu.get(2);   // return -1 (not found)
// lfu.get(3);   // return 3
//          // cache=[3,1], cnt(3)=2, cnt(1)=2
// lfu.put(4, 4);  // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
//          // cache=[4,3], cnt(4)=1, cnt(3)=2
// lfu.get(1);   // return -1 (not found)
// lfu.get(3);   // return 3
//          // cache=[3,4], cnt(4)=1, cnt(3)=3
// lfu.get(4);   // return 4
//          // cache=[4,3], cnt(4)=2, cnt(3)=3

// Input:

// ["LFUCache", "put", "put", "put", "put", "put", "get", "get", "get", "get", "get"]
// [[3], [5, 7], [4, 6], [3, 5], [2, 4], [1, 3], [1], [2], [3], [4], [5]]

// Output:
// [null, null, null, null, null, null, 3, 4, 5, -1, -1]

// Explanation:
// // cnt(x) = the use counter for key x
// // cache=[] will show the last used order for tiebreakers (leftmost element is most recent)
// LFUCache lfu = new LFUCache(3);
// lfu.put(5, 7);  // cache=[5], cnt(5)=1
// lfu.put(4, 6);  // cache=[4,5], cnt(4)=1, cnt(5)=1
// lfu.put(3, 5);  // cache=[3,4,5], cnt(3)=1, cnt(4)=1, cnt(5)=1
// lfu.put(2, 4);  // 5 is the LFU key because cnt(5)=1 is the smallest, invalidate 5.
//          // cache=[2,3,4], cnt(2)=1, cnt(3)=1, cnt(4)=1
// lfu.put(1, 3);  // 4 is the LFU key because cnt(4)=1 is the smallest, invalidate 4.
//          // cache=[1,2,3], cnt(1)=1, cnt(2)=1, cnt(3)=1
// lfu.get(1);   // return 3
//          // cache=[1,2,3], cnt(1)=2, cnt(2)=1, cnt(3)=1
// lfu.get(2);   // return 4
//          // cache=[2,1,3], cnt(1)=2, cnt(2)=2, cnt(3)=1
// lfu.get(3);   // return 5
//          // cache=[3,2,1], cnt(1)=2, cnt(2)=2, cnt(3)=2
// lfu.get(4);   // return -1 (not found)
// lfu.get(5);   // return -1 (not found)

#include <bits/stdc++.h>
using namespace std;
// Prerequisite - LRU Cache question

class Node
{
public:
    int key, val, cnt;
    Node *next;
    Node *prev;

    Node()
    {
        key = val = -1;
        cnt = 1;
        next = prev = NULL;
    }

    Node(int k, int value)
    {
        key = k;
        val = value;
        cnt = 1;
        next = prev = NULL;
    }
};

class List
{
public:
    int size;
    Node *head;
    Node *tail;
    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void disconnect(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
    void insertAfterHead(Node *node)
    {
        Node *afterHead = head->next;
        node->next = afterHead;
        node->prev = head;
        head->next = node;
        afterHead->prev = node;
        size++;
    }
};

class LFUCache
{
public:
    map<int, Node *> keyNodeMap;
    map<int, List *> freqListMap;
    int maxCacheSize;
    int minFreq;
    int currSize;
    LFUCache(int capacity)
    {
        maxCacheSize = capacity;
        minFreq = 0;
        currSize = 0;
    }
    void updateFreqListMap(Node *node)
    {
        keyNodeMap.erase(node->key);
        freqListMap[node->cnt]->disconnect(node);
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
            minFreq++;

        List *nextHigherFreqList = new List();

        if (freqListMap.count(node->cnt + 1))
        {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }
        node->cnt += 1;
        nextHigherFreqList->insertAfterHead(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNodeMap[node->key] = node;
    }

    int get(int key)
    {
        if (keyNodeMap.count(key))
        {
            Node *node = keyNodeMap[key];
            int val = node->val;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (maxCacheSize == 0)
            return;

        if (keyNodeMap.count(key))
        {
            Node *node = keyNodeMap[key];
            node->val = value;
            updateFreqListMap(node);
        }
        else
        {
            if (currSize == maxCacheSize)
            {
                List *list = freqListMap[minFreq];
                keyNodeMap.erase(list->tail->prev->key);
                freqListMap[minFreq]->disconnect(list->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List *listFreq = new List();
            if (freqListMap.count(minFreq))
                listFreq = freqListMap[minFreq];

            Node *node = new Node(key, value);
            listFreq->insertAfterHead(node);
            keyNodeMap[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};
