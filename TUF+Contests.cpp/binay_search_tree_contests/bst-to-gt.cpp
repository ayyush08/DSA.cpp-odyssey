// Great Tree

// Given a root of binary search tree. Convert the binary tree to Great tree such that every original key of BST is changed to original value plus sum of all keys greater than original key in BST.

// Examples:
// Input : root = 5 1 7 null null 6 10
// Output : 28 29 17 null null 23 10 null null null null
// Explanation :
// For key 5 -> The keys greater then 5 are 7, 6, 10. So new node value is 5 + 7 + 6 + 10 -> 28.
// For key 1 -> The keys greater then 1 are 5, 7, 6, 10. So new node value is 1 + 5 + 7 + 6 + 10 -> 29.
// For key 7 -> The keys greater then 7 is 10. So new node value is 7 + 10 -> 17.
// For key 6 -> The keys greater then 6 are 7, 10. So new node value is 7 + 6 + 10 -> 23.
// For key 10 -> There is no key greater than than 10. So new node value is 10.

// Input : root = 15 11 17 null null 16 20
// Output : 68 79 37 null null 53 20 null null null null
// Explanation :
// For key 15 -> The keys greater then 15 are 17, 16, 20. So new node value is 15 + 17 + 16 + 20 -> 68.
// For key 11 -> The keys greater then 11 are 15, 17, 16, 20. So new node value is 11 + 15 + 17 + 16 + 20 -> 79.
// For key 17 -> The keys greater then 17 is 20. So new node value is 17 + 20 -> 37.
// For key 16 -> The keys greater then 16 are 17, 20. So new node value is 17 + 16 + 20 -> 53.
// For key 20 -> There is no key greater than than 20. So new node value is 20.

// Constraints:
// 1 <= Number of Nodes <= 100
// 1 <= node value <= 104

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
    void solve(TreeNode *root, int &sum)
    {
        if (!root)
            return;
        solve(root->right, sum);
        sum += root->data;
        root->data = sum;
        solve(root->left, sum);
    }
    TreeNode *bstToGt(TreeNode *root)
    {
        int sum = 0;
        solve(root, sum);
        return root;
    }
};