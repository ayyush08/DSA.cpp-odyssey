// Rat in a Maze

// Given a grid of dimensions n x n. A rat is placed at coordinates (0, 0) and wants to reach at coordinates (n-1, n-1).
// Find all possible paths that rat can take to travel from (0, 0) to (n-1, n-1). The directions in which rat can move are 'U' (up) , 'D' (down) , 'L' (left) , 'R' (right).
// The value 0 in grid denotes that the cell is blocked and rat cannot use that cell for travelling, whereas value 1 represents that rat can travel through the cell. If the cell (0, 0) has 0 value, then mouse cannot move to any other cell.

// Note :
// In a path no cell can be visited more than once.
// If there is no possible path then return empty vector.

// Examples:
// Input : n = 4 , grid = [ [1, 0, 0, 0] , [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1] ]
// Output : [ "DDRDRR" , "DRDDRR" ]
// Explanation : The rat has two different path to reach (3, 3).
// The first path is (0, 0) => (1, 0) => (2, 0) => (2, 1) => (3, 1) => (3, 2) => (3, 3).
// The second path is (0,0) => (1,0) => (1,1) => (2,1) => (3,1) => (3,2) => (3,3).

// Input : n = 2 , grid = [ [1, 0] , [1, 0] ]
// Output : -1
// Explanation : There is no path that rat can choose to travel from (0,0) to (1,1).

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void func(vector<string> &ans, vector<vector<int>> &grid, int i, int j,
              string path) {
        if (i == grid.size() - 1 && j == grid.size() - 1) {
            ans.push_back(path);
            return;
        }

        if (grid[i][j] == 0) return;
        grid[i][j] = 0;

        if (i > 0) func(ans, grid, i - 1, j, path + "U");
        if (j > 0) func(ans, grid, i, j - 1,path + "L");
        if (i < grid.size() - 1) func(ans, grid, i + 1, j, path+"D");
        if (j < grid.size() - 1) func(ans, grid, i, j + 1, path+"R");

        grid[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &grid) {
        vector<string> ans;

        if (grid[0][0] == 0 || grid[grid.size() - 1][grid.size() - 1] == 0)
            return ans;

        func(ans, grid, 0, 0, "");

        return ans;
    }
};

// Time Complexity : The time complexity is O(4^(N^2)) due to recursion exploring all paths in the grid.

// Space Complexity :The space complexity is O(N^2) for the recursion stack and result storage.