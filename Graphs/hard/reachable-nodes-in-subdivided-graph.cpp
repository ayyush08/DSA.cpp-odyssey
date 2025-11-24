// 882. Reachable Nodes In Subdivided Graph
// You are given an undirected graph (the "original graph") with n nodes labeled from 0 to n - 1. You decide to subdivide each edge in the graph into a chain of nodes, with the number of new nodes varying between each edge.

// The graph is given as a 2D array of edges where edges[i] = [ui, vi, cnti] indicates that there is an edge between nodes ui and vi in the original graph, and cnti is the total number of new nodes that you will subdivide the edge into. Note that cnti == 0 means you will not subdivide the edge.

// To subdivide the edge [ui, vi], replace it with (cnti + 1) new edges and cnti new nodes. The new nodes are x1, x2, ..., xcnti, and the new edges are [ui, x1], [x1, x2], [x2, x3], ..., [xcnti-1, xcnti], [xcnti, vi].

// In this new graph, you want to know how many nodes are reachable from the node 0, where a node is reachable if the distance is maxMoves or less.

// Given the original graph and maxMoves, return the number of nodes that are reachable from node 0 in the new graph.

// Example 1:

// Input: edges = [[0,1,10],[0,2,1],[1,2,2]], maxMoves = 6, n = 3
// Output: 13
// Explanation: The edge subdivisions are shown in the image above.
// The nodes that are reachable are highlighted in yellow.
// Example 2:

// Input: edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], maxMoves = 10, n = 4
// Output: 23
// Example 3:

// Input: edges = [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]], maxMoves = 17, n = 5
// Output: 1
// Explanation: Node 0 is disconnected from the rest of the graph, so only node 0 is reachable.

// Constraints:

// 0 <= edges.length <= min(n * (n - 1) / 2, 104)
// edges[i].length == 3
// 0 <= ui < vi < n
// There are no multiple edges in the graph.
// 0 <= cnti <= 104
// 0 <= maxMoves <= 109
// 1 <= n <= 3000


//Approach: Dijkstra's Algorithm, consider cnt+1 as the weight of the edge between u and v. find shortest distance from node 0 to all other nodes. if distance to a node is less than or equal to maxMoves then that node is reachable. Now for each edge calculate how many new nodes can be reached from both sides and add the minimum of total new nodes and reachable new nodes to the answer.

#include <bits/stdc++.h>
using namespace std;

#define P pair<int, int>
class Solution
{
public:
    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
    {
        if (edges.empty())
            return 1;
        vector<vector<P>> adj(n);
        for (auto e : edges)
        {
            adj[e[0]].push_back({e[1], e[2] + 1});
            adj[e[1]].push_back({e[0], e[2] + 1});
        }
        vector<int> dist(n, 1e9);
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        while (!pq.empty())
        {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            for (auto &it : adj[node])
            {
                int adjNode = it.first;
                int edgeWt = it.second;
                if (wt + edgeWt < dist[adjNode])
                {
                    dist[adjNode] = wt + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (dist[i] <= maxMoves)
                ans++;
        }

        for (auto &e : edges)
        {
            int u = e[0], v = e[1], splits = e[2];

            int fromU = max(0, maxMoves - dist[u]);
            int fromV = max(0, maxMoves - dist[v]);

            ans += min(splits, fromU + fromV);
        }
        return ans;
    }
};

//Time Complexity: O(n+E log n) where E is the number of edges and n is the number of nodes.
//Space Complexity: O(n + E) for the adjacency list and O(n) for the distance array and priority queue.