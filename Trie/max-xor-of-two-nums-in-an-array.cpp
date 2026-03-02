// 421. Maximum XOR of Two Numbers in an Array
// Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

// Example 1:

// Input: nums = [3,10,5,25,2,8]
// Output: 28
// Explanation: The maximum result is 5 XOR 25 = 28.
// Example 2:

// Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
// Output: 127

// Constraints:

// 1 <= nums.length <= 2 * 105
// 0 <= nums[i] <= 231 - 1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[2];
    bool isEnd = false;
    void setEnd()
    {
        isEnd = true;
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
    Node *get(int bit)
    {
        return links[bit];
    }
    bool containsKey(int bit)
    {
        return links[bit] != NULL;
    }
};
struct Trie
{
    Node *root;
    void init()
    {
        root = new Node();
    }
    void insert(int n)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
        node->setEnd();
    }
    int getMaxComplement(int n)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (node->containsKey(!bit))
            {
                maxNum = (1 << i) | maxNum;
                node = node->get(!bit);
            }
            else
                node = node->get(bit);
        }
        return maxNum;
    }
};
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        Trie trie;
        trie.init();
        for (int num : nums)
        {
            trie.insert(num);
        }
        int ans = 0;
        for (int num : nums)
        {
            ans = max(ans, trie.getMaxComplement(num));
        }
        return ans;
    }
};

//Time Complexity: O(N*32) for inserting N numbers and O(N*32) for finding the maximum complement, resulting in O(N) overall since 32 is a constant.
//Space Complexity: O(N*32) for the trie, which is O(N) since 32 is a constant.

