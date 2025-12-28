// Articulation point in graph


// Given an undirected graph with V vertices and adjacency list adj. Find all the vertices removing which (and edges through it) would increase the number of connected components in the graph. The graph may be initially disconnected.. Return the vertices in ascending order. If there are no such vertices then returns a list containing -1.

// Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

// Example 1

// Input: V = 7, adj=[[1,2,3], [0], [0,3,4,5], [2,0], [2,6], [2,6], [4,5]]

// Output: [0, 2]

// Explanation: If we remove node 0 or node 2, the graph will be divided into 2 or more components.

// Example 2

// Input: V = 5, adj=[[1], [0,4], [3,4], [2,4], [1,2,3]]

// Output: [1, 4]

// Explanation: If we remove either node 1 or node 4, the graph breaks into multiple components.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  int timer = 1;

private:
    void dfs(int node, int parent, int n, vector<int> adj[],
             vector<int> &insertionTime, vector<int> &lowestInsertionTime,
             vector<bool> &visited, vector<int>& mark)
    {
        visited[node] = true;
        insertionTime[node] = timer;
        lowestInsertionTime[node] = timer;
        timer++;

        int children = 0;
        for (auto &it : adj[node])
        {
            if (it != parent)
            {
                if (!visited[it])
                {
                    dfs(it, node, n, adj, insertionTime, lowestInsertionTime, visited, mark);
                    lowestInsertionTime[node] = min(lowestInsertionTime[node], lowestInsertionTime[it]);

                    if (lowestInsertionTime[it] >= insertionTime[node] && parent!=-1)
                       mark[node] = 1;
                    children++;
                }
                else
                {
                    lowestInsertionTime[node] = min(lowestInsertionTime[node], insertionTime[it]);
                }
            }
        }
        if(children > 1 && parent==-1) mark[node] = 1;
    }
public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        
        vector<bool> visited(n, false);

        vector<int> insertionTime(n);
        vector<int> lowestInsertionTime(n);
        vector<int>mark(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]) dfs(i,-1,n,adj,insertionTime,lowestInsertionTime,visited,mark);
        }
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(mark[i]) ans.push_back(i);
        }
        if(!ans.size()) return {-1};
        return ans;
    }
};


//We use the concept of discovery and low times to find articulation points in a graph from tarjan's algorithm but here we have to take care of few more conditions.
//1. If the node is root node and has more than 1 child then it is an articulation point.
//2. If the node is not root node and there is a child such that low[child]>=disc[node] then node is an articulation point.
//Time complexity: O(V+E)
//Space complexity: O(V)