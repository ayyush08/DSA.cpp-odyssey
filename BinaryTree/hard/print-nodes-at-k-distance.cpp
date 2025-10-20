// Print all nodes at a distance of K in BT

// Given the root of a binary tree, the value of a target node target, and an integer k. Return an array of the values of all nodes that have a distance k from the target node.
// The answer can be returned in any order (N represents null).

// Note: Although input shows target as a value, internally it refers to the TreeNode with that value.

// Examples:
// Input : root = [3, 5, 1, 6, 2, 0, 8, N, N, 7, 4] , target = 5, k = 2
// Output : [1, 4, 7]
// Explanation : The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

// Input : root = [3, 5, 1, 6, 2, 0, 8, N, N, 7, 4] , target = 5, k = 3
// Output : [0, 8]
// Explanation : The nodes that are a distance 3 from the target node (with value 5) have values 0, 8.

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
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
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
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent;
        markParents(root, parent);
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        int dist = 0;
        while (!q.empty())
        {
            if (dist == k)
                break;
            dist++;
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if (parent[node] && !visited[parent[node]])
                {
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
        }

        vector<int> ans;
        while (q.size())
        {
            ans.push_back(q.front()->data);
            q.pop();
        }
        return ans;
    }
};