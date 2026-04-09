// 952. Largest Component Size by Common Factor
// You are given an integer array of unique positive integers nums. Consider the following graph:

// There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
// There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
// Return the size of the largest connected component in the graph.

// Example 1:

// Input: nums = [4,6,15,35]
// Output: 4
// Example 2:

// Input: nums = [20,50,9,63]
// Output: 2
// Example 3:

// Input: nums = [2,3,6,7,4,12,21,39]
// Output: 8

// Constraints:

// 1 <= nums.length <= 2 * 104
// 1 <= nums[i] <= 105
// All the values of nums are unique.

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
        if (a == b)
            return;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;

        if (rank[a] == rank[b])
            rank[a]++;
    }
};
class Solution
{
public:
    int largestComponentSize(vector<int> &nums)
    {
        int n = nums.size();
        DSU dsu;
        int maxi = *max_element(nums.begin(), nums.end());
        dsu.init(maxi);
        for (int num : nums)
        {
            for (int f = 2; f * f <= num; f++)
            {
                if (num % f == 0)
                {
                    dsu.unionByRank(num, f);
                    dsu.unionByRank(num, num / f);
                }
            }
        }
        unordered_map<int, int> size;
        for (int num : nums)
        {
            size[dsu.find(num)]++;
        }

        int ans = INT_MIN;

        for (auto &it : size)
        {
            ans = max(ans, it.second);
        }
        return ans;
    }
};