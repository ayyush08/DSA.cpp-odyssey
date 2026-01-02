// 1970. Last Day Where You Can Still Cross
// There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.

// Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

// You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

// Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.

// Example 1:

// Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
// Output: 2
// Explanation: The above image depicts how the matrix changes each day starting from day 0.
// The last day where it is possible to cross from top to bottom is on day 2.
// Example 2:

// Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
// Output: 1
// Explanation: The above image depicts how the matrix changes each day starting from day 0.
// The last day where it is possible to cross from top to bottom is on day 1.
// Example 3:

// Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
// Output: 3
// Explanation: The above image depicts how the matrix changes each day starting from day 0.
// The last day where it is possible to cross from top to bottom is on day 3.

// Constraints:

// 2 <= row, col <= 2 * 104
// 4 <= row * col <= 2 * 104
// cells.length == row * col
// 1 <= ri <= row
// 1 <= ci <= col
// All the values of cells are unique.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int r;
    int c;
    vector<int> dir = {0, 0, -1, 1};
    vector<int> dic = {1, -1, 0, 0};
    bool dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= r || j >= c || grid[i][j])
            return false;
        if (i == r - 1)
            return true;
        grid[i][j] = 1;
        for (int k = 0; k < 4; k++)
        {
            int nr = i + dir[k];
            int nc = j + dic[k];

            if (dfs(grid, nr, nc))
                return true;
        }
        return false;
    }
    bool canCross(int mid, vector<vector<int>> &cells)
    {
        vector<vector<int>> grid(r, vector<int>(c));

        for (int i = 0; i <= mid; ++i)
        {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;

            grid[r][c] = 1;
        }

        for (int j = 0; j < c; j++)
        {
            if (grid[0][j] == 0 && dfs(grid, 0, j))
            {
                return true;
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        r = row;
        c = col;

        int low = 0;
        int high = cells.size() - 1;
        int lastDay = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (canCross(mid, cells))
            {
                lastDay = mid + 1;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return lastDay;
    }
};

// similarly in bfs

// Approach 2: Using DSU - Take two supreme papa, one for top row and one for bottom row, connect all land cells from last day to first day, when both papa are connected, return that day.

class Solution
{
public:
    struct DSU
    {
        vector<int> parent;
        vector<int> rank;
        void init(int n)
        {
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }
        int find(int node)
        {
            if (parent[node] == node)
                return node;
            return parent[node] = find(parent[node]);
        }
        void unionByRank(int a, int b)
        {
            a = find(a);
            b = find(b);
            if (a == b)
                return;
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    };
    bool isValid(int r, int c, int m, int n)
    {
        return r >= 0 && r < m && c >= 0 && c < n;
    }
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        DSU dsu;
        int n = row * col;
        dsu.init(n + 1);
        int topPapa = n;
        int bottomPapa = n + 1;
        vector<vector<int>> grid(row, vector<int>(col, 0));
        vector<int> dir = {-1, 1, 0, 0};
        vector<int> dic = {0, 0, 1, -1};

        for (int i = cells.size() - 1; i >= 0; i--)
        {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            ;

            grid[r][c] = 1; // add land
            int id = r * col + c;

            for (int k = 0; k < 4; k++)
            {
                int nr = r + dir[k];
                int nc = c + dic[k];
                if (isValid(nr, nc, row, col) && grid[nr][nc])
                {
                    dsu.unionByRank(id, nr * col + nc);
                }
            }
            if (r == 0)
                dsu.unionByRank(id, topPapa);
            if (r == row - 1)
                dsu.unionByRank(id, bottomPapa);

            if (dsu.find(topPapa) == dsu.find(bottomPapa))
                return i;
        }
        return 0;
    }
};