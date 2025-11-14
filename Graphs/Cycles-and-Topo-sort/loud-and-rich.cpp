// 851. Loud and Rich

// There is a group of n people labeled from 0 to n - 1 where each person has a different amount of money and a different level of quietness.

// You are given an array richer where richer[i] = [ai, bi] indicates that ai has more money than bi and an integer array quiet where quiet[i] is the quietness of the ith person. All the given data in richer are logically correct (i.e., the data will not lead you to a situation where x is richer than y and y is richer than x at the same time).

// Return an integer array answer where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]) among all people who definitely have equal to or more money than the person x.

// Example 1:

// Input: richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
// Output: [5,5,2,5,4,5,6,7]
// Explanation:
// answer[0] = 5.
// Person 5 has more money than 3, which has more money than 1, which has more money than 0.
// The only person who is quieter (has lower quiet[x]) is person 7, but it is not clear if they have more money than person 0.
// answer[7] = 7.
// Among all people that definitely have equal to or more money than person 7 (which could be persons 3, 4, 5, 6, or 7), the person who is the quietest (has lower quiet[x]) is person 7.
// The other answers can be filled out with similar reasoning.
// Example 2:

// Input: richer = [], quiet = [0]
// Output: [0]

// Constraints:

// n == quiet.length
// 1 <= n <= 500
// 0 <= quiet[i] < n
// All the values of quiet are unique.
// 0 <= richer.length <= n * (n - 1) / 2
// 0 <= ai, bi < n
// ai != bi
// All the pairs of richer are unique.
// The observations in richer are all logically consistent.

#include <bits/stdc++.h>
using namespace std;

// make DAG from rich->poor and apply topo sort to propagate minimum quiet value to all reachable nodes

class Solution
{
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
        int V = quiet.size();
        vector<vector<int>> adj(V);
        vector<int> inDegree(V, 0);
        vector<int> ans(V);
        for (int i = 0; i < V; i++)
            ans[i] = i;
        queue<int> q;
        for (auto rich : richer)
        {
            adj[rich[0]].push_back(rich[1]);
            inDegree[rich[1]]++;
        }
        for (int d = 0; d < V; d++)
        {
            if (inDegree[d] == 0)
                q.push(d);
        }

        while (q.size())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (quiet[ans[node]] < quiet[ans[it]])
                    ans[it] = ans[node];
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
        return ans;
    }
};

// Time Complexity: O(V + E) where V is the number of people and E is the number of richer relationships.
// Space Complexity: O(V + E) for the adjacency list and other data structures used.

// DFS Approach : For each node, get the richest person with the least quiet value in its reachable nodes using DFS with memoization

class Solution2
{
public:
    int dfs(int node, vector<vector<int>> &adj, vector<int> &ans, vector<int> &quiet)
    {
        if (ans[node] != -1)
            return ans[node];
        int leastQuiet = node;
        for (auto it : adj[node])
        {
            int quieter = dfs(it, adj, ans, quiet); // recusively check the richer quitest person
            if (quiet[quieter] < quiet[leastQuiet])
                leastQuiet = quieter;
        }
        return ans[node] = leastQuiet;
    }
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
        int V = quiet.size();
        vector<int> ans(V, -1);
        vector<vector<int>> adj(V);
        for (auto r : richer)
        {
            adj[r[1]].push_back(r[0]);
        }
        for (int i = 0; i < V; i++)
            dfs(i, adj, ans, quiet);
        return ans;
    }
};