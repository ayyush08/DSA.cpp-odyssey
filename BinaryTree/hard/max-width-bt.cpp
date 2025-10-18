// Maximum Width of BT

// Given the root of a binary tree, return the maximum width of the given tree.

// The maximum width of a tree is the maximum width among all levels. The width of a level is determined by measuring the distance between its end nodes, which are the leftmost and rightmost non-null nodes. The length calculation additionally takes into account the null nodes that would be present between the end nodes if a full binary tree were to stretch down to that level.

// Examples:
// Input : root = [1, 3, 2, 5, 3, null, 9]

// Output : 4

// Explanation :

// So if the below tree would be a full binary tree then there would be total 4 nodes in the last level.

// So the maximum width of the binary tree is between the nodes with value 5 and 9 is equal to 4.

// Input : root = [1, 3, 2, 5, null, null, 9, 6, null, 7]

// Output : 7

// Explanation :

// If the below tree would be a full binary tree then at last levels there would b 7 nodes including the node with value 6 and 7.

// So the maximum width of binary tree is 7.

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
    long long int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        int ans = 0;

        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (q.size())
        {
            int s = q.size();
            int pos = q.front().second;

            int l, r;

            for (int i = 0; i < s; i++)
            {
                TreeNode *node = q.front().first;
                int idx = q.front().second - pos;
                q.pop();
                if (i == 0)
                    l = idx;
                if (i == s - 1)
                    r = idx;
                if (node->left)
                    q.push({node->left, 2 * idx + 1});
                if (node->right)
                    q.push({node->right, 2 * idx + 2});
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};