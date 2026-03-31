// Incremental Even-Weighted Cycle Queries
// You are given a positive integer n.

// There is an undirected graph with n nodes labeled from 0 to n - 1. Initially, the graph has no edges.

// You are also given a 2D integer array edges, where edges[i] = [ui, vi, wi] represents an edge between nodes ui and vi with weight wi. The weight wi is either 0 or 1.

// Process the edges in edges in the given order. For each edge, add it to the graph only if, after adding it, the sum of the weights of the edges in every cycle in the resulting graph is even.

// Return an integer denoting the number of edges that are successfully added to the graph.

//  

// Example 1:

// Input: n = 3, edges = [[0,1,1],[1,2,1],[0,2,1]]

// Output: 2

// Explanation:

// [0, 1, 1]: We add the edge between vertex 0 and vertex 1 with weight 1.
// [1, 2, 1]: We add the edge between vertex 1 and vertex 2 with weight 1.
// [0, 2, 1]: The edge between vertex 0 and vertex 2 (the dashed edge in the diagram) is not added because the cycle 0 - 1 - 2 - 0 has total edge weight 1 + 1 + 1 = 3, which is an odd number.
// Example 2:

// Input: n = 3, edges = [[0,1,1],[1,2,1],[0,2,0]]

// Output: 3

// Explanation:

// [0, 1, 1]: We add the edge between vertex 0 and vertex 1 with weight 1.
// [1, 2, 1]: We add the edge between vertex 1 and vertex 2 with weight 1.
// [0, 2, 0]: We add the edge between vertex 0 and vertex 2 with weight 0.
// Note that the cycle 0 - 1 - 2 - 0 has total edge weight 1 + 1 + 0 = 2, which is an even number.
//  

// Constraints:

// 3 <= n <= 5 * 104
// 1 <= edges.length <= 5 * 104
// edges[i] = [ui, vi, wi]
// 0 <= ui < vi < n
// All edges are distinct.
// wi = 0 or wi = 1©leetcode

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct DSU
    {
        vector<int> parent;
        vector<int> rank;
        vector<int> parity;
        void init(int n)
        {
            parent.resize(n + 1);
            rank.resize(n + 1, 1);
            parity.resize(n + 1, 0);
            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }
        pair<int, int> find(int node)
        {
            if (parent[node] == node)
                return {node, 0};
            auto p = find(parent[node]);
            parity[node] ^= p.second;
            parent[node] = p.first;
            return {parent[node], parity[node]};
        }
        void unionByRank(int a, int b, int weight)
        {
            auto [parentA, parityA] = find(a);
            auto [parentB, parityB] = find(b);
            if (parentA == parentB)
                return;
            if (rank[a] < rank[b])
            {
                swap(parentA, parentB);
                swap(parityA, parityB);
            }
            parent[parentB] = parentA;
            parity[parentB] = parityA ^ parityB ^ weight;
            if (rank[parentA] == rank[parentB])
                rank[parentA]++;
        }
    };
    int numberOfEdgesAdded(int n, vector<vector<int>> &edges)
    {
        int addedEdges = 0;
        DSU dsu;
        dsu.init(n);

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            auto [parentU, parityU] = dsu.find(u);
            auto [parentV, parityV] = dsu.find(v);

            if (parentU == parentV)
            {
                if ((parityU ^ parityV) != w)
                    continue;
            }
            dsu.unionByRank(u, v, w);
            addedEdges++;
        }
        return addedEdges;
    }
};
