// 743. Network Delay Time
// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

// Example 1:

// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2
// Example 2:

// Input: times = [[1,2,1]], n = 2, k = 1
// Output: 1
// Example 3:

// Input: times = [[1,2,1]], n = 2, k = 2
// Output: -1

// Constraints:

// 1 <= k <= n <= 100
// 1 <= times.length <= 6000
// times[i].length == 3
// 1 <= ui, vi <= n
// ui != vi
// 0 <= wi <= 100
// All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

#include <bits/stdc++.h>
using namespace std;

// Bfs with queue and Dijkstra's Algorithm both are applicable here

typedef pair<int, int> P;
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<P>> adj(n);
        for (auto time : times)
        {
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
        vector<int> reach(n, 1e9);

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, k - 1});
        reach[k - 1] = 0;

        while (pq.size())
        {
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();

            for (auto &it : adj[node])
            {
                int adjNode = it.first;
                int currentTime = it.second;
                if (time + currentTime < reach[adjNode])
                {
                    reach[adjNode] = time + currentTime;
                    pq.push({reach[adjNode], adjNode});
                }
            }
        }
        int ans = 0;
        for (int r : reach)
        {
            if (r == 1e9)
                return -1;
            ans = max(ans, r);
        }

        return ans;
    }
};

//Time Complexity: O(E log V) where E is the number of edges and V is the number of vertices.
//Space Complexity: O(V + E) for the adjacency list and O(V) for the priority queue.

class Solution2
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto time : times)
        {
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
        vector<int> reach(n, 1e9);

        queue<pair<int, int>> q;
        q.push({k - 1, 0});
        reach[k - 1] = 0;

        while (q.size())
        {
            int node = q.front().first;
            int time = q.front().second;
            q.pop();

            for (auto &it : adj[node])
            {
                int adjNode = it.first;
                int currentTime = it.second;
                if (time + currentTime < reach[adjNode])
                {
                    reach[adjNode] = time + currentTime;
                    q.push({adjNode, reach[adjNode]});
                }
            }
        }
        int ans = 0;
        for (int r : reach)
        {
            if (r == 1e9)
                return -1;
            ans = max(ans, r);
        }

        return ans;
    }
};

//Time Complexity: O(E + V) where E is the number of edges and V is the number of vertices.
//Space Complexity: O(V + E) for the adjacency list and O(V) for the