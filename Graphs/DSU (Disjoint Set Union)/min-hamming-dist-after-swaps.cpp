// 1722. Minimize Hamming Distance After Swap Operations

// You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.

// The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).

// Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source.

// Example 1:

// Input: source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
// Output: 1
// Explanation: source can be transformed the following way:
// - Swap indices 0 and 1: source = [2,1,3,4]
// - Swap indices 2 and 3: source = [2,1,4,3]
// The Hamming distance of source and target is 1 as they differ in 1 position: index 3.
// Example 2:

// Input: source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []
// Output: 2
// Explanation: There are no allowed swaps.
// The Hamming distance of source and target is 2 as they differ in 2 positions: index 1 and index 2.
// Example 3:

// Input: source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]
// Output: 0

// Constraints:

// n == source.length == target.length
// 1 <= n <= 105
// 1 <= source[i], target[i] <= 105
// 0 <= allowedSwaps.length <= 105
// allowedSwaps[i].length == 2
// 0 <= ai, bi <= n - 1
// ai != bi

#include <bits/stdc++.h>
using namespace std;

// Approach 1: DSU + Hash Map , For each component, count source frequencies and greedily match target values
//  Time Complexity: O(n*alpha(n)) where alpha is the inverse Ackermann function which is very slow growing and for all practical purposes can be considered as a constant.)

class Solution
{
public:
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
            if (a == b)
                return;
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;

            if (rank[a] == rank[b])
                rank[a]++;
        }
    };
    int minimumHammingDistance(vector<int> &source, vector<int> &target,
                               vector<vector<int>> &allowedSwaps)
    {
        int n = source.size();
        DSU dsu;
        dsu.init(n);
        for (auto &swap : allowedSwaps)
            dsu.unionByRank(swap[0], swap[1]);
        unordered_map<int, vector<int>> swappers;
        for (int i = 0; i < n; i++)
            swappers[dsu.find(i)].push_back(i);
        int hamming = 0;
        for (auto &s : swappers)
        {
            unordered_map<int, int> freq;
            for (auto &i : s.second)
            {
                freq[source[i]]++;
            }
            for (auto &i : s.second)
            {
                if (freq[target[i]])
                    freq[target[i]]--;
                else
                    hamming++;
            }
        }
        return hamming;
    }
};

// Approach 2: DSU → components become freely rearrangeable
// Cancel frequencies (source +1, target -1), leftover positives = Hamming distance
// Remaining positive counts = minimum Hamming distance

// Time Complexity: O(n*alpha(n)) where alpha is the inverse Ackermann function which is very slow growing and for all practical purposes can be considered as a constant.)

class Solution
{
public:
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
            if (a == b)
                return;
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;

            if (rank[a] == rank[b])
                rank[a]++;
        }
    };
    int minimumHammingDistance(vector<int> &source, vector<int> &target,
                               vector<vector<int>> &allowedSwaps)
    {
        int n = source.size();
        DSU dsu;
        dsu.init(n);
        for (auto &swap : allowedSwaps)
            dsu.unionByRank(swap[0], swap[1]);
        unordered_map<int, unordered_map<int, int>> swappers;
        for (int i = 0; i < n; i++)
        {
            int root = dsu.find(i);
            swappers[root][source[i]]++;
            swappers[root][target[i]]--;
        }
        int hamming = 0;
        for (auto &swap : swappers)
        {
            for (auto &f : swap.second)
            {
                if (f.second > 0)
                    hamming += f.second;
            }
        }
        return hamming;
    }
};