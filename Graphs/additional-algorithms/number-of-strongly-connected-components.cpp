// Kosaraju's algorithm
// Hard

// Hints
// Company
// You are given a directed graph with V vertices, numbered from 0 to V − 1, and its adjacency list Adj, where Adj[i] contains all vertices j such that there is a directed edge from vertex i to vertex j.

// Your task is to find the number of strongly connected components (SCCs) in the graph.

// Example 1

// Input: V=5, Adj=[[2,3],[0],[1],[4],[]]

// Output: 3

// Example 2

// Input: V=8, Adj=[[1],[2],[0,3],[4],[5,7],[6],[4,7],[]]

// Output: 4

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    stack<int> st;
    void dfs(int node, vector<bool> &visited, vector<int> adj[], bool isSorting)
    {
        visited[node] = true;
        for (auto &it : adj[node])
        {
            if (!visited[it])
                dfs(it, visited, adj, isSorting);
        }

        if (isSorting)
            st.push(node);
    }
    int kosaraju(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);

        // Step 1: Topological Sort or DFS finishing order
        for (int node = 0; node < V; node++)
        {
            if (!visited[node])
                dfs(node, visited, adj, true);
        }

        int sccs = 0;

        vector<int> reverseAdj[V];
        // Step 2: Transpose the graph

        for (int node = 0; node < V; node++)
        {
            visited[node] = false;
            for (auto it : adj[node])
            {
                reverseAdj[it].push_back(node);
            }
        }

        // Step 3: DFS according to finishing order on transposed graph 
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (!visited[node])
            {
                sccs++;
                dfs(node, visited, reverseAdj, false);
            }
        }

        return sccs;
    }
};
