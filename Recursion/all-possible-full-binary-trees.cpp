// 894. All Possible Full Binary Trees
// Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

// Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

// A full binary tree is a binary tree where each node has exactly 0 or 2 children.

// Example 1:

// Input: n = 7
// Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
// Example 2:

// Input: n = 3
// Output: [[0,0,0]]

// Constraints:

// 1 <= n <= 20

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
    unordered_map<int, vector<TreeNode *>> dp;
    vector<TreeNode *> solve(int n)
    {
        if (n % 2 == 0)
            return {};
        if (n == 1)
            return {new TreeNode(0)};
        if (dp.count(n))
            return dp[n];

        vector<TreeNode *> trees;
        for (int i = 1; i < n; i++)
        {
            vector<TreeNode *> leftTrees = solve(i);
            vector<TreeNode *> rightTrees = solve(n - i - 1);
            for (auto left : leftTrees)
            {
                for (auto right : rightTrees)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }
        return dp[n] = trees;
    }
    vector<TreeNode *> allPossibleFBT(int n)
    {
        return solve(n);
    }
};