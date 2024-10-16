// Given root of the binary tree, return its maximum depth.
// A binary tree's maximum depth is number of nodes along the longest path from from root node down to the farthest node.

// Example 1
// Input : root = [1, 2, 3, null, null, null , 6]
// Output : 3
// Explanation : The path from root node 1 to node with value 6 has maximum depth with 3 nodes along path.
// Example 2
// Input : root = [3, 9, 20, null, null, 15 , 7]
// Output : 3
// Explanation : The path from root node 3 to node with value 15 has maximum depth with 3 nodes along path.
// There exists other paths to reach the solution.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
// RECURSIVE SOLUTION
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        // your code goes here
        if (root == nullptr)
        {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + max(left, right);
    }
};

// ITERATIVE SOLUTION

class Solution2
{
public:
    int maxDepth(TreeNode *root)
    {
        // your code goes here
        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *front = q.front();
                q.pop();
                if (front->left != NULL)
                {
                    q.push(front->left);
                }
                if (front->right != NULL)
                {
                    q.push(front->right);
                }
            }
            depth++;
        }
        return depth;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution s;
    cout << "Solution 1: " << endl;
    cout << s.maxDepth(root) << endl;
    Solution2 s2;
    cout << "Solution 2: " << endl;
    cout << s2.maxDepth(root) << endl;
    return 0;
}