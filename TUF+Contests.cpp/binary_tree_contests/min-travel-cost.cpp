// Minimum Travel Cost

// Mocha and his friend wants to go on a vacation trip but they live in different cities. There are total of n cities given in form a binary tree rooted at vertex 1. To meet each other Mocha and his friend always stat travelling from their city towards the root.

// For travelling each city they need to fill their fuel tank and you are given the cost required to fill the tank at each vertex. You need to fill the tank each city you visit. Mocha and his friend travel until they meet for the first time at same vertex/city.

// You will be given binary tree rooted at vertex 1 and an array 'cost' (1-based indexing) which contains the cost of fuel required to fill at each vertex i.e. cost to refill the fuel at ith vertex is cost[i] (1 <= i <=n).

// You will be asked q queries which contains the start cities of Mocha(x) and his friend(y).

// All cities have a unique rule that once they sell their fuel then next time they need to reduce the cost to half of current cost (floor value should be considered).

// You need to find the money Mocha and his friend together spent on all of their trips in each city i.e. Money spent on each vertex after all the queries.

// Examples:
// Input : cost = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], root = 1 2 3 4 5 6 7 8 null null null null null 9 10 , queries = [ [4, 7], [8, 10], [4, 5], [6, 7], [2, 3] ]
// Output : [1, 3, 4, 7, 5, 6, 11, 8, 0, 10]
// Explanation :
// 1st query -> traverse from vertex 4 to 7 and they meet at common vertex 1 for first time. The path is 4 -> 2-> 1 -> 3 -> 7.
// 2nd query -> traverse from vertex 8 to 10 and they meet at common vertex 1 for first time. The path is 8 -> 4 -> 2 -> 1 -> 3 -> 7 -> 10.
// 3rd query -> traverse from vertex 4 to 5 and they meet at common vertex 2 for first time. The path is 4 -> 2-> 5.
// 4th query -> traverse from vertex 6 to 7 and they meet at common vertex 3 for first time. The path is 7-> 3-> 6.
// 5th query -> traverse from vertex 2 to 3 and they meet at common vertex 1 for first time. The path is 2-> 1 -> 3.
// So vertex 7 is traversed in query 1, 2, 4. So initial cost is 7 for tank refill. So after traversal in 1st query the cost is halved i.e. becomes 7/2 -> 3.5 -> 3.

// After traversal in 2nd query cost is halved again 3/2 -> 1.5 -> 1.
// After traversal in 4th query cost is halved again 1/2 -> 0.5 -> 0.
// So total money spent by Mocha and his friend on 7th vertex/city after all the queries is 7 + 3 + 1 => 11.

// Input : cost = [3, 5, 4, 6], root = 1 3 2 4 , queries = [ [2, 3] ]
// Output : [3, 5, 4, 0]
// Explanation :
// 1st query traversal path => 2 -> 1 -> 3
// Cost at vertex1 -> 3.
// Cost at vertex 2 -> 5.
// Cost at vertex 3 -> 4.
// Cost at vertex 4 -> 0.

// Constraints:
// 1 <= n, q <= 1000
// 1 <= cost[i] <= 104
// 1 <= queries[i][0], queries[i][1] <= n

// Passed only basic cases. Needs optimization for larger test cases. or something might still be wrong.

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
    unordered_map<int, TreeNode *> nodeMap;

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
            nodeMap[node->data] = node;
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

    vector<int> travel_cost(vector<int> &cost, vector<vector<int>> &queries, TreeNode *root)
    {
        if (!root)
            return {};
        int n = cost.size();
        vector<int> ans(n, 0);
        vector<int> currCost = cost; 
        markParent(root);
        unordered_map<int, int> dataToIndex;
        for (int i = 0; i < cost.size(); i++)
            dataToIndex[i] = i;
        for (auto &q : queries)
        {
            TreeNode *left = nodeMap[q[0]];
            TreeNode *right = nodeMap[q[1]];
            unordered_set<TreeNode *> visited;

            TreeNode *l = left;
            while (l)
            {
                int idx = dataToIndex[l->data];
                ans[idx] += currCost[idx];
                currCost[idx] /= 2; 
                visited.insert(l);
                if (parent.count(l))
                    l = parent[l];
                else
                    break;
            }

            TreeNode *r = right;
            while (r && !visited.count(r))
            {
                int idx = dataToIndex[r->data];
                ans[idx] += currCost[idx];
                currCost[idx] /= 2;
                if (parent.count(r))
                    r = parent[r];
                else
                    break;
            }
        }

        return ans;
    }
};
