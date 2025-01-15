// Find eventual safe states
// Given a directed graph with V vertices labeled from 0 to V-1. The graph is represented using an adjacency list where adj[i] lists all nodes adjacent to node i, meaning there is an edge from node i to each node in adj[i]. A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node. Return an array containing all the safe nodes of the graph in ascending order.

// Examples:
// Input: V = 7, adj= [[1,2], [2,3], [5], [0], [5], [], []]
// Output: [2, 4, 5, 6]
// Explanation:
// From node 0: two paths are there 0->2->5 and 0->1->3->0.
// The second path does not end at a terminal node. So it is not
// a safe node.

// From node 1: two paths exist: 1->3->0->1 and 1->2->5.
// But the first one does not end at a terminal node. So it is not a safe node.
// From node 2: only one path: 2->5 and 5 is a terminal node.
// So it is a safe node.
// From node 3: two paths: 3->0->1->3 and 3->0->2->5
// but the first path does not end at a terminal node.
// So it is not a safe node.
// From node 4: Only one path: 4->5 and 5 is a terminal node.
// So it is also a safe node.
// From node 5: It is a terminal node.
// So it is a safe node as well.
// From node 6: It is a terminal node.
// So it is a safe node as well.

// Input: V = 4, adj= [[1], [2], [0,3], []]
// Output: [3]
// Explanation: Node 3 itself is a terminal node and it is a safe node as well. But all the paths from other nodes do not lead to a terminal node.So they are excluded from the answer.

#include <bits/stdc++.h>
using namespace std;
// NOTICE- unsafe are those node upon which walking ends up in a cycle (Cycle Detection Intuition)

// Using DFS - detect cycle and while checking first  mark the node as unsafe if cycle detected it'll remain unsafe else mark it safe after traversing the path. Now simply return the safe nodes stores in safety array.
class Solution
{
private:
    bool dfs(int node, vector<int> &visited, vector<int> &walked,
             vector<int> adj[], vector<int> &safety)
    {
        visited[node] = 1;
        walked[node] = 1;
        safety[node] = 0;
        for (auto it : adj[node])
        {
            if (walked[it])
                return true;
            else if (!visited[it])
            {
                if (dfs(it, visited, walked, adj, safety))
                    return true;
            }
        }
        walked[node] = 0;
        safety[node] = 1;
        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        vector<int> walked(V, 0);
        vector<int> safety(V, 0);
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, walked, adj, safety);
            }
        }
        for (int i = 0; i < safety.size(); i++)
        {
            if (safety[i])
                ans.push_back(i);
        }
        return ans;
    }
};

// Using BFS Kahn's topo sort -  First, reverse the directions, then topo sort, and finally sort the topo sort to get the ans

class Solution2
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
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> adjReverse[V];
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                adjReverse[it].push_back(i);
            }
        }
        vector<int> topo = topoSort(V, adjReverse);
        sort(topo.begin(), topo.end());
        return topo;
    }
};

int main()
{
    Solution2 sol;
    int V = 7;
    vector<int> adj[] = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<int> safeNodes = sol.eventualSafeNodes(V, adj);
    for (int node : safeNodes)
    {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}