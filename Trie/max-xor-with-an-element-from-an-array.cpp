// 1707. Maximum XOR With an Element From Array

// You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

// The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

// Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

// Example 1:

// Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
// Output: [3,3,7]
// Explanation:
// 1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
// 2) 1 XOR 2 = 3.
// 3) 5 XOR 2 = 7.
// Example 2:

// Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
// Output: [15,-1,5]

// Constraints:

// 1 <= nums.length, queries.length <= 105
// queries[i].length == 2
// 0 <= nums[j], xi, mi <= 109

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
                node->put(bit, new Node());
            node = node->get(bit);
        }
    }
    int getMax(int n)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (node->containsKey(!bit))
            {
                maxNum |= (1 << i);
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
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        Trie trie;
        trie.init();
        vector<tuple<int, int, int>> offlineQueries;
        int qs = queries.size();
        vector<int> ans(qs, 0);
        for (int i = 0; i < qs; i++)
            offlineQueries.push_back({queries[i][1], queries[i][0], i});
        sort(nums.begin(), nums.end());
        sort(offlineQueries.begin(), offlineQueries.end());
        int i = 0;
        for (auto &[ai, xi, idx] : offlineQueries)
        {
            while (i < n && nums[i] <= ai)
            {
                trie.insert(nums[i]);
                i++;
            }

            if (i == 0)
                ans[idx] = -1;
            else
            {
                ans[idx] = trie.getMax(xi);
            }
        }
        return ans;
    }
};

// Time Complexity: O(32N + Q(logQ) + 32Q) where N is the size of the input array and Q is the number of queries. The time complexity includes inserting N numbers into the Trie, each taking O(32) operations due to the 32-bit integer representation, resulting in O(32N). Sorting the Q queries takes O(Q(logQ)) time. Processing each query involves traversing the 32-bit Trie, resulting in O(32Q).

// Space Complexity: O(32N + Q) where N is the size of the input array and Q is the number of queries. The space complexity accounts for storing N numbers in the Trie (32N) and the storage needed for the Q queries.