// Distance of nearest cell having one
// Given a binary grid of N x M. Find the distance of the nearest 1 in the grid for each cell.
// The distance is calculated as |i1 - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.

// Example 1
// Input: grid = [ [0, 1, 1, 0], [1, 1, 0, 0], [0, 0, 1, 1] ]
// Output: [ [1, 0, 0, 1], [0, 0, 1, 1], [1, 1, 0, 0] ]
// Explanation: 0's at (0,0), (0,3), (1,2), (1,3), (2,0) and (2,1) are at a distance of 1 from 1's at (0,1),(0,2), (0,2), (2,3), (1,0) and (1,1) respectively.

// Example 2
// Input: grid = [ [1, 0, 1], [1, 1, 0], [1, 0, 0] ]
// Output: [ [0, 1, 0], [0, 0, 1], [0, 1, 2] ]
// Explanation: 0's at (0,1), (1,2), (2,1) and (2,2) are at a distance of 1, 1, 1 and 2 from 1's at (0,0),(0,2), (2,0) and (1,1) respectively.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(columns, 0));
        vector<vector<int>> dist(rows, vector<int>(columns, 0));
        queue<pair<pair<int, int>, int>> q;
        vector<int> dir = {-1, 1, 0, 0};
        vector<int> dic = {0, 0, 1, -1};
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int s = q.front().second;
            q.pop();
            dist[r][c] = s;
            for (int i = 0; i < 4; i++)
            {
                int nRow = r + dir[i];
                int nCol = c + dic[i];
                if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < columns &&
                    visited[nRow][nCol] == 0)
                {
                    visited[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, s + 1});
                }
            }
        }
        return dist;
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}};
    Solution obj;
    vector<vector<int>> ans = obj.nearest(grid);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}