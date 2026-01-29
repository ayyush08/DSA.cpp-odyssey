// 2976. Minimum Cost to Convert String I
// You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

// You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

// Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

// Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

// Example 1:

// Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
// Output: 28
// Explanation: To convert the string "abcd" to string "acbe":
// - Change value at index 1 from 'b' to 'c' at a cost of 5.
// - Change value at index 2 from 'c' to 'e' at a cost of 1.
// - Change value at index 2 from 'e' to 'b' at a cost of 2.
// - Change value at index 3 from 'd' to 'e' at a cost of 20.
// The total cost incurred is 5 + 1 + 2 + 20 = 28.
// It can be shown that this is the minimum possible cost.
// Example 2:

// Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
// Output: 12
// Explanation: To change the character 'a' to 'b' change the character 'a' to 'c' at a cost of 1, followed by changing the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3. To change all occurrences of 'a' to 'b', a total cost of 3 * 4 = 12 is incurred.
// Example 3:

// Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
// Output: -1
// Explanation: It is impossible to convert source to target because the value at index 3 cannot be changed from 'd' to 'e'.

// Constraints:

// 1 <= source.length == target.length <= 105
// source, target consist of lowercase English letters.
// 1 <= cost.length == original.length == changed.length <= 2000
// original[i], changed[i] are lowercase English letters.
// 1 <= cost[i] <= 106
// original[i] != changed[i]

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using Floyd-Warshall Algorithm (Good for small test cases)
class Solution
{
public:
    const int INF = 1e9;
    long long minimumCost(string source, string target, vector<char> &original,
                          vector<char> &changed, vector<int> &cost)
    {
        vector<vector<long long>> matrix(26, vector<long long>(26, INF));

        for (int i = 0; i < 26; i++)
            matrix[i][i] = 0;

        for (int i = 0; i < original.size(); i++)
        {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            matrix[from][to] = (long long)min(matrix[from][to], 1LL * cost[i]); // Update with minimum cost
        }

        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (matrix[i][k] == INF || matrix[k][j] == INF)
                        continue;
                    if (matrix[i][j] == INF)
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]); // floyd-warshall
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < source.size(); i++)
        {
            int from = source[i] - 'a';
            int to = target[i] - 'a';
            if (matrix[from][to] == INF) // impossible to convert
                return -1;
            ans += matrix[from][to];
        }
        return ans;
    }
};

// Time Complexity: O(26^3 + n) where n is the length of source/target strings.
// Space Complexity: O(26^2) for the adjacency matrix.

// Approach 2: Using Dijkstra's Algorithm (Efficient for larger test cases)

class Solution
{
public:
    typedef pair<int, int> P;
    const int INF = 1e9;
    vector<long long> dijkstra(vector<vector<P>> &adj, int src)
    {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, src});
        vector<long long> dist(adj.size(), INF);
        dist[src] = 0;
        while (pq.size())
        {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto &it : adj[node])
            {
                int adjNode = it.first;
                int adjCost = it.second;
                if (dist[adjNode] > cost + adjCost)
                {
                    dist[adjNode] = cost + adjCost;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        int n = original.size();
        vector<vector<P>> adj(26);

        for (int i = 0; i < n; i++)
        {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adj[u].push_back({v, cost[i]});
        }

        unordered_map<int, vector<long long>> visited;
        long long ans = 0;
        for (int i = 0; i < source.size(); i++)
        {
            int from = source[i] - 'a';
            int to = target[i] - 'a';
            if (!visited.count(from))
                visited[from] = dijkstra(adj, from);

            if (visited[from][to] == INF)
                return -1;
            ans += visited[from][to];
        }
        return ans;
    }
};
//Time Complexity: O(n + k * (E + 26) log 26) where k is the number of unique characters in source, E is the number of edges and V is 26.
//Space Complexity: O(V^2) for storing shortest paths for each unique character in source