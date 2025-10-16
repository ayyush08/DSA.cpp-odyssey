// Top View of BT

// Given the root of a binary tree, return the top view of the binary tree.

// Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. Return nodes from the leftmost node to the rightmost node. Also if 2 nodes are outside the shadow of the tree and are at the same position then consider the left ones only(i.e. leftmost).

// Examples:
// Input : root = [1, 2, 3, 4, 5, 6, 7]

// Output : [4, 2, 1, 3, 7]

// Explanation :

// Input : root = [10, 20, 30, 40, 60, 90, 100]

// Output : [40, 20, 10, 30, 100]

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
    vector<int> topView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        queue<pair<TreeNode *, int>> q; // node,level
        map<int, int> mp;               // line->node;
        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            TreeNode *node = it.first;
            int level = it.second;

            if (!mp.count(level))
            {
                mp[level] = node->data;
            }

            if (node->left)
                q.push({node->left, level - 1});
            if (node->right)
                q.push({node->right, level + 1});
        }
        for (auto &it : mp)
            ans.push_back(it.second);
        return ans;
    }
};

//Time Complexity: O(NlogN) where N is number of nodes in the tree , logN is for map insertion
//Space Complexity: O(N) for queue and map


//Why recursion will not work here?
//Ans: Because in recursion we go depth wise and we might miss some nodes which are at same vertical level but at upper level
//For Example:
//         1
//       /   \
//      2     3
//       \
//        4
//         \
//          5
//           \
//            6
//In the above case if we go depth wise then we will miss node 2 as it is at same vertical level as 4,5,6 but at upper level
//So we use BFS here to traverse level wise and keep track of vertical levels using a map<int,int>
//Also we only insert in map if the vertical level is not already present in the map as we need to consider leftmost node only in case of same vertical level