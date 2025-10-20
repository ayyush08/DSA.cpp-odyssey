// Minimum time taken to burn the BT from a given Node

// Given a target node data and a root of binary tree. If the target is set on fire, determine the shortest amount of time needed to burn the entire binary tree.
// It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.

// Examples:
// Input : root = [1, 2, 3, 4, null, 5, 6, null, 7]. target = 1
// Output : 3
// Explanation : The node with value 1 is set on fire.
// In 1st second it burns node 2 and node 3.
// In 2nd second it burns nodes 4, 5, 6.
// In 3rd second it burns node 7.

// Input : root = [1, 2, 3, null, 5, null, 4], target = 4
// Output : 4
// Explanation : The node with value 4 is set on fire.
// In 1st second it burns node 3.
// In 2nd second it burns node 1.
// In 3rd second it burns node 2.
// In 4th second it burns node 5.

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
    TreeNode *markParents(int start, TreeNode *root,
                          unordered_map<TreeNode *, TreeNode *> &parent)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *res = nullptr;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            if (node->data == start)
                res = node;
            q.pop();
            if (node->left)
            {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right)
            {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    int timeToBurnTree(TreeNode *root, int start)
    {
        unordered_map<TreeNode *, TreeNode *> parent;
        TreeNode *target = markParents(start, root, parent);
        unordered_map<TreeNode *, bool> visited;

        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        int time = 0;

        while (!q.empty())
        {
            int s = q.size();
            bool burned = false;
            for (int i = 0; i < s; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left && !visited[node->left])
                {
                    burned = true;
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right])
                {
                    burned = true;
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if (parent[node] && !visited[parent[node]])
                {
                    burned = true;
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
            if (burned)
                time++;
        }
        return time;
    }
};