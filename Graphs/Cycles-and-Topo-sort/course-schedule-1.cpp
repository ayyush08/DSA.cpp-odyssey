// 207. Course Schedule

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// All the pairs prerequisites[i] are unique.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &prerequisites)
    {
        vector<int> inDegree(V, 0);
        queue<int> q;
        vector<int> topo;
        vector<vector<int>> adj(V);
        for (auto &pre : prerequisites)
        {
            adj[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        for (int i = 0; i < V; i++)
            if (inDegree[i] == 0)
                q.push(i);

        while (q.size())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
        return topo;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> topo = topoSort(numCourses, prerequisites);
        return topo.size() == numCourses;
    }
};

//We are asked to find if we can finish all courses or not.
//If we can find a topological sort of all the courses, then we can finish all courses.
//If there is a cycle in the graph, then we cannot finish all courses as we will be stuck in the cycle.
//So, we just need to check if we can find a topological sort of all the courses or not.

//Time Complexity: O(V + E) where V is the number of courses and E is the number of prerequisites.
//Space Complexity: O(V + E) for the adjacency list and inDegree array.