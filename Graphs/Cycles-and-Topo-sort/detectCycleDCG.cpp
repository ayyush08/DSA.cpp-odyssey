// Detect a cycle in a directed graph
// 100
// Hard
// Companies
// Given a directed graph with V vertices labeled from 0 to V-1. The graph is represented using an adjacency list where adj[i] lists all nodes connected to node. Determine if the graph contains any cycles.

// Examples:
// Input: V = 6, adj= [ [1], [2, 5], [3], [4], [1], [ ] ]
// Output: True
// Explanation: The graph contains a cycle: 1 -> 2 -> 3 -> 4 -> 1.

// Input: V = 4, adj= [[1,2], [2], [], [0,2]]
// Output: False
// Explanation: The graph does not contain a cycle.

#include <bits/stdc++.h>
using namespace std;

// Using Kahn's algo topological sort - if after sorting answer does not contain all nodes means cycle was detected.

class Solution
{
private:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        queue<int> q;
        vector<int> ans;
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
                inDegree[it]++;
        }
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int front = q.front();
            ans.push_back(front);
            q.pop();
            for (auto it : adj[front])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
        return ans;
    }

public:
    bool isCyclic(int N, vector<int> adj[])
    {
        vector<int> topoCheck = topoSort(N, adj);
        return topoCheck.size() < N;
    }
};

// Using DFS - Trace the path once you reach the end, untrace the path and while tracing check if the path is already walked upon, if yes then cycle is found.
class Solution2
{
private:
    bool dfs(int node, vector<int> &visited, vector<int> &walked, vector<int> adj[])
    {
        visited[node] = 1;
        walked[node] = 1;
        for (auto it : adj[node])
        {
            if (walked[it])
                return true;
            else if (!visited[it])
            {
                if (dfs(it, visited, walked, adj))
                    return true;
            }
        }
        walked[node] = 0;
        return false;
    }

public:
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        vector<int> walked(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, visited, walked, adj))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    int V = 6;
    vector<int> adj[V] = {{1}, {2, 5}, {3}, {4}, {1}, {}};

    Solution2 obj;
    if (obj.isCyclic(V, adj))
        cout << "The graph contains a cycle." << endl;
    else
        cout << "The graph does not contain a cycle." << endl;

    return 0;
}