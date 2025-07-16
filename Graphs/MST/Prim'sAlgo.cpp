// Find the MST weight

// Given a weighted, undirected, and connected graph with V vertices numbered from 0 to V-1 and E edges.
// The ith edge is represented by [ai,bi,wi], where ai and bi denotes the endpoint of the edge and the wi denotes the weight of the edge.
// Find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph.

// A minimum spanning tree (MST) or minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.

// Examples:

// Input: V = 4, edges = [[0, 1, 1], [1, 2, 2], [2, 3, 3], [0, 3, 4]]
// Output: 6
// Explanation:
// Edges included in the MST:
// [0, 1, 1] with weight 1
// [1, 2, 2] with weight 2
// [2, 3, 3] with weight 3
// The total weight of the MST is 1 + 2 + 3 = 6. These edges form a spanning tree that connects all vertices (0, 1, 2, 3) with the minimum possible total edge weight, satisfying the MST properties.

// Input: V = 3, edges = [[0, 1, 5], [1, 2, 10], [2,0,15]]
// Output: 15
// Explanation:
// Edges included in the MST:
// [0, 1, 5] with weight 5
// [1, 2, 10] with weight 10
// The total weight of the MST is 5+10 = 15

#include <bits/stdc++.h>
using namespace std;
#define P pair<int, int>
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> visited(V, 0);
        pq.push({0, 0});
        int s = 0;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int weight = it.first;

            if (visited[node])
                continue;
            visited[node] = 1;
            s += weight;

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgeWt = it[1];

                if (!visited[adjNode])
                    pq.push({edgeWt, adjNode});
            }
        }
        return s;
    }
};
        
int main()
{
    int V = 4;
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 2}, {2, 3, 3}, {0, 3, 4}};
    vector<vector<int>> adj[V];
    for (auto edge : edges)
    {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }
    Solution obj;
    cout << obj.spanningTree(V, adj) << endl; // Output: 6
    return 0;
}

//Time Complexity: O(ElogE) -In the worst case, the min-heap will store all the E edges, and insertion operation on the min-heap takes O(logE) time taking overall O(ElogE) time.

//Space Complexity:  O(E + V) (where V is the number of nodes in the graph)
// The min-heap will store all edges in worst-case taking O(E) space and the visited array takes O(V) space.