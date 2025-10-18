// Print root to node path in BT

// Given the root of a binary tree. Return all the root-to-leaf paths in the binary tree.
// A leaf node of a binary tree is the node which does not have a left and right child.

// Examples:
// Input : root = [1, 2, 3, null, 5, null, 4]
// Output : [ [1, 2, 5] , [1, 3, 4] ]
// Explanation : There are only two paths from root to leaf.
// From root 1 to 5 , 1 -> 2 -> 5.
// From root 1 to 4 , 1 -> 3 -> 4.

// Input : root = [1, 2, 3, 4, 5]
// Output : [ [1, 2, 4] , [1, 2, 5] , [1, 3] ]

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
    void solve(TreeNode *root, vector<vector<int>> &ans, vector<int> &temp)
    {
        if (!root)
            return;

        temp.push_back(root->data);
        if (!root->left && !root->right)
            ans.push_back(temp);
        else
        {
            solve(root->left, ans, temp);
            solve(root->right, ans, temp);
        }
        temp.pop_back();
    }
    vector<vector<int>> allRootToLeaf(TreeNode *root)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root, ans, temp);
        return ans;
    }
};
