// Boundary Traversal

// Given a root of Binary Tree, perform the boundary traversal of the tree.
// The boundary traversal is the process of visiting the boundary nodes of the binary tree in the anticlockwise direction, starting from the root.
// The boundary of a binary tree is the concatenation of the root, the left boundary, the leaves ordered from left-to-right, and the reverse order of the right boundary.

// The left boundary is the set of nodes defined by the following:
// The root node's left child is in the left boundary. If the root does not have a left child, then the left boundary is empty.
// If a node in the left boundary and has a left child, then the left child is in the left boundary.
// If a node is in the left boundary, has no left child, but has a right child, then the right child is in the left boundary.
// The leftmost leaf is not in the left boundary.
// The right boundary is similar to the left boundary, except it is the right side of the root's right subtree. Again, the leaf is not part of the right boundary, and the right boundary is empty if the root does not have a right child.

// Examples:
// Input : root = [1, 2, 3, 4, 5, 6, 7, null, null, 8, 9]
// Output : [1, 2, 4, 8, 9, 6, 7, 3]

// Input : root = [1, 2, null, 4, 9, 6, 5, 3, null, null, null, null, null, 7, 8]
// Output : [1, 2, 4, 6, 5, 7, 8]

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
    bool isLeaf(TreeNode *root)
    {
        return (!root->left && !root->right);
    }
    void leftB(TreeNode *root, vector<int> &ans)
    {
        if (isLeaf(root))
            return;
        TreeNode *temp = root->left;
        while (temp)
        {
            if (!isLeaf(temp))
                ans.push_back(temp->data);
            if (temp->left)
                temp = temp->left;
            else
                temp = temp->right;
        }
    }
    void leafNodes(TreeNode *root, vector<int> &ans)
    {
        if (isLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }
        if (root->left)
            leafNodes(root->left, ans);
        if (root->right)
            leafNodes(root->right, ans);
    }
    void rightB(TreeNode *root, vector<int> &ans)
    {
        stack<int> st;
        TreeNode *temp = root->right;
        while (temp)
        {
            if (!isLeaf(temp))
                st.push(temp->data);
            if (temp->right)
                temp = temp->right;
            else
                temp = temp->left;
        }
        while (st.size())
        {
            ans.push_back(st.top());
            st.pop();
        }
    }
    vector<int> boundary(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        if (!isLeaf(root))
            ans.push_back(root->data);
        leftB(root, ans);
        leafNodes(root, ans);
        rightB(root, ans);
        return ans;
    }
};