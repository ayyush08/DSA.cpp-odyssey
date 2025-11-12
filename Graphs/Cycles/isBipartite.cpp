// Bipartite graph

// A bipartite graph is a graph that can be colored using 2 colors such that no adjacent nodes have the same color. Any linear graph with no cycle is always a bipartite graph. With a cycle, any graph with an even cycle length can also be a bipartite graph. So, any graph with an odd cycle length can never be a bipartite graph.

// Given an undirected graph with V vertices labeled from 0 to V-1. The graph is represented using an adjacency list where adj[i] lists all nodes connected to node. Determine if the graph is bipartite or not.

// A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

// Examples:
// Input: V=4, adj = [[1,3],[0,2],[1,3],[0,2]]

// Output: True

// Explanation: The given graph is bipartite since, we can partition the nodes into two sets: {0, 2} and {1, 3}.

// Input: V=4, adj = [[1,2,3],[0,2],[0,1,3],[0,2]]

// Output: False

// Explanation: The graph is not bipartite. If we attempt to partition the nodes into two sets, we encounter an edge that connects two nodes within the same set, which violates the bipartite property.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool checkComponent(int start, vector<int> adj[], vector<int> &color)
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty())
        {
            int currentNode = q.front();
            q.pop();
            for (auto it : adj[currentNode])
            {
                if (color[it] == -1)
                {
                    color[it] = !color[currentNode];
                    q.push(it);
                }
                else if (color[it] == color[currentNode])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (checkComponent(i, adj, color) == false)
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    int V = 4;
    vector<int> adj[V];
    adj[0] = {1, 3};
    adj[1] = {0, 2};
    adj[2] = {1, 3};
    adj[3] = {0, 2};
    Solution obj;
    cout << obj.isBipartite(V, adj);
    return 0;
}

// DFS

class Solution2
{
public:
    bool func(int node, vector<int> adj[], vector<int> &color, int toColor)
    {
        color[node] = toColor;
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                if (func(it, adj, color, !toColor) == false)
                    return false;
            }
            else if (color[it] == toColor)
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!func(i, adj, color, 0))
                    return false;
            }
        }
        return true;
    }
};
