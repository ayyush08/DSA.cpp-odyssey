// 897. Increasing Order Search Tree
// Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

// Example 1:

// Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
// Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
// Example 2:

// Input: root = [5,1,7]
// Output: [1,null,5,null,7]

// Constraints:

// The number of nodes in the given tree will be in the range [1, 100].
// 0 <= Node.val <= 1000

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
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *curr = root;
        TreeNode *newRoot = nullptr;
        TreeNode *tail = nullptr;

        while (curr)
        {
            if (!curr->left)
            {
                // visit
                if (!newRoot)
                    newRoot = curr;
                if (tail)
                {
                    tail->right = curr;
                    tail->left = nullptr;
                }
                tail = curr;
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
                    curr = curr->left;
                }
                else
                {
                    prev->right = nullptr;
                    // visit
                    if (!newRoot)
                        newRoot = curr;
                    if (tail)
                    {
                        tail->right = curr;
                        tail->left = nullptr;
                    }
                    tail = curr;
                    curr = curr->right;
                }
            }
        }

        if (tail)
            tail->left = nullptr;
        return newRoot;
    }
};
