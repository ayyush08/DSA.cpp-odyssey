// Connected Components in an Undirected Graph
// Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v.

// Your task is to return a list of all connected components. Each connected component should be represented as a list of its vertices, with all components returned in a collection where each component is listed separately.

// Note: You can return the components in any order, driver code will print the components in sorted order.

// Examples :

// Input: V = 5, edges[][] = [[0, 1], [2, 1], [3, 4]]
// Output: [[0, 1, 2], [3, 4]]

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
        void merge(int a, int b)
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
    vector<vector<int>> getComponents(int V, vector<vector<int>> &edges)
    {
        // code here
        DSU dsu;
        dsu.init(V);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            dsu.merge(u, v); // merge the sets containing u and v
        }

        vector<vector<int>> ans(V);
        for (int i = 0; i < V; i++)
        {
            ans[dsu.find(i)].push_back(i); // add vertex i to the component of its leader
        }
        vector<vector<int>> result;
        for (int i = 0; i < V; i++)
        {
            if (!ans[i].empty()) //remove empty components
            {
                result.push_back(ans[i]);
            }
        }
        return result;
    }
};
