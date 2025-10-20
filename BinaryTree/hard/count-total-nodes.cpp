// Count total nodes in a complete BT
// Return the number of nodes in a binary tree given its root.

// Every level in a complete binary tree possibly with the exception of the final one is fully filled, and every node in the final level is as far to the left as it can be. At the last level h, it can have 1 to 2h nodes inclusive.

// Examples:
// Input : root = [1, 2, 3, 4, 5, 6]

// Output : 6

// Explanation :

// Input : root = [1, 2, 3, 4, 5, 6, 7, 8, 9]

// Output : 9

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach - use any traversal technique to count nodes (O(N) time complexity)

// Optimized Approach - Using the properties of complete binary tree 2^h - 1

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
    int maxHeight(TreeNode *root, int type)
    {
        if (!root)
            return 0;
        if (type)
        {
            return 1 + maxHeight(root->right, type);
        }
        else
            return 1 + maxHeight(root->left, type);
    }
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftHeight = maxHeight(root, 0);
        int rightHeight = maxHeight(root, 1);
        if (leftHeight == rightHeight)
        {
            return (1 << leftHeight) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// Time Complexity: O(log N * log N) where N is the number of nodes in the binary tree. Calculating leftHeight and rightHeight each takes O(log N) time. In the worst-case scenario, the recursive calls occur at most log N times, leading to a total time complexity of O(log N * log N).

// Space Complexity:O(log N) where N is the number of nodes in the binary tree. The maximum depth of the recursion stack is equal to the tree's height, which is log N for a complete binary tree.