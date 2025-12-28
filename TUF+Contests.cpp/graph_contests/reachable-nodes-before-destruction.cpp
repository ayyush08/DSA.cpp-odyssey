// Reachable Nodes Before Destruction
// Easy

// You are given a network of n nodes, represented by an undirected graph, where each node is connected to other nodes by edges. Each edge has a specific travel time associated with it. Additionally, you are given an array destroy_time where destroy_time[i] denotes the time at which node

// i will be destroyed. Once a node is destroyed, it becomes inaccessible.Starting from node 0, your task is to determine which nodes can be reached and saved before they are destroyed. A node is considered "saved" if you can reach it from node 0 before the time mentioned in destroy_time.

// Return an array where answer[i] is 1 if node i can be saved (i.e., you can reach it before it is destroyed) and 0 if it cannot be saved.

// Example 1

// Input: n = 4, edges = [[0,1,3],[1,2,2],[0,2,5],[2,3,4]], destroy_time = [6,4,7,5]

// Output: [1, 1, 1, 0]

// Explanation:

// Node 0: This is the starting point, and it is already saved, so the answer is 1.

// Node 1: It takes 3 units of time to reach via the edge [0,1], and it is destroyed at time 4, so it be saved.

// Node 2: It takes 5 units of time to reach via the edge [0,2], and it is destroyed at time 7, so it can be saved.

// Node 3: It takes 9 units of time to reach via the edges [0,2] → [2,3], but it is destroyed at time 5, so it cannot be saved.

// Example 2

// Input: n = 5, edges = [[0,1,2],[0,2,3],[1,3,4],[2,4,1]], destroy_time = [5,6,8,7,9]

// Output: [1, 1, 1, 1, 1]

// Explanation:

// Node 0: This is the starting point, and it is already saved, so the answer is 1.

// Node 1: It takes 2 units of time to reach via the edge [0,1], and it is destroyed at time 6, so it can be saved.

// Node 2: It takes 3 units of time to reach via the edge [0,2], and it is destroyed at time 8, so it can be saved.

// Node 3: It takes 6 units of time to reach via the edges [0,1] → [1,3], and it is destroyed at time 7, so it can be saved.

// Node 4: It takes 4 units of time to reach via the edges [0,2] → [2,4], and it is destroyed at time 9, so it can be saved.

// Constraints

// 1 <= n <= 5 * 104
// 0 <= edges.length <= 105
// edges[i] == [ui, vi, lengthi]
// 0 <= ui, vi <= n - 1
// 1 <= lengthi <= 105
// destroy_time.length == n
// 1 <= destroy_time[i] <= 105

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> reachableNodes(int n, vector<vector<int>> &v, vector<int> &d)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto e : v)
        {
            int u = e[0];
            int v = e[1];
            int t = e[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<int> timeToReach(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        if (d[0] > 0)
        {
            timeToReach[0] = 0;
            pq.push({0, 0});
        }

        while (!pq.empty())
        {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (time >= d[node])
                continue;
            if (time > timeToReach[node])
                continue;

            for (auto &it : adj[node])
            {
                int newTime = time + it.second;
                if (newTime < timeToReach[it.first] && newTime < d[it.first])
                {
                    timeToReach[it.first] = newTime;
                    pq.push({newTime, it.first});
                }
            }
        }
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (timeToReach[i] < d[i])
                ans[i] = 1;
        }
        return ans;
    }
};
