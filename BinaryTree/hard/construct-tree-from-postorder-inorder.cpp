// 106. Construct Binary Tree from Inorder and Postorder Traversal
// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

// Example 1:

// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: inorder = [-1], postorder = [-1]
// Output: [-1]

// Constraints:

// 1 <= inorder.length <= 3000
// postorder.length == inorder.length
// -3000 <= inorder[i], postorder[i] <= 3000
// inorder and postorder consist of unique values.
// Each value of postorder also appears in inorder.
// inorder is guaranteed to be the inorder traversal of the tree.
// postorder is guaranteed to be the postorder traversal of the tree

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
    TreeNode *build(int &i, int ioLeft, int ioRight, vector<int> &postorder, vector<int> &inorder)
    {
        if (ioLeft > ioRight)
            return NULL;
        int node = postorder[i];
        TreeNode *root = new TreeNode(node);
        i--;
        int inorderIndex = mp[node];
        root->right = build(i, inorderIndex + 1, ioRight, postorder, inorder);
        root->left = build(i, ioLeft, inorderIndex - 1, postorder, inorder);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        TreeNode *root = NULL;
        int n = postorder.size();
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;
        int start = n - 1;
        return build(start, 0, n - 1, postorder, inorder);
    }
};