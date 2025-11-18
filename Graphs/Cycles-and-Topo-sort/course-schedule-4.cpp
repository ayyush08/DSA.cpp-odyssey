// 1462. Course Schedule IV
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

// For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
// Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

// You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

// Return a boolean array answer, where answer[j] is the answer to the jth query.

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
// Output: [false,true]
// Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
// Course 0 is not a prerequisite of course 1, but the opposite is true.
// Example 2:

// Input: numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
// Output: [false,false]
// Explanation: There are no prerequisites, and each course is independent.
// Example 3:

// Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
// Output: [true,true]

// Constraints:

// 2 <= numCourses <= 100
// 0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)
// prerequisites[i].length == 2
// 0 <= ai, bi <= numCourses - 1
// ai != bi
// All the pairs [ai, bi] are unique.
// The prerequisites graph has no cycles.
// 1 <= queries.length <= 104
// 0 <= ui, vi <= numCourses - 1
// ui != vi

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, unordered_set<int>> topoSort(vector<vector<int>> &adj, vector<int> &inDegree, unordered_map<int, unordered_set<int>> &topo, int V)
    {
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        while (q.size())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                // Propagate all prerequisites of current node to all its neighbors for transitive closure
                topo[it].insert(node);
                for (auto req : topo[node])
                    topo[it].insert(req);
                inDegree[it]--;
                if (!inDegree[it])
                    q.push(it);
            }
        }
        return topo;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (auto &pre : prerequisites)
        {
            adj[pre[0]].push_back(pre[1]);
            inDegree[pre[1]]++;
        }
        unordered_map<int, unordered_set<int>> topo;
        topo = topoSort(adj, inDegree, topo, numCourses);
        vector<bool> ans(queries.size(), false);

        for (int i = 0; i < queries.size(); i++)
        {
            ans[i] = topo[queries[i][1]].count(queries[i][0]);
        }
        return ans;
    }
};

// Time Complexity: O(V + E + Q) where V is number of courses, E is number of prerequisites and Q is number of queries
// Space Complexity: O(V^2) for storing transitive closure in worst case