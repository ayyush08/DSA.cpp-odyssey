// M Coloring Problem

// Given an integer M and an undirected graph with N vertices and E edges. The goal is to determine whether the graph can be coloured with a maximum of M colors so that no two of its adjacent vertices have the same colour applied to them.
// In this context, colouring a graph refers to giving each vertex a different colour. If the colouring of vertices is possible then return true, otherwise return false.

// Examples:
// Input : N = 4 , M = 3 , E = 5 , Edges = [ (0, 1) , (1, 2) , (2, 3) , (3, 0) , (0, 2) ]
// Output : true
// Explanation : Consider the three colors to be red, green, blue.
// We can color the vertex 0 with red, vertex 1 with blue, vertex 2 with green, vertex 3 with blue.
// In this way we can color graph using 3 colors at most.

// Input : N = 3 , M = 2 , E = 3 , Edges = [ (0, 1) , (1, 2) , (0, 2) ]
// Output : false
// Explanation : Consider the three colors to be red, green.
// We can color the vertex 0 with red, vertex 1 with blue.
// As the vertex 2 is adjacent to both vertex 1 and 0 , so we cannot color with red and green.
// Hence as we could not color all vertex of graph we return false.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(int i, int node, vector<int> &colors, vector<int> adj[])
    {
        for (auto it : adj[node])
        {
            if (colors[it] == i) //adjacent node has the same color , cannot color
                return false;
        }
        return true;
    }
    bool startColor(vector<int> adj[], vector<int> &colors, int m, int n, int node)
    {
        if (n == node)
            return true;

        for (int i = 1; i <= m; i++) //check all colors
        {
            if (isPossible(i, node, colors, adj))
            {
                colors[node] = i;
                if (startColor(adj, colors, m, n, node + 1)) //check adjacent nodes with the current color
                    return true;
                colors[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(vector<vector<int>> &edges, int m, int n)
    {
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> colors(n, -1);

        return startColor(adj, colors, m, n, 0);
    }
};

// Time Complexity : O(M^N) where m is the number of colors and n is the number of nodes, since each node can be colored in m ways and there are n nodes to color.

// Space Complexity : O(N) for the colors array and O(n) for the adjacency list, resulting in O(N) total space complexity.