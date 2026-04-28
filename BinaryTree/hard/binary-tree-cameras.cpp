// 968. Binary Tree Cameras

// You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

// Return the minimum number of cameras needed to monitor all nodes of the tree.

// Example 1:

// Input: root = [0,0,null,0,0]
// Output: 1
// Explanation: One camera is enough to monitor all nodes if placed as shown.
// Example 2:

// Input: root = [0,0,null,0,null,0,null,null,0]
// Output: 2
// Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// Node.val == 0

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
    int cameras = 0;
    // States:
    // 0 - hasCamera
    // 1 - don't have camera and is not covered
    // 2 - don't have camera but already covered (another camera is monitoring me)
    int solve(TreeNode *root)
    {
        if (!root)
            return 2;

        int left = solve(root->left);
        int right = solve(root->right);

        if (left == 1 || right == 1)
        { // store camera and tell parent that its child has one
            cameras++;
            return 0;
        }
        else if (left == 0 || right == 0)
            return 2; // tell parent that its child is covered

        return 1; // tell parent that child is free
    }
    int minCameraCover(TreeNode *root)
    {
        if (solve(root) == 1)
            cameras++; // uncovered root;
        return cameras;
    }
};