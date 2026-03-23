// 3600. Maximize Spanning Tree Stability with Upgrades
// You are given an integer n, representing n nodes numbered from 0 to n - 1 and a list of edges, where edges[i] = [ui, vi, si, musti]:

// ui and vi indicates an undirected edge between nodes ui and vi.
// si is the strength of the edge.
// musti is an integer (0 or 1). If musti == 1, the edge must be included in the spanning tree. These edges cannot be upgraded.
// You are also given an integer k, the maximum number of upgrades you can perform. Each upgrade doubles the strength of an edge, and each eligible edge (with musti == 0) can be upgraded at most once.

// The stability of a spanning tree is defined as the minimum strength score among all edges included in it.

// Return the maximum possible stability of any valid spanning tree. If it is impossible to connect all nodes, return -1.

// Note: A spanning tree of a graph with n nodes is a subset of the edges that connects all nodes together (i.e. the graph is connected) without forming any cycles, and uses exactly n - 1 edges.

// Example 1:

// Input: n = 3, edges = [[0,1,2,1],[1,2,3,0]], k = 1

// Output: 2

// Explanation:

// Edge [0,1] with strength = 2 must be included in the spanning tree.
// Edge [1,2] is optional and can be upgraded from 3 to 6 using one upgrade.
// The resulting spanning tree includes these two edges with strengths 2 and 6.
// The minimum strength in the spanning tree is 2, which is the maximum possible stability.
// Example 2:

// Input: n = 3, edges = [[0,1,4,0],[1,2,3,0],[0,2,1,0]], k = 2

// Output: 6

// Explanation:

// Since all edges are optional and up to k = 2 upgrades are allowed.
// Upgrade edges [0,1] from 4 to 8 and [1,2] from 3 to 6.
// The resulting spanning tree includes these two edges with strengths 8 and 6.
// The minimum strength in the tree is 6, which is the maximum possible stability.
// Example 3:

// Input: n = 3, edges = [[0,1,1,1],[1,2,1,1],[2,0,1,1]], k = 0

// Output: -1

// Explanation:

// All edges are mandatory and form a cycle, which violates the spanning tree property of acyclicity. Thus, the answer is -1.

// Constraints:

// 2 <= n <= 105
// 1 <= edges.length <= 105
// edges[i] = [ui, vi, si, musti]
// 0 <= ui, vi < n
// ui != vi
// 1 <= si <= 105
// musti is either 0 or 1.
// 0 <= k <= n
// There are no duplicate edges.

#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent;
    vector<int> rank;
    void init(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    void unionByRank(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (rank[a] > rank[b])
            swap(a, b);
        parent[b] = a;

        if (rank[a] == rank[b])
            rank[a]++;
    }
};
class Solution
{
public:
    bool check(int n, int mid, vector<vector<int>> &edges, int k)
    {
        DSU dsu;
        dsu.init(n);
        vector<vector<int>> potentialUpgrades;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int s = edge[2];
            bool m = edge[3];

            if (m)
            {
                if (s < mid)
                    return false;

                dsu.unionByRank(u, v);
            }
            else
            {
                if (s >= mid)
                    dsu.unionByRank(u, v);
                else if (2 * s >= mid)
                    potentialUpgrades.push_back({u, v});
            }
        }

        for (auto &e : potentialUpgrades)
        {
            int u = e[0];
            int v = e[1];

            if (dsu.find(u) != dsu.find(v))
            {
                if (k <= 0)
                    return false;
                dsu.unionByRank(u, v);
                k--;
            }
        }
        int root = dsu.find(0);
        for (int node = 1; node < n; node++)
        {
            if (dsu.find(node) != root)
                return false;
        }
        return true;
    }
    int maxStability(int n, vector<vector<int>> &edges, int k)
    {

        DSU dsu;
        dsu.init(n);

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int s = edge[2];
            bool m = edge[3];

            if (m)
            {
                if (dsu.find(u) != dsu.find(v))
                    dsu.unionByRank(u, v);
                else
                    return -1; // cycle check
            }
        }

        int ans = -1;
        int low = 1, high = 2 * 1e5;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (check(n, mid, edges, k))
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};

//T.C : O(nlog(maxStability - minStability))
//S.C : O(n+e), n = number of nodes, e = number of edges