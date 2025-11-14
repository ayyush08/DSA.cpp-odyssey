// Given a Directed Acyclic Graph (DAG) with V vertices labeled from 0 to V-1 and E edges.The graph is represented using an adjacency list where adj[i] lists all nodes connected to node. Find any Topological Sorting of that Graph.

// In topological sorting, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).
// The Output will be True if  your topological sort is correct otherwise it will be False.

// Examples:
// Input: V = 6,adj=[ [ ], [ ], [3], [1], [0,1], [0,2] ]
// Output: [5, 4, 2, 3, 1, 0]
// Explanation: A graph may have multiple topological sortings.
// The result is one of them. The necessary conditions
// for the ordering are:

// According to edge 5 -> 0, node 5 must appear before node 0 in the ordering.
// According to edge 4 -> 0, node 4 must appear before node 0 in the ordering.
// According to edge 5 -> 2, node 5 must appear before node 2 in the ordering.
// According to edge 2 -> 3, node 2 must appear before node 3 in the ordering.
// According to edge 3 -> 1, node 3 must appear before node 1 in the ordering.
// According to edge 4 -> 1, node 4 must appear before node 1 in the ordering.
// The above result satisfies all the necessary conditions.
// [4, 5, 2, 3, 1, 0] is also one such topological sorting
// that satisfies all the conditions.

// Input: V = 4, adj=[ [ ], [0], [0], [0] ]
// Output: [3, 2, 1, 0]
// Explanation: The necessary conditions for the ordering are:
// For edge 1 -> 0 node 1 must appear before node 0.
// For edge 2 -> 0 node 1 must appear before node 0.
// For edge 3 -> 0 node 1 must appear before node 0.

// Using DFS:

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(int i, vector<int> &visited, stack<int> &st, vector<int> adj[])
    {
        visited[i] = 1;
        for (auto it : adj[i])
        {
            if (!visited[it])
                dfs(it, visited, st, adj);
        }
        st.push(i);
    }

public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<int> ans;
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, st, adj);
            }
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
//Using BFS (Kahn's Algorithm)
class Solution2
{
public:
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
};

int main()
{
    int V = 6;
    vector<int> adj[V];
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[5].push_back(0);
    adj[5].push_back(2);

    Solution2 obj;
    vector<int> result = obj.topoSort(V, adj);

    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

// Why does topological sort only exist in DAG?

// If the edges are undirected: An undirected edge between node u and v signifies an edge from u to v (u->v) as well as from v to u (v->u) making it practically impossible to write such orderings where u appears before v and v appears before u simultaneously.
// If the directed graph contains a cycle: There is no linear ordering possible for nodes in cycles, making it impossible for topological sorting to exist.
