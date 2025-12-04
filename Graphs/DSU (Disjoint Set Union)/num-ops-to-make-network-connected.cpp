// Number of operations to make network connected

// Given a graph with n vertices and m edges. The graph is represented by an array Edges, where Edge[i] = [a, b] indicates an edge between vertices a and b. One edge can be removed from anywhere and added between any two vertices in one operation. Find the minimum number of operations that will be required to make the graph connected. If it is not possible to make the graph connected, return -1.

// Examples:
// Input : n = 4, Edge =[ [0, 1], [ 0, 2], [1, 2]]

// Output: 1

// Explanation: We need a minimum of 1 operation to make the two components connected. We can remove the edge (1,2) and add the edge between node 2 and node 3 like the following:

// Input: n = 9, Edge = [[0,1],[0,2],[0,3],[1,2],[2,3],[4,5],[5,6],[7,8]]

// Output: 2

// Explanation: We need a minimum of 2 operations to make the two components connected. We can remove the edge (0,2) and add the edge between node 3 and node 4 and we can remove the edge (0,3) and add it between nodes 6 and 8 like the following:

// Constraints:
//   1 <= n <= 104
//   1 <= Edge.length <= 104
//   Edge[i].length == 2

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
    int solve(int n, vector<vector<int>> &Edge)
    {
        if (Edge.size() < n - 1)
            return -1;
        DSU dsu;
        dsu.init(n);
        int components = n;
        for (auto e : Edge)
        {
            int u = e[0];
            int v = e[1];
            if (dsu.find(u) != dsu.find(v)) //if u and v are in different components
            {
                dsu.unionByRank(u, v); //join them
                components--; //reduce number of components
            }
        }
        return components - 1; //remaining components - 1 will be the edges needed to connect them as we already checked if we have enough edges at start i.e Edge.size()<n-1
    }
};

//Time Complexity: O(E * α(V)), where E is the number of edges and α is the Inverse Ackermann function.
//Space Complexity: O(V) for parent and rank arrays.
