// Shortest path in undirected graph with unit weights
// Given a Undirected Graph of N vertices from 0 to N-1 and M edges and a 2D Integer array wdges, where there is a edge from vertex edge[i][0] to vertex edge[i][1] of unit weight.
// Find the shortest path from the source to all other nodes in this graph. In this problem statement, we have assumed the source vertex to be ‘0’. If a vertex is unreachable from the source node, then return -1 for that vertex.

// Examples:
// Input: n = 9, m = 10, edges = [[0,1],[0,3],[3,4],[4,5],[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]
// Output: 0 1 2 1 2 3 3 4 4
// Explanation:
// The above output array shows the shortest path to all
// the nodes from the source vertex (0), Dist[0] = 0, Dist[1] = 1 , Dist[2] = 2 , …. Dist[8] = 4.Where Dist[node] is the shortest path between src and the node. For a node, if the value of Dist[node]= -1, then we conclude that the node is unreachable from the src node.

// Input: n = 8, m = 10, edges =[[1,0],[2,1],[0,3],[3,7],[3,4],[7,4],[7,6],[4,5],[4,6],[6,5]]
// Output: 0 1 2 1 2 3 3 2
// Explanation:
// The above output list shows the shortest path to all the nodes from the source vertex (0), Dist[0] = 0, Dist[1] = 1, Dist[2] = 2,.....Dist[7] = 2.

// Approach

// Step 1: Create adjacency list of the graph.
// Step 2: Initialize the distance array with INT_MAX and distance of source vertex as 0.
// Step 3: Using distance array as a visited array, and update the distance array with the minimum distance.
// Step 4: Return the distance array.

// Code

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M)
    {
        vector<int> adj[N];
        for (int i = 0; i < M; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> dist(N, 1e9);

        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (dist[node] + 1 < dist[it])
                {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }
        return dist;
    }
};

int main()
{
    int n = 3, m = 1;
    vector<vector<int>> edges = {{1, 2}};
    Solution obj;
    vector<int> ans = obj.shortestPath(edges, n, m);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}

// Time Complexity: O(N + M) 
