// Given the root of a binary search tree (BST) and an integer val.
// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        // your code goes here
        while (root != NULL && root->data != val)
        {
            root = (val < root->data) ? root->left : root->right;
        }
        return root;
    }
};

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;
    TreeNode *res = obj.searchBST(root, 2);
    cout << res->data << endl;
    return 0;
}