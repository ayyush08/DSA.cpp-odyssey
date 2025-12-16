// 947. Most Stones Removed with Same Row or Column

// On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

// Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

// Example 1:

// Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
// Output: 5
// Explanation: One way to remove 5 stones is as follows:
// 1. Remove stone [2,2] because it shares the same row as [2,1].
// 2. Remove stone [2,1] because it shares the same column as [0,1].
// 3. Remove stone [1,2] because it shares the same row as [1,0].
// 4. Remove stone [1,0] because it shares the same column as [0,0].
// 5. Remove stone [0,1] because it shares the same row as [0,0].
// Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
// Example 2:

// Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
// Output: 3
// Explanation: One way to make 3 moves is as follows:
// 1. Remove stone [2,2] because it shares the same row as [2,0].
// 2. Remove stone [2,0] because it shares the same column as [0,0].
// 3. Remove stone [0,2] because it shares the same row as [0,0].
// Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
// Example 3:

// Input: stones = [[0,0]]
// Output: 0
// Explanation: [0,0] is the only stone on the plane, so you cannot remove it.

// Constraints:

// 1 <= stones.length <= 1000
// 0 <= xi, yi <= 104
// No two stones are at the same coordinate point.

#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent;
    vector<int> size;
    void init(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int find(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    void unionBySize(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};
class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        int maxRow = 0, maxCol = 0;
        for (auto stone : stones)
        {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }
        DSU dsu;
        dsu.init(maxRow + maxCol + 1);
        int components = 0;
        unordered_map<int, int> uniqueNodes;
        for (auto stone : stones)
        {
            int row = stone[0];
            int col = stone[1] + maxRow + 1;

            dsu.unionBySize(row, col);
            uniqueNodes[row] = 1;
            uniqueNodes[col] = 1;
        }
        for (auto &it : uniqueNodes)
        {
            if (dsu.find(it.first) == it.first)
                components++;
        }
        return n - components;
    }
};

//Idea
// We can consider each row and column as nodes in a graph. Each stone connects a row node to a column node.
// Thus, we can use Disjoint Set Union (DSU) to group connected components of rows and columns.
// The number of stones that can be removed is equal to the total number of stones minus the number of connected components.


//Time Complexity
// O(n) + O(n*alpha(maxRow+maxCol+1)) where n is number of stones, alpha is inverse ackermann function
// Space Complexity
// O(maxRow + maxCol) due to the parent and size vectors in the DSU class, and O(n) for the unordered_map uniqueNodes.