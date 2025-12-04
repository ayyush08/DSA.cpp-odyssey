// Detect Cycle using DSU
// Given an undirected graph with no self loops with V (from 0 to V-1) nodes and E edges, the task is to check if there is any cycle in the undirected graph.

// Note: Solve the problem using disjoint set union (DSU).

#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent;
    vector<int> rank;
    void init(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
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
        if (a == b)
            return;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;

        if (rank[a] == rank[b])
            rank[a]++;
    }
};
class Solution
{
public:
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[])
    {

        DSU dsu;
        dsu.init(V);

        for (int u = 0; u < V; u++)
        {
            for (int v : adj[u])
            {
                if (dsu.find(u) == dsu.find(v) && u < v)
                    return 1;
                dsu.unionByRank(u, v);
            }
        }
        return 0;
    }
};

//Time Complexity: O(E * α(V)), where E is the number of edges and α is the Inverse Ackermann function.
//Space Complexity: O(V) for parent and rank arrays.