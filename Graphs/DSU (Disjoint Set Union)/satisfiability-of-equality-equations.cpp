// 990. Satisfiability of Equality Equations

// You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

// Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

// Example 1:

// Input: equations = ["a==b","b!=a"]
// Output: false
// Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
// There is no way to assign the variables to satisfy both equations.
// Example 2:

// Input: equations = ["b==a","a==b"]
// Output: true
// Explanation: We could assign a = 1 and b = 1 to satisfy both equations.

// Constraints:

// 1 <= equations.length <= 500
// equations[i].length == 4
// equations[i][0] is a lowercase letter.
// equations[i][1] is either '=' or '!'.
// equations[i][2] is '='.
// equations[i][3] is a lowercase letter.

#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent;
    vector<int> rank;
    void init(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
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
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};
class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        DSU dsu;
        dsu.init(26);

        for (string eq : equations)
        {
            if (eq[1] == '=')
            {
                dsu.unionByRank(eq[0] - 'a', eq[3] - 'a');
            }
        }

        for (string eq : equations)
        {
            if (eq[1] == '!' && dsu.find(eq[0] - 'a') == dsu.find(eq[3] - 'a'))
                return false;
        }
        return true;
    }
};