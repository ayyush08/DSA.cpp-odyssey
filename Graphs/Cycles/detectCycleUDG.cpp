// Detect a cycle in an undirected graph
// Given an undirected graph with V vertices labeled from 0 to V-1. The graph is represented using an adjacency list where adj[i] lists all nodes connected to node. Determine if the graph contains any cycles.

// Example 1
// Input: V = 6, adj= [[1, 3], [0, 2, 4], [1, 5], [0, 4], [1, 3, 5], [2, 4]]
// Output: True
// Explanation: The graph contains a cycle: 0 ->1 -> 2 -> 5 -> 4 -> 1.

// Example 2
// Input: V = 4, adj= [[1, 2], [0], [0, 3], [2]]
// Output: False
// Explanation: The graph does not contain any cycles.

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool bfs(int i,vector<int> adj[], vector<bool>& visited){
        queue<pair<int,int>> q;
        q.push({i,-1});
        visited[i]=true;
        while(!q.empty()){
            int current = q.front().first;
            int init = q.front().second;
            q.pop();
            for(auto it:adj[current]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push({it,current});
                }else if(it!=init){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        bool cycle = false;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                cycle = bfs(i,adj,visited);
                if(cycle) break;
            }
        }
        return cycle;

    }
};

int main(){
    int V = 6;
    vector<int> adj[V];
    adj[0] = {1, 3};
    adj[1] = {0, 2, 4};
    adj[2] = {1, 5};
    adj[3] = {0, 4};
    adj[4] = {1, 3, 5};
    adj[5] = {2, 4};
    Solution obj;
    cout<<obj.isCycle(V,adj)<<endl;
    return 0;
}