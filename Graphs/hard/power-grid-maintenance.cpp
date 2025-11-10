// 3607. Power Grid Maintenance
// You are given an integer c representing c power stations, each with a unique identifier id from 1 to c (1‑based indexing).
// These stations are interconnected via n bidirectional cables, represented by a 2D array connections, where each element connections[i] = [ui, vi] indicates a connection between station ui and station vi. Stations that are directly or indirectly connected form a power grid.
// Initially, all stations are online (operational).

// You are also given a 2D array queries, where each query is one of the following two types:
// [1, x]: A maintenance check is requested for station x. If station x is online, it resolves the check by itself. If station x is offline, the check is resolved by the operational station with the smallest id in the same power grid as x. If no operational station exists in that grid, return -1.
// [2, x]: Station x goes offline (i.e., it becomes non-operational).
// Return an array of integers representing the results of each query of type [1, x] in the order they appear.
// Note: The power grid preserves its structure; an offline (non‑operational) node remains part of its grid and taking it offline does not alter connectivity.

// Example 1:
// Input: c = 5, connections = [[1,2],[2,3],[3,4],[4,5]], queries = [[1,3],[2,1],[1,1],[2,2],[1,2]]
// Output: [3,2,3]
// Explanation:
// Initially, all stations {1, 2, 3, 4, 5} are online and form a single power grid.
// Query [1,3]: Station 3 is online, so the maintenance check is resolved by station 3.
// Query [2,1]: Station 1 goes offline. The remaining online stations are {2, 3, 4, 5}.
// Query [1,1]: Station 1 is offline, so the check is resolved by the operational station with the smallest id among {2, 3, 4, 5}, which is station 2.
// Query [2,2]: Station 2 goes offline. The remaining online stations are {3, 4, 5}.
// Query [1,2]: Station 2 is offline, so the check is resolved by the operational station with the smallest id among {3, 4, 5}, which is station 3.

// Example 2:
// Input: c = 3, connections = [], queries = [[1,1],[2,1],[1,1]]
// Output: [1,-1]
// Explanation:
// There are no connections, so each station is its own isolated grid.
// Query [1,1]: Station 1 is online in its isolated grid, so the maintenance check is resolved by station 1.
// Query [2,1]: Station 1 goes offline.
// Query [1,1]: Station 1 is offline and there are no other stations in its grid, so the result is -1.

// Constraints:
// 1 <= c <= 105
// 0 <= n == connections.length <= min(105, c * (c - 1) / 2)
// connections[i].length == 2
// 1 <= ui, vi <= c
// ui != vi
// 1 <= queries.length <= 2 * 105
// queries[i].length == 2
// queries[i][0] is either 1 or 2.
// 1 <= queries[i][1] <= c

#include <bits/stdc++.h>
using namespace std;

// Brute Force - apply each query directly and do dfs/bfs for type 1 queries - O(c*(c+n)) time
//  Optimized Approach - pre-process to find connected components and maintain set of active nodes for each component - O(c+n) + O(q*log(c)) time
// An

class Solution
{
public:
    // O(c+n) [v+e]
    void dfs(int node, unordered_map<int, vector<int>> &adj, int id, vector<int> &nodeIds, unordered_map<int, set<int>> &idToSet, vector<bool> &visited)
    {
        visited[node] = true;
        idToSet[id].insert(node);
        nodeIds[node] = id;

        for (auto it : adj[node])
        {
            if (!visited[it])
                dfs(it, adj, id, nodeIds, idToSet, visited);
        }
    }
    vector<int> processQueries(int c, vector<vector<int>> &connections, vector<vector<int>> &queries)
    {
        unordered_map<int, vector<int>> adj;

        for (auto &edge : connections)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(c + 1, false);
        vector<int> nodeIds(c + 1);

        unordered_map<int, set<int>> idToSet;
        // pre-processing to collect which component node belongs to and also map each id to corresponsing set of nodes for fast access
        // O(c+n)
        for (int node = 1; node <= c; node++)
        {
            if (!visited[node])
            {
                int id = node;
                dfs(node, adj, id, nodeIds, idToSet, visited);
            }
        }

        vector<int> ans;
        // O(q*log(c))
        for (auto &query : queries)
        {
            int type = query[0];
            int station = query[1]; // node
            int id = nodeIds[station];

            if (type == 1)
            {
                if (idToSet[id].count(station))
                    ans.push_back(station);
                else if (!idToSet[id].empty())
                    ans.push_back(*idToSet[id].begin());
                else
                {
                    ans.push_back(-1); // no active stations;
                }
            }
            else
            {
                // log(c)
                idToSet[id].erase(station);
            }
        }
        return ans;
    }
};

// The DFS is causing O(c+n) time complexity in pre-processing step to find connected components.
// It can be even more optimized using Disjoint Set Union (DSU) or Union-Find data structure to achieve almost O(1) time complexity for union and find operations, leading to an overall time complexity of O((c+n) * α(c)) for pre-processing, where α is the inverse Ackermann function, which grows very slowly. This would make the solution more efficient for larger inputs.

struct DSU
{
    vector<int> parent;
    vector<int> rank;
    void init(int n)
    {
        parent.assign(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n + 1, 0);
    }
    int find(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }
    void unionByRank(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};

class Solution2
{
public:
    vector<int> processQueries(int c, vector<vector<int>> &connections,
                               vector<vector<int>> &queries)
    {
        vector<int> ans;
        DSU dsu;
        dsu.init(c);

        for (auto &edge : connections)
        {
            int u = edge[0];
            int v = edge[1];
            dsu.unionByRank(u, v);
        }

        unordered_map<int, set<int>> idToSet;
        for (int node = 1; node <= c; node++)
        {

            int id = dsu.find(node);
            idToSet[id].insert(node); // initially all online
        }

        for (auto &query : queries)
        {
            int type = query[0];
            int station = query[1]; // node
            int id = dsu.find(station);

            if (type == 1)
            {
                if (idToSet[id].count(station))
                    ans.push_back(station);
                else if (!idToSet[id].empty())
                    ans.push_back(*idToSet[id].begin());
                else
                {
                    ans.push_back(-1); // no active stations;
                }
            }
            else
            {
                // log(c)
                idToSet[id].erase(station);
            }
        }

        return ans;
    }
};