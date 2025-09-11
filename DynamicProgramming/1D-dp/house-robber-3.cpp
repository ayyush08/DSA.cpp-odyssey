// 337. House Robber III
// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

// Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

// Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

// Example 1:

// Input: root = [3,2,3,null,3,null,1]
// Output: 7
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// Example 2:

// Input: root = [3,4,5,1,3,null,1]
// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// 0 <= Node.val <= 104

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
    pair<int, int> func(TreeNode *root)
    {
        if (!root)
            return {0, 0};

        pair<int, int> left = func(root->left);
        pair<int, int> right = func(root->right);

        int rob = root->val + left.second + right.second;
        int dontRob = max(left.first, left.second) + max(right.first, right.second);

        return {rob, dontRob};
    }
    int rob(TreeNode *root)
    {
        auto res = func(root);
        return max(res.first, res.second);
    }
};

//This is also a DP approach but since we do not know the size of the tree it's a on the fly approach using pairs to store the values. So every node traversal is working as a DP state.

//Time complexity is O(n) and space complexity is O(h) where h is the height of the tree due to recursive stack space.