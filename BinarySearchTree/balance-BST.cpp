// //1382. Balance a Binary Search Tree
// Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

// A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

// Example 1:

// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
// Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
// Example 2:

// Input: root = [2,1,3]
// Output: [2,1,3]

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// 1 <= Node.val <= 105

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
    void inOrderTraversal(vector<int> &tree, TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inOrderTraversal(tree, root->left);
        tree.push_back(root->val);
        inOrderTraversal(tree, root->right);
    }
    TreeNode *makeBalancedTree(vector<int> &tree, int left, int right)
    {
        if (left > right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode *node = new TreeNode(tree[mid]);
        node->left = makeBalancedTree(tree, left, mid - 1);
        node->right = makeBalancedTree(tree, mid + 1, right);
        return node;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> tree;
        inOrderTraversal(tree, root);
        return makeBalancedTree(tree, 0, tree.size() - 1);
    }
};

//Idea is that for every tree/subtree the  most balanced node is around the middle of the inorder traversal of the tree/subtree.

//1. Get Inorder traversal of the BST and store it in a vector.
//2. Recursively construct the balanced BST using the middle element of the vector as the root, and repeat for left and right halves of the vector for left and right subtrees respectively.

//Time Complexity: O(n) for inorder traversal and O(n) for constructing the balanced BST, leading to an overall time complexity of O(n).
//Space Complexity: O(n) for storing the inorder traversal in a vector.
