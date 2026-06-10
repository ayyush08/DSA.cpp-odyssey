// Count Number of trees in an Undirected Graph

//You are given an UDG with N vertices numbered from 0 to N-1 and M edges. Your task is to find the number of trees in the given graph. A tree is a connected component of the graph that has no cycles. Return number of connected components that are trees.


#include <bits/stdc++.h>
using namespace std;


bool isTree(vector<vector<int>>& adj,int node,vector<bool>& visited,int parent){
    visited[node] = true;

    for(auto& it:adj[node]){
        if(it==parent) continue;
        if(visited[it]) return false;
        if(!isTree(adj,it,visited,node)){
            return false;
        }
    }

    return true;
}




int countConnectedTrees(vector<vector<int>>& edges,int n){
    vector<vector<int>> adj(n);

    for(auto edge:edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    
    int components = 0;

    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(isTree(adj,i,visited,-1)){
                components++;
            }
        }
    }
    return components;
}

int main(){
    vector<vector<int>> edges = {{0,1},{1,2},{2,0},{3,4}};

    cout << countConnectedTrees(edges,5) << endl;
    return 0;
   
}