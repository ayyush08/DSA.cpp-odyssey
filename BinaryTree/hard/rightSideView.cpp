// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// Example 1:
// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]

// Explanation:
// Example 2:
// Input: root = [1,2,3,4,null,null,null,5]
// Output: [1,3,4,5]

// Explanation:
// Example 3:
// Input: root = [1,null,3
// Output: [1,3]

// Example 4:
// Input: root = []
// Output: []

// Constraints:
// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

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
    vector<int> rightSideView(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<int> ans;
        if (root == NULL)
            return ans;

        q.push(root);
        while (!q.empty())
        {
            int s = q.size();
            TreeNode *prev = NULL;
            for (int i = 0; i < s; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                prev = node;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(prev->val);
        }
        return ans;
    }
};

// Time Complexity: O(N) where N is number of nodes in the tree
// Space Complexity: O(N) for queue data structure

// Optimal Approach:
//  We can also do a modified pre-order traversal (root-right-left) and keep track of the level of each node. Whenever we reach a new level for the first time, we add that node's value to our result list. This way, we ensure that we always capture the rightmost node at each level.

class Solution
{
public:
    void func(TreeNode *root, int level, vector<int> &ans)
    {
        if (!root)
            return;
        if (ans.size() == level)
            ans.push_back(root->val);
        func(root->right, level + 1, ans);
        func(root->left, level + 1, ans);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        func(root, 0, ans);
        return ans;
    }
};

//LEFT SIDE VIEW
class Solution
{
public:
    void func(TreeNode *root, int level, vector<int> &ans)
    {
        if (!root)
            return;
        if (ans.size() == level)
            ans.push_back(root->val);
        func(root->left, level + 1, ans);
        func(root->right, level + 1, ans);
    }
    vector<int> leftSideView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        func(root, 0, ans);
        return ans;
    }
};