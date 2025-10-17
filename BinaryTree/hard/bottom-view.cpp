// Bottom view of BT

// Given root of binary tree, return the bottom view of the binary tree.

// The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom. Return nodes from the leftmost node to the rightmost node. Also if 2 nodes are outside the shadow of the tree and are at the same position then consider the node that appears later in level traversal.

// Examples:
// Input : root = [20, 8, 22, 5, 3, null, 25, null, null, 10 ,14]
// Output : [5, 10, 3, 14, 25]
// Explanation : From left to right the path is as follows :
// First we encounter node with value 5.
// Then we have nodes 8 , 10 but from bottom only 10 will be visible.
// Next we have 20 , 3 but from bottom only 3 will be visible.
// Next we have 14 , 22 but from bottom only 14 will be visible.
// Then we encounter node with value 25.

// Input : root = [20, 8, 22, 5, 3, 4, 25, null, null, 10 ,14]
// Output : [5, 10, 4, 14, 25]
// Explanation : From left to right the path is as follows :
// First we encounter node with value 5.
// Then we have nodes 8 , 10 but from bottom only 10 will be visible.
// Next we have 20 , 3 and 4. The 3 and 4 will be nodes visible from bottom but as the node 4 appears later from left to right , so only node 4 will be considered visible.
// Next we have 14 , 22 but from bottom only 14 will be visible.
// Then we encounter node with value 25.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<int> bottomView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        queue<pair<TreeNode *, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            TreeNode *node = it.first;
            int level = it.second;

            mp[level] = node->data;
            if (node->left)
                q.push({node->left, level - 1});
            if (node->right)
                q.push({node->right, level + 1});
        }
        for (auto &it : mp)
            ans.push_back(it.second);
        return ans;
    }
};