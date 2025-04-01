// Bellman ford algorithm

// Given a weighted and directed graph of V vertices and E edges. An edge is represented as [ai, bi, wi], meaning there is a directed edge from ai to bi having weight wi. Find the shortest distance of all the vertices from the source vertex S. If a vertex can't be reached from the S then mark the distance as 109.

// If the graph contains a negative cycle then return -1.

// Examples:
// Input : V = 6, Edges = [[3, 2, 6], [5, 3, 1], [0, 1, 5], [1, 5, -3], [1, 2, -2], [3, 4, -2], [2, 4, 3]], S = 0
// Output: 0 5 3 3 1 2
// Explanation:
// For node 1, shortest path is 0->1 (distance=5).
// For node 2, shortest path is 0->1->2 (distance=3)
// For node 3, shortest path is 0->1->5->3 (distance=3)
// For node 4, shortest path is 0->1->5->3->4 (distance=1)
// For node 5, shortest path is 0->1->5 (distance=2)

// Input : V = 2, Edges = [[0,1,9]], S = 0
// Output: 0 9
// Explanation: For node 1, the shortest path is 0->1 (distance=9)

// Bellman Ford Algorithm - It not only works when the graph contains negative edges, but also helps identify if the graph contains negative cycle (a cycle where sum of all weights is negative). The algorithm finds the minimum distance to reach any node by performing N-1 times Edge Relaxation (where N is the number of nodes in the graph). Though Bellman Ford Algorithm is more versatile, it is slower when compared to Dijkstra's Algorithm.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if (dist[u] != 1e9 && dist[u] + wt < dist[v])
                    dist[v] = dist[u] + wt;
            }
        }
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e9 && dist[u] + wt < dist[v])
                return {-1};
        }
        return dist;
    }
};


int main()
{
    int V = 6;
    vector<vector<int>> edges = {{3, 2, 6}, {5, 3, 1}, {0, 1, 5}, {1, 5, -3}, {1, 2, -2}, {3, 4, -2}, {2, 4, 3}};
    int S = 0;
    Solution obj;
    vector<int> result = obj.bellman_ford(V, edges, S);
    for (int i : result)
        cout << i << " ";
    return 0;
}
// Time Complexity: O(V*E) where V is the number of vertices and E is the number of edges in the graph. The algorithm runs in O(V) time for each edge relaxation, and we perform V-1 iterations for all edges.
// Space Complexity: O(V) for storing the distance of each vertex from the source vertex S.

// Why exactly (N-1) iterations?
// Longest Path in a Graph: 
//The longest possible path without cycles in a graph with N nodes consists of (N-1) edges. And during each iteration, the Bellman-Ford algorithm updates the shortest path information for one more edge in the path.
// Ensuring All Paths Are Considered:
// By repeating the relaxation process (N-1) times, the algorithm ensures that all vertices are updated based on paths that could extend up to (N-1) edges.


//How to check if the graph contains a negative cycle?

//It is already known to us that if a graph has negative cycle, the edge relaxation can be done for an infinite number of times. But the algorithm suggests that all the edges will be relaxed after exactly (N-1) iterations.
//Thus in order to check the existence of a negative cycle, an extra iteration can be performed to check if the edge relaxation is possible or not.
//If in the extra iteration, the edge relaxation was possible, a negative cycle is confirmed in the graph.