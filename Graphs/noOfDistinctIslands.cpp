// Number of distinct islands
// Given a boolean 2D matrix grid of size N x M. Find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is equal to another (not rotated or reflected).

// Example 1
// Input: grid = [[1, 1, 0, 0, 0], [1, 1, 0, 0, 0], [0, 0, 0, 1, 1],[0, 0, 0, 1, 1]]
// Output: 1
// Explanation:
// Same colored islands are equal. We have 2 equal islands, so we have only 1 distinct island.

// Example 2
// Input: grid = [[1, 1, 0, 1, 1], [1, 0, 0, 0, 0], [0, 0, 0, 0, 1],[1, 1, 0, 1, 1]]
// Output: 3
// Explanation:
// Same colored islands are equal. We have 4 islands, but 2 of them are equal, So we have 3 distinct islands..

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(int row, int col, vector<pair<int, int>> &dist,
             vector<vector<int>> &grid, vector<vector<int>> &visited, int base_row, int base_col)
    {
        visited[row][col] = 1;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dir = {-1, 1, 0, 0};
        vector<int> dic = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dir[i];
            int newCol = col + dic[i];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                !visited[newRow][newCol] && grid[newRow][newCol] == 1)
            {
                dist.push_back({newRow - base_row, newCol - base_col});
                dfs(newRow, newCol, dist, grid, visited, base_row, base_col);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        set<vector<pair<int, int>>> islands;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    vector<pair<int, int>> dist;
                    dfs(i, j, dist, grid, visited, i, j);
                    islands.insert(dist);
                }
            }
        }
        return islands.size();
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}};
    Solution obj;
    cout << obj.countDistinctIslands(grid) << endl;
    return 0;
}