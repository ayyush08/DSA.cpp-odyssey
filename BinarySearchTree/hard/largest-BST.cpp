// Largest BST in Binary Tree
// Given a root of Binary Tree, where the nodes have integer values. Return the size of the largest subtree of the binary tree which is also a BST.
// A binary search tree (BST) is a binary tree data structure which has the following properties.

// The left subtree of a node contains only nodes with data less than the node’s data.
// The right subtree of a node contains only nodes with data greater than the node’s data.
// Both the left and right subtrees must also be binary search trees.

// Examples:
// Input : root = [2, 1, 3]
// Output : 3
// Explanation :
// The given complete binary tree is a BST consisting of 3 nodes.
// Input : root = [10, null, 20, null, 30, null, 40, null, 50]
// Output : 5
// Explanation :
// If we consider the node 10 as root node then it forms the largest BST.

#include <bits/stdc++.h>
using namespace std;

// Brute force Approach - apply validate BST for each node and calculate size if valid BST
// O(n^2) time complexity in worst case(skewed tree) and O(h) space for recursion stack

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
    bool validate(TreeNode *root, long long least, long long most)
    {
        if (!root)
            return true;
        if (root->data <= least || root->data >= most)
            return false;

        return (validate(root->left, least, root->data) &&
                validate(root->right, root->data, most));
    }
    TreeNode *validateBST(TreeNode *root)
    {
        if (!root)
            return NULL;
        if (validate(root, LLONG_MIN, LLONG_MAX))
            return root;
        TreeNode *leftFound = validateBST(root->left);
        TreeNode *rightFound = validateBST(root->right);
        if (!leftFound)
            return rightFound;
        if (!rightFound)
            return leftFound;
        return (getBSTSize(leftFound) >= getBSTSize(rightFound)) ? leftFound : rightFound;
    }
    int getBSTSize(TreeNode *node)
    {
        if (!node)
            return 0;
        return 1 + getBSTSize(node->left) + getBSTSize(node->right);
    }
    int largestBST(TreeNode *root)
    {
        if (!root)
            return 0;
        TreeNode *validRoot = validateBST(root);
        return getBSTSize(validRoot);
    }
};

// Optimal Approach - Postorder Traversal with information propagation - O(n) time and O(h) recursion stack space

class NodeValue
{
public:
    int maxNode, minNode, size;
    NodeValue(int mn, int mx, int s)
    {
        maxNode = mx;
        minNode = mn;
        size = s;
    }
};
class Solution
{
public:
    NodeValue solve(TreeNode *root)
    {
        if (!root)
            return NodeValue(INT_MAX, INT_MIN, 0);
        auto left = solve(root->left);
        auto right = solve(root->right);

        if (left.maxNode < root->data && root->data < right.minNode)
        {
            return NodeValue(min(root->data, left.minNode),
                            max(root->data, right.maxNode),
                            left.size + right.size + 1);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.size, right.size));
    }
    int largestBST(TreeNode *root)
    {
        return solve(root).size;
    }
};