
#include<bits/stdc++.h>
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
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int v = it[0];  // v
                int wt = it[1]; // weight
                int u = i;      // u
                edges.push_back({wt, {u, v}});
            }
        }
        sort(edges.begin(), edges.end());

        int mst_sum = 0;

        DSU dsu;
        dsu.init(V);

        for (auto edge : edges)
        {
            int edgeWt = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if (dsu.find(u) != dsu.find(v))
            {
                mst_sum += edgeWt;
                dsu.unionByRank(u, v);
            }
        }
        return mst_sum;
    }
};


//O(ElogE+V+Eα(V))≈O(ElogE)