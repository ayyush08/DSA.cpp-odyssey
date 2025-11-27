
// 980. Unique Paths III

// Companies
// You are given an m x n integer array grid where grid[i][j] could be:
// 1 representing the starting square. There is exactly one starting square.
// 2 representing the ending square. There is exactly one ending square.
// 0 representing empty squares we can walk over.
// -1 representing obstacles that we cannot walk over.
// Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

// Example 1:

// Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
// Output: 2
// Explanation: We have the following two paths:
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
// 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
// Example 2:

// Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
// Output: 4
// Explanation: We have the following four paths:
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
// 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
// 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
// 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
// Example 3:

// Input: grid = [[0,1],[2,0]]
// Output: 0
// Explanation: There is no path that walks over every empty square exactly once.
// Note that the starting and ending square can be anywhere in the grid.

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 20
// 1 <= m * n <= 20
// -1 <= grid[i][j] <= 2
// There is exactly one starting cell and one ending cell.

// NOTICE: We have to walk each non-obstacle cell exactly once so we can't do this problem like unique paths 1 and 2 where we just count the paths from start to end. Here we need backtracking to ensure we visit all non-obstacle cells exactly once.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ans = 0;
    int total;
    int m;
    int n;
    void func(int i, int j, vector<vector<int>> &grid, int paths)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1)
            return;

        if (grid[i][j] == 2)
        {
            if (paths == total)
                ans++;
            return;
        }
        int prev = grid[i][j];
        grid[i][j] = -1;

        func(i + 1, j, grid, paths + 1);
        func(i, j + 1, grid, paths + 1);
        func(i - 1, j, grid, paths + 1);
        func(i, j - 1, grid, paths + 1);

        grid[i][j] = prev;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        total = 1;
        int si = 0, sj = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    si = i;
                    sj = j;
                }
                else if (grid[i][j] != -1)
                    total++;
            }
        }
        func(si, sj, grid, 1);
        return ans;
    }
};

//Time Complexity: O(4^(m*n)) in worst case as from each cell we have 4 directions to explore and we may have to visit all cells.
//Space Complexity: O(m*n) for the recursion stack.