// Number of provinces
// Given an undirected graph with V vertices. Two vertices u and v belong to a single province if there is a path from u to v or v to u. Find the number of provinces. The graph is given as an n x n matrix adj where adj[i][j] = 1 if the ith city and the jth city are directly connected, and adj[i][j] = 0 otherwise.
// A province is a group of directly or indirectly connected cities and no other cities outside of the group.


// Example 1
// Input: adj=[ [1, 0, 0, 1], [0, 1, 1, 0], [0, 1, 1, 0], [1, 0, 0, 1] ]
// Output: 2
// Explanation:In this graph, there are two provinces: [1, 4] and [2, 3]. City 1 and city 4 have a path between them, and city 2 and city 3 also have a path between them. There is no path between any city in province 1 and any city in province 2.

// Example 2
// Input: adj= [ [1, 0, 1], [0, 1, 0], [1, 0, 1] ]
// Output: 2
// Explanation: The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.


#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfsOfGraph(int start, vector<int> adjList[], int vis[])
    {
        vis[start] = 1;
        for (auto it : adjList[start])
        {
            if (!vis[it])
            {
                dfsOfGraph(it, adjList, vis);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj)
    {
        int V = adj.size();
        vector<int> adjList[V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int vis[V] = {0};
        int provinces = 0;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                provinces++;
                dfsOfGraph(i, adjList, vis);
            }
        }
        return provinces;
    }
};

int main(){
    Solution s;
    vector<vector<int>> adj = {{1,0,1},{0,1,0},{1,0,1}};
    cout << s.numProvinces(adj) << endl;
    return 0;
}