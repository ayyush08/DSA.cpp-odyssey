// Path with minimum effort
// A hiker is preparing for an upcoming hike. Given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of the cell (row, col). The hiker is situated in the top-left cell, (0, 0), and hopes to travel to the bottom-right cell, (rows-1, columns-1) (i.e.,0-indexed). He can move up, down, left, or right. He wishes to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Examples:
// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells. This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

// Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
// Output: 1
// Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

// Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
// Output:
// 2

#include <bits/stdc++.h>
using namespace std;

#define P pair<int, pair<int, int>>
class Solution
{
public:
    int MinimumEffort(vector<vector<int>> &heights)
    {
        priority_queue<P, vector<P>, greater<P>> pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};
        vector<vector<int>> maxDiff(n, vector<int>(m, 1e9));
        maxDiff[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty())
        {
            auto cell = pq.top();
            pq.pop();
            int diff = cell.first;
            int r = cell.second.first;
            int c = cell.second.second;
            if (r == n - 1 && c == m - 1)
                return diff;

            for (int i = 0; i < 4; i++)
            {
                int newRow = r + dr[i];
                int newCol = c + dc[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
                {
                    int newEffort = abs(heights[newRow][newCol] - heights[r][c]);
                    if (max(newEffort, diff) < maxDiff[newRow][newCol])
                    {
                        maxDiff[newRow][newCol] = max(newEffort, diff);
                        pq.push({max(newEffort, diff), {newRow, newCol}});
                    }
                }
            }
        }
    }
};

int main()
{
    vector<vector<int>> heights = {{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}};
    Solution obj;
    cout << obj.MinimumEffort(heights) << endl;
    return 0;
}
//Approach : We will use Dijkstra's algorithm to solve this problem. We will use a priority queue to store the cells with the minimum effort. We will keep track of the maximum difference in height between two consecutive cells in the maxDiff array. We will start from the top-left cell and keep moving to the adjacent cells. We will update the maxDiff array with the maximum difference in height between the current cell and the adjacent cell. If the row and column of the current cell are equal to the row and column of the bottom-right cell, we will return the maximum difference in height between the two cells.

//Why returning directly if there could be a chance that the bottom-right cell is reachable with less effort than the current cell?
// The answer is NOT POSSIBLE, because here we are using a min-heap that ensures that always the minimal distance path is taken, hence even though there could be a path with less effort, it will be taken care of by the min-heap and the path with the least effort will be taken along when r == n - 1 && c == m - 1 is reached. Hence, we can return the answer directly.
// Time complexity: O(m*n*log(m*n)) where m is the number of rows and n is the number of columns in the grid.