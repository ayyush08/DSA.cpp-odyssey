// 399. Evaluate Division
// You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

// You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

// Return the answers to all queries. If a single answer cannot be determined, return -1.0.

// Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

// Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

// Example 1:

// Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
// Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
// Explanation:
// Given: a / b = 2.0, b / c = 3.0
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
// return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
// note: x is undefined => -1.0
// Example 2:

// Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
// Output: [3.75000,0.40000,5.00000,0.20000]
// Example 3:

// Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
// Output: [0.50000,2.00000,-1.00000,-1.00000]

// Constraints:

// 1 <= equations.length <= 20
// equations[i].length == 2
// 1 <= Ai.length, Bi.length <= 5
// values.length == equations.length
// 0.0 < values[i] <= 20.0
// 1 <= queries.length <= 20
// queries[i].length == 2
// 1 <= Cj.length, Dj.length <= 5
// Ai, Bi, Cj, Dj consist of lower case English letters and digits.

#include <bits/stdc++.h>
using namespace std;

// Treating the variables as nodes and equations as directed edges with weights as values for, a->b value is an edge with weight 'value' and b->a value is an edge with weight '1/value'.

// Solution 1: Using BFS : O(Q * (V + E)) time complexity

class Solution
{
public:
    unordered_map<string, vector<pair<string, double>>> graph;
    void bfs(string C, string D, double &res)
    {
        unordered_set<string> visited;
        queue<pair<string, double>> q; // node,value
        q.push({C, 1.0});
        while (q.size())
        {
            string node = q.front().first;
            double prev = q.front().second;
            q.pop();
            if (node == D)
            {
                res = prev;
                break;
            }

            for (auto &it : graph[node])
            {
                string neighbour = it.first;
                double curr = it.second;
                if (!visited.count(neighbour))
                {
                    visited.insert(neighbour);
                    q.push({neighbour, curr * prev});
                }
            }
        }
    }
    void processQueries(vector<double> &ans, vector<vector<string>> &queries)
    {
        for (auto q : queries)
        {
            string C = q[0];
            string D = q[1];

            if (!graph.count(C) || !graph.count(D))
            {
                ans.push_back(-1.0);
                continue;
            }
            if (C == D)
            {
                ans.push_back(1.0);
                continue;
            }
            double res = -1.0;
            bfs(C, D, res);
            ans.push_back(res);
        }
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {

        // Build graph
        for (int i = 0; i < equations.size(); i++)
        {
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];

            graph[A].push_back({B, val});
            graph[B].push_back({A, 1.0 / val});
        }

        vector<double> ans;

        processQueries(ans, queries);
        return ans;
    }
};

// Using DFS : O(Q * (V + E)) time complexity

class Solution
{
public:
    unordered_map<string, vector<pair<string, double>>> graph;
    bool dfs(string node, string target, double &res, double val, unordered_set<string> &visited)
    {
        if (node == target)
        {
            res = val;
            return true;
        }
        visited.insert(node);

        for (auto &it : graph[node])
        {
            string neighbour = it.first;
            double curr = it.second;
            if (!visited.count(neighbour))
            {
                visited.insert(neighbour);
                if (dfs(neighbour, target, res, curr * val, visited))
                    return true;
            }
        }
        return false;
    }
    void processQueries(vector<double> &ans, vector<vector<string>> &queries)
    {
        for (auto q : queries)
        {
            string C = q[0];
            string D = q[1];

            if (!graph.count(C) || !graph.count(D))
            {
                ans.push_back(-1.0);
                continue;
            }
            if (C == D)
            {
                ans.push_back(1.0);
                continue;
            }
            double res = -1.0;
            unordered_set<string> visited;
            dfs(C, D, res, 1.0, visited);
            ans.push_back(res);
        }
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {

        // Build graph
        for (int i = 0; i < equations.size(); i++)
        {
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];

            graph[A].push_back({B, val});
            graph[B].push_back({A, 1.0 / val});
        }

        vector<double> ans;

        processQueries(ans, queries);
        return ans;
    }
};

//Using DSU (Disjoint Set Union) : O(E + Q * α(V)) time complexity - faster than BFS and DFS as here α(V) is almost constant

class Solution {
public:

    // -----------------------------
    //  DSU STRUCT (Weighted Union-Find)
    // -----------------------------
    struct DSU {
        unordered_map<string,string> parent; // parent[x] = parent of x
        unordered_map<string,double> ratio;  // ratio[x] = x / parent[x]

        // Create a new set if variable is unseen
        void makeSet(const string &x) {
            if(!parent.count(x)) {
                parent[x] = x;   // parent of itself
                ratio[x]  = 1.0; // x/x = 1
            }
        }

        // Find root of x and also compute x/root ratio
        pair<string,double> find(const string &x) {
            if(parent[x] == x)
                return {x, 1.0};

            auto p = find(parent[x]);   // find parent’s root

            parent[x] = p.first;        // path compression
            ratio[x] *= p.second;       // update x/root ratio

            return {parent[x], ratio[x]};
        }

        // Merge sets of a and b when equation a/b = val
        void merge(const string &a, const string &b, double val) {
            makeSet(a);
            makeSet(b);

            auto pa = find(a);   // root & ratio for a
            auto pb = find(b);   // root & ratio for b

            string rootA = pa.first;
            string rootB = pb.first;

            if(rootA == rootB) return;  // already connected

            /*
                Equation: a / b = val

                We know:
                   a = ratioA * rootA
                   b = ratioB * rootB

                After merge, we connect:
                    rootA -> rootB

                We want the equation to remain true mathematically:
                    (a / b) = val
                Substitute:
                   (ratioA * rootA) / (ratioB * rootB) = val

               => (rootA / rootB) = (ratioB * val) / ratioA

                So:
                   ratio[rootA] = (ratioB * val) / ratioA
            */

            parent[rootA] = rootB;
            ratio[rootA] = (pb.second * val) / pa.second;
        }
    };

    // Our DSU object
    DSU dsu;


    // -----------------------------
    // Process queries using DSU
    // -----------------------------
    void processQueries(vector<double>& ans, vector<vector<string>>& queries) {
        for(auto &q : queries) {
            string C = q[0];
            string D = q[1];

            // If either variable missing: no answer
            if(!dsu.parent.count(C) || !dsu.parent.count(D)) {
                ans.push_back(-1.0);
                continue;
            }

            auto pC = dsu.find(C);   // (rootC, C/rootC)
            auto pD = dsu.find(D);   // (rootD, D/rootD)

            if(pC.first != pD.first) {
                ans.push_back(-1.0); // not connected
            } else {
                // C / D = (C/root) / (D/root)
                ans.push_back(pC.second / pD.second);
            }
        }
    }


    // -----------------------------
    // Main solve function
    // -----------------------------
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries)
    {
        // Build DSU from equations
        for(int i = 0; i < equations.size(); i++) {
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];

            dsu.merge(A, B, val);
        }

        vector<double> ans;
        processQueries(ans, queries);
        return ans;
    }
};
