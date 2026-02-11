// 1162. As Far from Land as Possible
// Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

// The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

// Example 1:

// Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
// Output: 2
// Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
// Example 2:

// Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
// Output: 4
// Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    vector<int> dir = {-1, 1, 0, 0};
    vector<int> dic = {0, 0, 1, -1};
    int maxDistance(vector<vector<int>> &grid)
    {
        n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        if (q.empty() || q.size() == n * n)
            return -1;
        int ans = -1e9;
        while (q.size())
        {
            auto cell = q.front();
            q.pop();
            int x = cell.first;
            int y = cell.second;
            for (int i = 0; i < 4; i++)
            {
                int nx = dir[i] + x;
                int ny = dic[i] + y;
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && dist[nx][ny] == -1)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    ans = max(ans, dist[nx][ny]);
                    q.push({nx, ny});
                }
            }
        }
        return ans;
    }
};
//Time Complexity: O(n^2)
//Space Complexity: O(n^2)