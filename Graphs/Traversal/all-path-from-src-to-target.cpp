// 797. All Paths From Source to Target
// Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

// The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

// Example 1:

// Input: graph = [[1,2],[3],[3],[]]
// Output: [[0,1,3],[0,2,3]]
// Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
// Example 2:

// Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
// Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

// Constraints:

// n == graph.length
// 2 <= n <= 15
// 0 <= graph[i][j] < n
// graph[i][j] != i (i.e., there will be no self-loops).
// All the elements of graph[i] are unique.
// The input graph is guaranteed to be a DAG.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    int src;
    int target;
    vector<vector<int>> ans;
    void solve(int node, vector<vector<int>> &graph, vector<int> &temp)
    {
        temp.push_back(node);
        if (node == target)
        {
            ans.push_back(temp);
        }
        for (int ngbr : graph[node])
        {
            solve(ngbr, graph, temp);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        n = graph.size();
        src = 0;
        target = n - 1;
        vector<int> temp;
        solve(src, graph, temp);
        return ans;
    }
};

//Time Complexity: O(2^n * n) where n is the number of nodes in the graph. In the worst case, there can be 2^(n-2) paths from source to target, and each path can take O(n) time to construct.
//Space Complexity: O(n) for the recursion stack and O(2^n * n) for storing the paths in the answer.