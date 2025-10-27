// 95. Unique Binary Search Trees II
// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

// Example 1:

// Input: n = 3
// Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
// Example 2:

// Input: n = 1
// Output: [[1]]

// Constraints:

// 1 <= n <= 8

// go through 1 to n and make each one root and recursively call for left and right subtree

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    vector<TreeNode *> build(int left, int right)
    {
        vector<TreeNode *> res;
        if (left > right)
        {
            res.push_back(NULL);
            return res;
        }

        for (int i = left; i <= right; i++)
        {
            vector<TreeNode *> leftSt = build(left, i - 1);
            vector<TreeNode *> rightSt = build(i + 1, right);

            for (TreeNode *lt : leftSt)
            {
                for (TreeNode *rt : rightSt)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = lt;
                    root->right = rt;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode *> generateTrees(int n) { return build(1, n); }
};