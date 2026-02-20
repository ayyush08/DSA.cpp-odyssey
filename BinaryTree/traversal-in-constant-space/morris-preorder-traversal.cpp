// Morris Preorder Traversal
// Given root of binary tree, return the preorder traversal of the binary tree.

// Morris preorder Traversal is a tree traversal algorithm aiming to achieve a space complexity of O(1) without recursion or an external data structure.

// Examples:
// Input : root = [1, 4, null, 4 2]

// Output : [1, 4, 4, 2]

// Explanation :

// Input : root = [1]

// Output : [1]

// Explanation : Only root node is present.

// Just a shuttle change from Morris Inorder Traversal, we ppush the node data when we first visit it, i.e., before going to left subtree.

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
    vector<int> preorder(TreeNode *root)
    {
        vector<int> preorder;
        TreeNode *curr = root;
        while (curr)
        {
            if (!curr->left)
            {
                preorder.push_back(curr->data); // Push when there is no left subtree
                curr = curr->right;
            }
            else
            {
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr)
                    prev = prev->right;
                if (!prev->right)
                {
                    prev->right = curr;
                    preorder.push_back(curr->data); // Push before going to left subtree
                    curr = curr->left;
                }
                else 
                {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};