// Furthest Empty Plot From Buildings
// Medium

// You are given a map of a city represented as a square n×n grid. Each cell in the grid is either:

// 0 representing an empty plot of land, or 1 representing a building.

// Your task is to find an empty plot of land such that the distance to the nearest building is maximized, and return this distance. If there are no buildings or no empty plots, return −1.

// The distance between two locations (x1,y1) and (x2,y2) is calculated using the Manhattan distance formula: |x1-x2|+|y1-y2|

// Example 1

// Input: grid=[[0,1,0],[0,0,0],[1,0,0]]

// Output:2

// Explanation:

// The empty plot at position (1,2) is the farthest from any building, with a distance of 2.

// Example 2

// Input: grid=[[0,0,1],[0,0,0],[0,0,1]]

// Output:3

// Explanation:

// The empty plot at position (1,0) is the farthest from any building, with a distance of 3.

// Constraints

// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int farthestEmptyPlot(vector<vector<int>> grid)
    {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        if (q.empty() || q.size() == n * n)
            return -1;
        vector<int> dir = {0, 0, -1, 1};
        vector<int> dic = {1, -1, 0, 0};
        int ans = 0;
        while (q.size())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dir[i];
                int nc = c + dic[i];
                if (nr < n && nr >= 0 && nc < n && nc >= 0 &&
                    dist[nr][nc] == -1)
                {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                    ans = max(ans, dist[nr][nc]);
                }
            }
        }
        return ans;
    }
};

//Point to Remember: Manhattan Distance can be calculated using 4 direction vectors.