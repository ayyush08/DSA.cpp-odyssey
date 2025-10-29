// Morris Inorder Traversal
// Given root of binary tree, return the Inorder traversal of the binary tree.

// Morris Inorder Traversal is a tree traversal algorithm aiming to achieve a space complexity of O(1) without recursion or an external data structure.

// Examples:
// Input : root = [1, 4, null, 4, 2]

// Output : [4, 4, 2, 1]

// Explanation :

// Input : root = [1, null, 2, 3]

// Output : [1, 3, 2]

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
    vector<int> getInorder(TreeNode *root)
    {
        vector<int> inorder;
        TreeNode *curr = root;
        while (curr)
        {
            if (!curr->left)
            {
                inorder.push_back(curr->data); // Push when there is no left subtree
                curr = curr->right;//threaded movement back to root
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
                    prev->right = NULL;
                    inorder.push_back(curr->data); // Push when returning from left subtree
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};

// Time Complexity: O(n) - amortized as the branches altogether form n traversals.
// Space Complexity: O(1) - no extra space used except for the output vector.

//NOTE: MORRIS ORDER TRAVERSAL uses THREADING OF BINARY TREES to achieve O(1) space complexity. A threaded binary tree is a binary tree variant where null pointers are replaced with pointers to in-order predecessor or successor nodes, facilitating traversal without recursion or a stack.