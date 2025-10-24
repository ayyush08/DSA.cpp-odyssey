// Tree Greatness

// Given a binary tree consisting exactly of n vertices and rooted at vertex 1. Each vertex V of this tree has a value value[v] assigned to it.

// The greatness of a vertex i = (value[i] x 1) + (value[par[i]] x 2) + (value[par[par[i]] x 3) + (value[par[par[par[i]]] x 4) + ... until you reach the root i.e par[par[.....par[i]...]] is the root
// where par[i] represents the parent of vertex i.

// Given a value array where value[i] (1-based indexing) corresponds to the value assigned to the ith vertex. The greatness of an entire tree is defined as the maximum of greatness of any of its vertices. Find the maximum greatness of the tree.

// Examples:
// Input : value = [2, 3, -2, -1, -7, 5], root = 1 2 6 3 4 null null null null 5

// Output : 23

// Input : value = [1, 2, 3, 4, 5], root = 1 2 3 4 null 5
// Output : 14

// Explanation : Greatness for vertex 1 => 1*1 => 1.
// Greatness for vertex 2 => 2*1 + 1*2 => 4.
// Greatness for vertex 3 => 3*1 + 1*2 => 5.
// Greatness for vertex 4 => 4*1 + 2*2 + 1*3 => 11.
// Greatness for vertex 5 => 5*1 + 3*2 + 1*3 => 14.
// So the maximum greatness of a tree is obtained from vertex 5. I.e 14.

// Constraints:
// 1 <= n <= 105
// -105 <= value[i] <= 105

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
    unordered_map<TreeNode *, TreeNode *> parent;
    unordered_map<TreeNode *, int> dp;
    void markParent(TreeNode *root)
    {
        if (!root)
            return;
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
    int getGreatness(TreeNode *node, vector<int> &value)
    {
        int i = 1;
        int greatness = value[node->data] * i;
        i++;
        while (parent[node])
        {
            int v = parent[node]->data;
            greatness += (value[v] * i);
            i++;
            node = parent[node];
        }
        return greatness;
    }
    int treeGreatness(vector<int> &value, TreeNode *root)
    {
        if (!root)
            return 0;
        markParent(root);
        queue<TreeNode *> q;
        q.push(root);
        int ans = 0;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            int greatness = getGreatness(node, value);
            ans = max(ans, greatness);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        return ans;
    }
};