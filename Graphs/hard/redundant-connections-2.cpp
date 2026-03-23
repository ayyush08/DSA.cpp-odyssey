// 685. Redundant Connection II
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

// The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.

// The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.

// Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

// Example 1:

// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]
// Example 2:

// Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
// Output: [4,1]

// Constraints:

// n == edges.length
// 3 <= n <= 1000
// edges[i].length == 2
// 1 <= ui, vi <= n
// ui != vi

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Union-Find + Indegree tracking.
// Find the node with indegree 2, if it doesn't exist, then find the edge that forms a cycle and return it. If it exists, then check for both the edges that point to the node with indegree 2, if removing any of them results in a graph without a cycle, then return that edge.
class Solution
{
public:
    int n;
    struct DSU
    {
        vector<int> parent;
        vector<int> rank;
        void init(int n)
        {
            parent.resize(n + 1);
            rank.resize(n + 1, 1);
            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }
        int find(int node)
        {
            if (parent[node] == node)
                return node;
            return parent[node] = find(parent[node]);
        }
        void unionByRank(int a, int b)
        {
            a = find(a);
            b = find(b);
            if (a == b)
                return;
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    };
    vector<int> checkCycle(vector<vector<int>> &edges, vector<int> toSkip)
    {
        DSU dsu;
        dsu.init(n);
        for (auto &e : edges)
        {
            if (toSkip.size() && e == toSkip)
                continue;
            if (dsu.find(e[0]) == dsu.find(e[1]))
                return e;
            dsu.unionByRank(e[0], e[1]);
        }
        return {};
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        n = edges.size();
        vector<int> inDegree(n + 1, 0);
        int extraNode = -1;
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            inDegree[v]++;
            if (inDegree[v] > 1)
            {
                extraNode = v;
                break;
            }
        }
        if (extraNode == -1)
            return checkCycle(edges, {});

        for (int i = n - 1; i >= 0; i--)
        {
            if (edges[i][1] == extraNode)
            {
                if (checkCycle(edges, edges[i]).empty())
                    return edges[i];
            }
        }
        return {};
    }
};

//Appraoch 2: Union-Find
//Decide upfront which edge to ignore, then run DSU once 

class Solution {
public:
    int n;
    struct DSU {
        vector<int> parent;
        vector<int> rank;
        void init(int n) {
            parent.resize(n+1);
            rank.resize(n+1,1);
            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }
        int find(int node) {
            if (parent[node] == node)
                return node;
            return parent[node] = find(parent[node]);
        }
        void unionByRank(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b)
                return;
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }

    };
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        n = edges.size();
        vector<int>parent(n+1,-1);
        vector<int>e1,e2;
        for(auto& e:edges){
            int u = e[0];
            int v = e[1];
           if(parent[v]==-1) parent[v] = u;
           else{
                e1 = {parent[v],v}; // first edge that points to the node with indegree 2
                e2 = e; // second edge that points to the node with indegree 2
                e[1] = -1; //disable to avoid union later
           }
        }

        DSU dsu;
        dsu.init(n);
        for(auto& e:edges){
            if(e[1]==-1) continue; //ignore the disableed edge
            int u = e[0];
            int v = e[1];
            
            if(dsu.find(u)==dsu.find(v)){
                if(e1.empty()) return e; //if there is no node with indegree 2, then return the edge that forms a cycle
                return e1; //if there is a node with indegree 2, then return the first edge that points to that node, because the second edge is the one that is currently being processed and is causing the cycle, so we need to remove the first edge to break the cycle.
            }
            dsu.unionByRank(u,v);

        }
        return e2;//if there is a node with indegree 2, and removing the first edge doesn't break the cycle, then we need to remove the second edge.

    }
}; 