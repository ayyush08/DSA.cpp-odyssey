// Find All Possible Tasks
// You are given a set of tasks and their required resources. Each task has a list of resources that are needed to complete it, and some of the resources might themselves be tasks that need to be completed first. You are also given a set of resources that you already have.

// Your task is to determine which tasks can be completed based on the resources you already have, including the tasks that can be completed indirectly by first completing other tasks.

// Return a list of tasks that you can complete. You may return the answer in any order.

// Example 1

// Input: tasks = ["cleaning"], resources = [["broom","soap"]], available = ["broom","soap","vacuum"]

// Output: ["cleaning"]

// Explanation: You can complete the task "cleaning" because you have the resources "broom" and "soap".

// Example 2

// Input: tasks = ["cleaning","laundry"], resources = [["broom","soap"],["cleaning","detergent"]], available = ["broom","soap","detergent"]

// Output: ["cleaning","laundry"]

// Explanation: You can complete "cleaning" because you have "broom" and "soap".

// You can also complete "laundry" because you have "detergent" and can complete "cleaning" which is required for "laundry".

// Constraints

// n == tasks.length == resources.length

// 1 <= n <= 100

// 1 <= resources[i].length, available.length <= 500

// 1 <= tasks[i].length, resources[i][j].length, available[k].length <= 10

// All the values of tasks and available combined are unique.

// Each resources[i] does not contain any duplicate values.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &tasks, vector<vector<string>> &resources, vector<string> &available)
    {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;

        for (auto &task : tasks)
            indegree[task] = 0;

        for (int i = 0; i < tasks.size(); i++)
        {
            for (auto &res : resources[i])
            {
                graph[res].push_back(tasks[i]);
                indegree[tasks[i]]++;
            }
        }

        queue<string> q;
        for (auto &a : available)
            q.push(a);

        vector<string> result;

        while (q.size())
        {
            string task = q.front();
            q.pop();
            for (auto &it : graph[task])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    result.push_back(it);
                    q.push(it);
                }
            }
        }
        return result;
    }
};