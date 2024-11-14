#include<bits/stdc++.h>
using namespace std;

// Storage of Graphs using Adjacency Matrix

// int main()
// {
//     int n,m;
//     cout << "Enter the number of vertices and edges: ";
//     cin>>n>>m;
//     int adj[n+1][n+1];
//     cout << "Enter the edges: ";
//     for(int i=0;i<m;i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         adj[u][v]=1;
//         adj[v][u]=1;
//     }

// return 0;
// }

// Storage of Graphs using Adjacency List


int main()
{
    int n,m;
    cout << "Enter the number of vertices and edges: ";
    cin>>n>>m;
    vector<int> adj[n+1];
    cout << "Enter the edges: ";
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For directed graph, remove this line
    }

return 0;
}