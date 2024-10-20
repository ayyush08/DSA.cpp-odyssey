// Given the root node of a binary tree. Return true if the given binary tree is a binary search tree(BST) else false.
// A valid BST is defined as follows:
// The left subtree of a node contains only nodes with key strictly less than the node's key.
// The right subtree of a node contains only nodes with key strictly greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
// Example 1
// Input : root = [5, 3, 6, 2, 4, null, 7]
// Output : true
// Explanation : Below is image of the given tree.
// Example 2
// Input : root = [5, 3, 6, 4, 2, null, 7]
// Output : false

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
    bool checkBST(TreeNode *root, int least, int most)
    {
        if (root == nullptr)
            return true;
        if (root->data <= least || root->data >= most)
        {
            return false;
        }
        return (checkBST(root->left, least, root->data) &&
                checkBST(root->right, root->data, most));
    }
    bool isBST(TreeNode *root)
    {
        // your code goes here
        return checkBST(root, INT_MIN, INT_MAX);
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    Solution obj;
    cout << obj.isBST(root) << endl;
    return 0;
}