// 827. Making A Large Island

// You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

// Return the size of the largest island in grid after applying this operation.

// An island is a 4-directionally connected group of 1s.

// Example 1:

// Input: grid = [[1,0],[0,1]]
// Output: 3
// Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
// Example 2:

// Input: grid = [[1,1],[1,0]]
// Output: 4
// Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
// Example 3:

// Input: grid = [[1,1],[1,1]]
// Output: 4
// Explanation: Can't change any 0 to 1, only one island with area = 4.

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 500
// grid[i][j] is either 0 or 1.

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
    vector<int> dir = {-1, 1, 0, 0};
    vector<int> dic = {0, 0, 1, -1};
    bool isValid(int r, int c, int n)
    {
        return r >= 0 && r < n && c >= 0 && c < n;
    }
    void addGivenIslands(vector<vector<int>> &grid, DSU &dsu, int n, bool &hasZero)
    {
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (!grid[r][c])
                {
                    if (!hasZero)
                        hasZero = true;
                    continue;
                }

                for (int i = 0; i < 4; i++)
                {
                    int nr = r + dir[i];
                    int nc = c + dic[i];
                    if (isValid(nr, nc, n) && grid[nr][nc])
                    {
                        int currNode = r * n + c;
                        int adjNode = nr * n + nc;
                        dsu.unionBySize(currNode, adjNode);
                    }
                }
            }
        }
    }
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();

        DSU dsu;
        dsu.init(n * n);
        bool hasZero = false;

        addGivenIslands(grid, dsu, n, hasZero);
        if (!hasZero)
            return n * n;

        int ans = 0;
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (grid[r][c])
                    continue;
                set<int> components;
                for (int i = 0; i < 4; i++)
                {
                    int nr = r + dir[i];
                    int nc = c + dic[i];
                    if (isValid(nr, nc, n) && grid[nr][nc])
                    {
                        int adjNode = nr * n + nc;
                        //avoid adding same component multiple times
                        components.insert(dsu.find(adjNode));
                    }
                }
                int totalSize = 0;
                for (int component : components)
                    totalSize += (dsu.size[component]);
                ans = max(ans, totalSize + 1);
            }
        }
        // maybe all 1?
        //  for(int cell=0;cell<n*n;cell++){
        //      ans = max(ans,dsu.size[dsu.find(cell)]);
        //  }
        return ans;
    }
};
// Time Complexity:O(n^2 * α(n)), where α(n) is the inverse Ackermann function, which grows very slowly, and can be considered O(1) for practical purposes. The dominant operations are the nested loops iterating through the grid and the unionBySize operations within the loops.
// Space Complexity:O(n^2) due to the parent and size vectors in the DSU data structure, which store information for each cell in the grid