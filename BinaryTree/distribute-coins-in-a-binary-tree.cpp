// You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

// In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

// Return the minimum number of moves required to make every node have exactly one coin.

// Example 1:

// Input: root = [3,0,0]
// Output: 2
// Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.
// Example 2:

// Input: root = [0,3,0]
// Output: 3
// Explanation: From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from the root of the tree to the right child.

// Constraints:

// The number of nodes in the tree is n.
// 1 <= n <= 100
// 0 <= Node.val <= n
// The sum of all Node.val is n.

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
    int distribute(TreeNode *root, int &moves)
    {
        if (root == NULL)
            return 0;
        int leftDef = distribute(root->left, moves);
        int rightDef = distribute(root->right, moves);
        int newDef = root->val - 1 + leftDef + rightDef; // Deficit or surplus of coins at the current node
        moves += (abs(leftDef) + abs(rightDef)); //moves needed wil be the sum of absolute values of left and right deficits
        // If newDef is positive, it means we have surplus coins, if negative, it means we have a deficit.
        return newDef;
    }
    int distributeCoins(TreeNode *root)
    {
        int moves = 0;
        distribute(root, moves);
        return moves;
    }
};