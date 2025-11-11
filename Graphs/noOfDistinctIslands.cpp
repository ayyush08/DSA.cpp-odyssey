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

// Time Complexity: O(N*M*log(N*M))
// Space Complexity: O(N*M)

// Optimal Approach: Use unordered_set with taking coordinates as string to reduce the logarithmic factor in time complexity due to ordered set.

class Solution
{
public:
    int m;
    int n;
    vector<int> dir = {0, 0, -1, 1};
    vector<int> dic = {1, -1, 0, 0};
    void dfs(int r, int c, vector<vector<int>> &grid,
             vector<vector<bool>> &visited, int br, int bc,
             string &temp)
    {
        visited[r][c] = true;
        temp += to_string(r - br) + "," + to_string(c - bc);

        for (int i = 0; i < 4; i++)
        {
            int nr = dir[i] + r;
            int nc = dic[i] + c;

            if (nr < m && nc < n && nr >= 0 && nc >= 0 && !visited[nr][nc] && grid[nr][nc] == 1)
            {
                dfs(nr, nc, grid, visited, br, bc, temp);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector(n, false));
        unordered_set<string> st;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    string rep;
                    dfs(i, j, grid, visited, i, j, rep);
                    st.insert(rep);
                }
            }
        }
        return st.size();
    }
};
