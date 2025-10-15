// Check for symmetrical BTs

// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

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
    bool check(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;
        if (left->data != right->data)
            return false;
        return check(left->left, right->right) && check(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return check(root->left, root->right);
    }
};