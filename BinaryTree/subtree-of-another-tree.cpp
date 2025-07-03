// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

// Example 1:

// Input: root = [3,4,5,1,2], subRoot = [4,1,2]
// Output: true
// Example 2:

// Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
// Output: false

// Constraints:

// The number of nodes in the root tree is in the range [1, 2000].
// The number of nodes in the subRoot tree is in the range [1, 1000].
// -104 <= root.val <= 104
// -104 <= subRoot.val <= 104

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool check(TreeNode *root, TreeNode *subRoot) //check whole structure and values of subRoot in root (if both are identical)
    {
        if (root == NULL && subRoot == NULL)
            return true;
        if (root == NULL || subRoot == NULL)
            return false;
        if (root->val != subRoot->val)
            return false;
        return check(root->left, subRoot->left) && check(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == NULL)
            return false;
        bool isOk = check(root, subRoot);
        if (isOk)
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot); // check left and right subtree of root(keep checking for descendants)
    }
};