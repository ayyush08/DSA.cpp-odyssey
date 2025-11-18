// Shortest path in DAG
// Given a Directed Acyclic Graph of N vertices from 0 to N-1 and M edges and a 2D Integer array edges, where there is a directed edge from vertex edge[i][0] to vertex edge[i][1] with a distance of edge[i][2] for all i.
// Find the shortest path from source vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex. The source vertex is assumed to be 0.

// Examples
// Input: N = 4, M = 2 edge = [[0,1,2],[0,2,1]]
// Output: 0 2 1 -1
// Explanation:
// Shortest path from 0 to 1 is 0->1 with edge weight 2.
// Shortest path from 0 to 2 is 0->2 with edge weight 1.
// There is no way we can reach 3, so it's -1 for 3.

// Input: N = 6, M = 7 edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
// Output: 0 2 3 6 1 5
// Explanation:
// Shortest path from 0 to 1 is 0->1 with edge weight 2.
// Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3.
// Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6.
// Shortest path from 0 to 4 is 0->4 with edge weight 1.
// Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.

// Approach

// Step 1 : Create a graph using adjacency list of pair<int,int> to store the destination vertex and the weight of the edge. T
// Step 2 : Get the topoSort of the graph.
// Step 3 : Initialize the distance array with INT_MAX and distance of source vertex as 0.
// Step 4 : Traverse the topoSort and relax the edges.
// Step 5 : Return the distance array.

// Using DFS for Topological Sort
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void topoSort(int i, vector<pair<int, int>> adj[], int visited[], stack<int> &st)
    {
        visited[i] = 1;
        for (auto it : adj[i])
        {
            if (!visited[it.first])
                topoSort(it.first, adj, visited, st);
        }
        st.push(i);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++)
        {
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            int weight = edges[i][2];
            adj[node1].push_back({node2, weight});
        }
        int visited[N] = {0};
        stack<int> st;

        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                topoSort(i, adj, visited, st);
            }
        }

        vector<int> dist(N, 1e9);
        dist[0] = 0;

        while (!st.empty())
        {
            int top = st.top();
            st.pop();

            for (auto it : adj[top])
            {
                int node = it.first;
                int wght = it.second;

                if (dist[top] + wght < dist[node])
                    dist[node] = dist[top] + wght;
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }
        return dist;
    }
};

int main()
{
    int N = 3, M = 3;
    vector<vector<int>> edges = {{0, 1, 4}, {0, 2, 2}, {1, 2, 5}};
    Solution obj;
    vector<int> ans = obj.shortestPath(N, M, edges);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}

// Time Complexity: O(N+M)

// Using Kahn's Algorithm for Topological Sort

class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<pair<int, int>>> &adj)
    {
        queue<int> q;
        vector<int> ans;
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
                inDegree[it.first]++;
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
                inDegree[it.first]--;
                if (inDegree[it.first] == 0)
                    q.push(it.first);
            }
        }
        return ans;
    }
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(N);
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }
        vector<int> topo = topoSort(N, adj);
        vector<int> dist(N, 1e9);
        dist[0] = 0;
        for (int i = 0; i < N; i++)
        {
            int node = topo[i];
            for (auto [it, wt] : adj[node])
            {
                if (dist[node] + wt < dist[it])
                    dist[it] = dist[node] + wt;
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }
        return dist;
    }
};
