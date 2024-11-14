// Given an undirected connected graph with V vertices numbered from 0 to V-1, the task is to implement both Depth First Search (DFS) and Breadth First Search (BFS) traversals starting from the 0th vertex. The graph is represented using an adjacency list where adj[i] contains a list of vertices connected to vertex i. Visit nodes in the order they appear in the adjacency list.

// Example 1
// Input: V = 5, adj = [[2, 3, 1], [0], [0, 4], [0], [2]]
// Output:[0, 2, 4, 3, 1], [0, 2, 3, 1, 4]
// Explanation:
// DFS: Start from vertex 0. Visit vertex 2, then vertex 4, backtrack to vertex 0, then visit vertex 3, and finally vertex 1. The traversal is 0 → 2 → 4 → 3 → 1.
// BFS: Start from vertex 0. Visit vertices 2, 3, and 1 (in the order they appear in the adjacency list). Then, visit vertex 4 from vertex 2. The traversal is 0 → 2 → 3 → 1 → 4.

// Example 2
// Input: V = 4, adj = [[1, 3], [2, 0], [1], [0]]
// Output: [0, 1, 2, 3], [0, 1, 3, 2]
// Explanation:
// DFS: Start from vertex 0. Visit vertex 1, then vertex 2, backtrack to vertex 0, then visit vertex 3. The traversal is 0 → 1 → 2 → 3.
// BFS: Start from vertex 0. Visit vertices 1 and 3, then visit vertex 2 from vertex 1. The traversal is 0 → 1 → 3 → 2.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfss(int start, vector<int> adj[], int visited[], vector<int> &dfs)
    {
        visited[start] = 1;
        dfs.push_back(start);
        for (auto it : adj[start])
        {
            if (!visited[it])
                dfss(it, adj, visited, dfs);
        }
    }

public:
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        int start = 0;
        vector<int> dfs;
        dfss(start, adj, visited, dfs);
        return dfs;
    }

    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        visited[0] = 1;
        vector<int> bfs;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            visited[node] = 1;
            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};


int main()
{
    Solution s;
    int V = 5;
    vector<int> adj[V];
    adj[0] = {2, 3, 1};
    adj[1] = {0};
    adj[2] = {0, 4};
    adj[3] = {0};
    adj[4] = {2};
    vector<int> dfs = s.dfsOfGraph(V, adj);
    vector<int> bfs = s.bfsOfGraph(V, adj);
    cout << "DFS: ";
    for (int i = 0; i < dfs.size(); i++)
    {
        cout << dfs[i] << " ";
    }
    cout << endl;
    cout << "BFS: ";
    for (int i = 0; i < bfs.size(); i++)
    {
        cout << bfs[i] << " ";
    }
    return 0;
}