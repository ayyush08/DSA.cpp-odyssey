// 3650. Minimum Cost Path with Edge Reversals
// You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with cost wi.

// Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used its switch, you may activate it on one of its incoming edges vi → ui reverse that edge to ui → vi and immediately traverse it.

// The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.

// Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.

// Example 1:

// Input: n = 4, edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]

// Output: 5

// Explanation:

// Use the path 0 → 1 (cost 3).
// At node 1 reverse the original edge 3 → 1 into 1 → 3 and traverse it at cost 2 * 1 = 2.
// Total cost is 3 + 2 = 5.
// Example 2:

// Input: n = 4, edges = [[0,2,1],[2,1,1],[1,3,1],[2,3,3]]

// Output: 3

// Explanation:

// No reversal is needed. Take the path 0 → 2 (cost 1), then 2 → 1 (cost 1), then 1 → 3 (cost 1).
// Total cost is 1 + 1 + 1 = 3.

// Constraints:

// 2 <= n <= 5 * 104
// 1 <= edges.length <= 105
// edges[i] = [ui, vi, wi]
// 0 <= ui, vi <= n - 1
// 1 <= wi <= 1000


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, int> P;
    int dijkstra(vector<vector<P>>& adj, int n) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        int minCost = 0;
        while (pq.size()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == n - 1)
                return wt;

            for (auto &it : adj[node]) {
                int adjNode = it.first;
                int nwt = it.second;
                if (dist[adjNode] > wt + nwt) {
                    dist[adjNode] = wt + nwt;
                    pq.push({wt + nwt, adjNode});
                }
            }
        }
        return -1;
    }
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<P>> adj(n);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
            int rwt = 2 * wt;
            adj[v].push_back({u, rwt});
        }
        return dijkstra(adj, n);
    }
};

//Time Complexity: O((V + E) log V) where V is the number of vertices and E is the number of edges.
//Space Complexity: O(V + E) for the adjacency list and O(V) for the distance array.

//Intuition:
//Just add the reversed edges with cost 2 * wi to the original graph and run Dijkstra's algorithm to find the shortest path from node 0 to node n - 1.