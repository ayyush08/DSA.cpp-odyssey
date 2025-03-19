// Shortest Distance in a Binary Maze
// Given an n x m matrix grid where each cell contains either 0 or 1, determine the shortest distance between a source cell and a destination cell. You can move to an adjacent cell (up, down, left, or right) if that adjacent cell has a value of 1. The path can only be created out of cells containing 1. If the destination cell is not reachable from the source cell, return -1.

// Examples:
// Input: grid = [[1, 1, 1, 1],[1, 1, 0, 1],[1, 1, 1, 1],[1, 1, 0, 0],[1, 0, 0, 1]], source = [0, 1], destination = [2, 2]
// Output: 3
// Explanation: The shortest path from (0, 1) to (2, 2) is:
// Move down to (1, 1)
// Move down to (2, 1)
// Move right to (2, 2)
// Thus, the shortest distance is 3

// Input: grid = [[1, 1, 1, 1, 1],[1, 1, 1, 1, 1],[1, 1, 1, 1, 0],[1, 0, 1, 0, 1]], source = [0, 0], destination = [3, 4]
// Output: -1
// Explanation:
// Since, there is no path possible between the source cell and the destination cell, hence we return -1.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        if (source.first == destination.first && source.second == destination.second)
            return 0;
        queue<pair<int, pair<int, int>>> q = {};
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});
        while (!q.empty())
        {
            auto cell = q.front();
            q.pop();
            int r = cell.second.first;
            int c = cell.second.second;
            int dis = cell.first;
            for (int i = 0; i < 4; i++)
            {
                int newRow = r + dr[i];
                int newCol = c + dc[i];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && (dis + 1 < dist[newRow][newCol]) && grid[newRow][newCol] == 1)
                {
                    dist[newRow][newCol] = dis + 1;
                    if (newRow == destination.first && newCol == destination.second)
                    {
                        return dis + 1;
                    }
                    q.push({dis + 1, {newRow, newCol}});
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 1, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}, {1, 0, 0, 1}};
    pair<int, int> source = {0, 1};
    pair<int, int> destination = {2, 2};
    Solution obj;
    cout << obj.shortestPath(grid, source, destination) << endl;
    return 0;
}
// Approach: Use Dijsktra's algorithm but instead of using a priority queue, use a normal queue. The reason is that we are using BFS to find the shortest path. We will keep track of the distance of each cell from the source cell. We will keep updating the distance of each cell from the source cell. If we reach the destination cell, we will return the distance of the destination cell from the source cell. If we are unable to reach the destination cell, we will return -1. The time complexity of this approach is O(m*n) where m is the number of rows and n is the number of columns in the grid. The space complexity of this approach is O(m*n) where m is the number of rows and n is the number of columns in the grid.