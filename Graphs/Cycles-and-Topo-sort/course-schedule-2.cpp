
// 210. Course Schedule II
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
// Example 2:

// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
// So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
// Example 3:

// Input: numCourses = 1, prerequisites = []
// Output: [0]

// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= numCourses * (numCourses - 1)
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// ai != bi
// All the pairs [ai, bi] are distinct

#include<bits/stdc++.h>
using namespace std;    
class Solution {
  private:
    vector<int> topoSort(int V, vector<vector<int>>& adjReverse)
    {
        queue<int> q;
        vector<int> ans;
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto it : adjReverse[i])
                inDegree[it]++;
        }
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int front = q.front();
            ans.push_back(front);
            q.pop();
            for (auto it : adjReverse[front])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
        return ans;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int>inDegree(numCourses,0);
        vector<vector<int>> adjReverse(numCourses);
         for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        for (int i = 0; i < numCourses; i++)
        {
            for (auto it : adj[i])
            {
                adjReverse[it].push_back(i);
            }
        }
        vector<int> topo = topoSort(numCourses, adj);
        // sort(topo.begin(), topo.end());
        if(topo.size()<numCourses) return {};
        return topo;
    }
};