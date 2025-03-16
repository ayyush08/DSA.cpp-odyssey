// Print Shortest Path
// Given a weighted undirected graph having n vertices numbered from 1 to n and m edges describing there are edges, where edges[i]=[ai,bi,wi], representing an edge from vertex ai to bi with weight wi.
// Find the shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1. If there exists a path, then return a list whose first element is the weight of the path and the remaining elements represent the shortest path from vertex 1 to vertex n.

// Examples:
// Input: n = 5, m= 6, edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]
// Output: 5 1 4 3 5
// Explanation: The source vertex is 1. Hence, the shortest distance path of node 5 from the source will be 1->4->3->5 as this is the path with a minimum sum of edge weights from source to destination.

// Input: n = 4, m = 4, edges = [[1,2,2], [2,3,4], [1,4,1],[4,3,3]]
// Output:1 1 4
// Explanation: The source vertex is 1. Hence, the shortest distance path of node 4 from the source will be 1->4 as this is the path with the minimum sum of edge weights from source to destination.

// Approach - Dijkstra's Algorithm modified to print the shortest path, we take in account the parent nodes of each node to print the path.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {

        vector<pair<int, int>> adj[n + 1];

        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> parent(n + 1);
        vector<int> dist(n + 1, 1e9);
        dist[1] = 0;
        pq.push({0, 1});
        for(int i=1;i<=n;i++) parent[i]=i;
        while (!pq.empty())
        {
            int node = pq.top().second;
            int weight = pq.top().first;

            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edgeWt = it.second;

                if (weight + edgeWt < dist[adjNode])
                {
                    dist[adjNode] = weight + edgeWt;
                    pq.push({dist[adjNode], adjNode});

                    parent[adjNode] = node;
                }
            }
        }

        if (dist[n] == 1e9)
            return {-1};

        int destination = n;
        vector<int> path;

        while (parent[destination] != destination)
        {
            path.push_back(destination);
            destination = parent[destination];
        }
        path.push_back(1);

        reverse(path.begin(), path.end());
        path.insert(path.begin(), dist[n]);
        return path;
    }
};


int main()
{
    int n = 5, m = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
    Solution obj;
    vector<int> ans = obj.shortestPath(n, m, edges);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}

// Time Complexity: O(N + M * log(N)), where N is the number of vertices and M is the number of edges in the graph. How? Each node is processed once in the priority queue and deletion and insertion operation takes O(logN) time making it overall O(N*logN) in the worst case.
// For each vertex, all its edges are relaxed. This operation involves updating the priority queue, which takes O(logV) making it overall O(M*logN) for E edges in the worst case.
// Reconstructing the path involves tracing the parent array, which takes O(N) in the worst case (since we may trace back through all vertices).

// Space Complexity: O(N + M), where N is the number of vertices and M is the number of edges in the graph. The parent array and the distance array require O(N) space. The adjacency list requires O(M) space. The priority queue requires O(N) space.