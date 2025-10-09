// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

// Example 1:

// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]

// Constraints:

// 1 <= preorder.length <= 3000
// inorder.length == preorder.length
// -3000 <= preorder[i], inorder[i] <= 3000
// preorder and inorder consist of unique values.
// Each value of inorder also appears in preorder.
// preorder is guaranteed to be the preorder traversal of the tree.
// inorder is guaranteed to be the inorder traversal of the tree.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    unordered_map<int, int> mp;
    TreeNode *build(int &i, int ioLeft, int ioRight, vector<int> &preorder, vector<int> &inorder)
    {
        if (ioLeft > ioRight)
            return NULL;
        int node = preorder[i];
        TreeNode *root = new TreeNode(node);
        i++;
        int inorderIndex = mp[node];
        root->left = build(i, ioLeft, inorderIndex - 1, preorder, inorder);
        root->right = build(i, inorderIndex + 1, ioRight, preorder, inorder);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *root = NULL;
        int n = preorder.size();
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;
        int start = 0;
        return build(start, 0, n - 1, preorder, inorder);
    }
};