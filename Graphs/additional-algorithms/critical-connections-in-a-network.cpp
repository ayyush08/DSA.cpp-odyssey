// 1192. Critical Connections in a Network
// Attempted
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

// Return all critical connections in the network in any order.

// Example 1:

// Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
// Output: [[1,3]]
// Explanation: [[3,1]] is also accepted.
// Example 2:

// Input: n = 2, connections = [[0,1]]
// Output: [[0,1]]

// Constraints:

// 2 <= n <= 105
// n - 1 <= connections.length <= 105
// 0 <= ai, bi <= n - 1
// ai != bi
// There are no repeated connections.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int timer = 0;

private:
    void dfs(int node, int parent, int n, vector<int> adj[],
             vector<int> &insertionTime, vector<int> &lowestInsertionTime,
             vector<bool> &visited, vector<vector<int>> &bridges)
    {
        visited[node] = true;
        insertionTime[node] = timer;
        lowestInsertionTime[node] = timer;
        timer++;
        for (auto &it : adj[node])
        {
            if (it != parent)
            {
                if (!visited[it])
                {
                    dfs(it, node, n, adj, insertionTime, lowestInsertionTime, visited, bridges);
                    lowestInsertionTime[node] = min(lowestInsertionTime[node], lowestInsertionTime[it]);

                    if (lowestInsertionTime[it] > insertionTime[node])
                        bridges.push_back({node, it});
                }
                else
                {
                    lowestInsertionTime[node] = min(lowestInsertionTime[it], lowestInsertionTime[node]);
                }
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>> &connections)
    {
        vector<int> adj[n];

        for (auto &connection : connections)
        {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        vector<bool> visited(n, false);

        vector<int> insertionTime(n);
        vector<int> lowestInsertionTime(n);
        vector<vector<int>> bridges;
        dfs(0, -1, n, adj, insertionTime, lowestInsertionTime, visited,
            bridges);
        return bridges;
    }
};