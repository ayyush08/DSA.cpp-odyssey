// Asked in Amazon Interview

// 310. Minimum Height Trees

// A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

// Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

// Return a list of all MHTs' root labels. You can return the answer in any order.

// The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

// Example 1:

// Input: n = 4, edges = [[1,0],[1,2],[1,3]]
// Output: [1]
// Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
// Example 2:

// Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
// Output: [3,4]

// Constraints:

// 1 <= n <= 2 * 104
// edges.length == n - 1
// 0 <= ai, bi < n
// ai != bi
// All the pairs (ai, bi) are distinct.
// The given input is guaranteed to be a tree and there will be no repeated edges.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<int> inDegree(n, 0);
        vector<vector<int>> adjList(n);
        if (n == 1)
            return {0};
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            inDegree[u]++;
            inDegree[v]++;
        }
        vector<int> mhts;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 1)
                q.push(i);
        }

        int totalNodes = n;
        //Iterative peeling of leaf nodes until we are left with 2 or less nodes in the graph because the MHTs can have at most 2 roots (in case of even length longest path in the tree)
        while (totalNodes > 2)
        {
            int s = q.size();
            totalNodes -= s;
            for (int i = 0; i < s; i++)
            {
                int node = q.front();
                q.pop();
                for (auto ngbr : adjList[node])
                {
                    inDegree[ngbr]--;
                    if (inDegree[ngbr] == 1)
                        q.push(ngbr);
                }
            }
        }

        while (!q.empty())
        {
            mhts.push_back(q.front());
            q.pop();
        }

        return mhts;
    }
};

// Time Complexity: O(n) where n is the number of nodes in the tree. We are visiting each node at most once when we are peeling off the leaf nodes.
// Space Complexity: O(n) for the adjacency list and the inDegree array. The queue can also hold at most n nodes in the worst case (when all nodes are leaf nodes).