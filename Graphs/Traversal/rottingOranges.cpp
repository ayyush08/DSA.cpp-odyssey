// Rotten Oranges
// Given an n x m grid, where each cell has the following values :
// 2 - represents a rotten orange
// 1 - represents a Fresh orange
// 0 - represents an Empty Cell
// Every minute, if a fresh orange is adjacent to a rotten orange in 4-direction ( upward, downwards, right, and left ) it becomes rotten.
// Return the minimum number of minutes required such that none of the cells has a Fresh Orange. If it's not possible, return -1.

// Example 1
// Input: grid = [ [2, 1, 1] , [0, 1, 1] , [1, 0, 1] ]
// Output: -1
// Explanation: Orange at (3,0) cannot be rotten.

// Example 2
// Input: grid = [ [2,1,1] , [1,1,0] , [0,1,1] ]
// Output: 4

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int columns = grid[0].size();
        int visited[rows][columns];
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else
                {
                    visited[i][j] = 0;
                }
            }
        }
        int rottingTime = 0;
        vector<int> dir = {-1, 1, 0, 0};
        vector<int> dic = {0, 0, 1, -1};
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            q.pop();
            rottingTime = max(time, rottingTime);
            for (int i = 0; i < 4; i++)
            {
                int newRow = r + dir[i];
                int newCol = c + dic[i];
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < columns && grid[newRow][newCol] == 1 && visited[newRow][newCol] != 2)
                {
                    q.push({{newRow, newCol}, time + 1});
                    visited[newRow][newCol] = 2;
                }
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == 0)
                    return -1;
            }
        }
        return rottingTime;
    }
};

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    Solution obj;
    cout << obj.orangesRotting(grid) << endl;
    return 0;
}