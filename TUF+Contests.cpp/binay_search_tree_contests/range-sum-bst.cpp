// Range Sum in BST

// Given a root of binary search tree and two integers low, high. Return the sum of all elements that lie in inclusive range of [low, high].

// Examples:
// Input : root = 5 2 7 1 3 null 10 , low = 3, high = 7

// Output : 15

// Explanation : The element 3, 5, 7 liens in range [3, 7]. The sum is 3 + 5 + 7 -> 15.

// Input : root = 15 12 17 11 13 null 10 , low = 3, high = 7

// Output : 0

// Explanation : No element lies in the range [3,7], so the sum is 0.

// Constraints:
// 1 <= Number of Nodes <= 104
// 1 <= nodes value <= 105

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
    bool isInRange(int n, int l, int r)
    {
        return (n >= l && n <= r);
    }
    void solve(TreeNode *root, int low, int high, int &sum)
    {
        if (!root)
            return;
        if (isInRange(root->data, low, high))
            sum += root->data;
        solve(root->left, low, high, sum);
        solve(root->right, low, high, sum);
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int sum = 0;
        solve(root, low, high, sum);
        return sum;
    }
};
