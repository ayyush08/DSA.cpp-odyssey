// 1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
// Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.

// Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.

// Note that you can return the indices of the edges in any order.

// Example 1:

// Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
// Output: [[0,1],[2,3,4,5]]
// Explanation: The figure above describes the graph.
// The following figure shows all the possible MSTs:

// Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
// The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.
// Example 2:

// Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
// Output: [[],[0,1,2,3]]
// Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.

// Constraints:

// 2 <= n <= 100
// 1 <= edges.length <= min(200, n * (n - 1) / 2)
// edges[i].length == 3
// 0 <= ai < bi < n
// 1 <= weighti <= 1000
// All pairs (ai, bi) are distinct.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct DSU
    {
        vector<int> parent;
        vector<int> rank;
        void init(int n)
        {
            parent.assign(n, 0);
            iota(parent.begin(), parent.end(), 0);
            rank.assign(n, 0);
        }
        int find(int v)
        {
            if (parent[v] == v)
                return v;
            return parent[v] = find(parent[v]);
        }
        void unionByRank(int a, int b)
        {
            a = find(a);
            b = find(b);
            if (a != b)
            {
                if (rank[a] < rank[b])
                    swap(a, b);
                parent[b] = a;
                if (rank[a] == rank[b])
                    rank[a]++;
            }
        }
    };
    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        return a[2] < b[2];
    }
    int kruskal(int V, vector<vector<int>> &edges, int skip, int mustTake)
    {

        DSU dsu;
        dsu.init(V);
        int mst_sum = 0;
        int edgesConnected = 0;

        if (mustTake != -1)
        {
            int u = edges[mustTake][0];
            int v = edges[mustTake][1];
            mst_sum += edges[mustTake][2];
            edgesConnected++;
            dsu.unionByRank(u, v);
        }
        for (int i = 0; i < edges.size(); i++)
        {
            if (skip == i)
                continue;
            int edgeWt = edges[i][2];
            int u = edges[i][0];
            int v = edges[i][1];

            if (dsu.find(u) != dsu.find(v))
            {
                mst_sum += edgeWt;
                edgesConnected++;
                dsu.unionByRank(u, v);
            }
        }
        if (edgesConnected != V - 1)
            return INT_MAX;
        return mst_sum;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        int E = edges.size();
        for (int i = 0; i < E; i++)
            edges[i].push_back(i);
        sort(edges.begin(), edges.end(), comp);
        int baseMST = kruskal(n, edges, -1, -1);

        vector<int> critical, pseudoCritical;

        for (int i = 0; i < E; i++)
        {
            if (kruskal(n, edges, i, -1) > baseMST)
            { // skipping to see if critical
                critical.push_back(edges[i][3]);
            }
            else if (kruskal(n, edges, -1, i) == baseMST) //including to see if pseudo-critical (including means mst weight should remain same always)
            {
                pseudoCritical.push_back(edges[i][3]);
            }
        }

        return {critical, pseudoCritical};
    }
};