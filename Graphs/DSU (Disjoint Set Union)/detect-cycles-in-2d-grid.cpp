// 1559. Detect Cycles in 2D Grid

// Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.

// A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.

// Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

// Return true if any cycle of the same value exists in grid, otherwise, return false.

// Example 1:

// Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
// Output: true
// Explanation: There are two valid cycles shown in different colors in the image below:

// Example 2:

// Input: grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
// Output: true
// Explanation: There is only one valid cycle highlighted in the image below:

// Example 3:

// Input: grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
// Output: false

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 500
// grid consists only of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

//Approach 1: DFS

class Solution {
public:
    int m;
    int n;
    vector<vector<bool>> visited;
    vector<int> dir = {0, 0, -1, 1};
    vector<int> dic = {1, -1, 0, 0};
    bool dfs(int r, int c, vector<vector<char>>& grid, int parentX,
             int parentY) {
        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = dir[i] + r;
            int nc = dic[i] + c;

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;
            //mismatch
            if (grid[nr][nc] != grid[r][c])
                continue;
            //unexplored path
            if(!visited[nr][nc]){
                if(dfs(nr,nc,grid,r,c)) return true;
            }
            //if already explored but is different from parent -> cycle found
            else if(nr==parentX && nc==parentY) continue;
            else if(visited[nr][nc]) return true;
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(!visited[i][j]){
                if (dfs(i, j, grid, -1, -1)) return true;
                }
            }
        }
        return false;
    }
};

// Time Complexity: O(m*n) where m and n are the number of rows and columns in the grid respectively. Each cell is visited at most once.
// Space Complexity: O(m*n) in the worst case, when all cells are visited and the recursion stack can go as deep as m*n.

// Approach 2: BFS (Similar to DFS, but uses a queue instead of recursion)

// Aprroach 3: DSU (Disjoint Set Union)

class Solution {
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
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        DSU dsu;

        dsu.init(m*n);

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                int currNode = r*n+c;
                if(c+1<n && grid[r][c]==grid[r][c+1]){
                    int adjNode = r*n+(c+1);
                    if(dsu.find(currNode)==dsu.find(adjNode)) return true; 
                    dsu.unionByRank(currNode,adjNode);
                }
                if(r+1<m && grid[r][c]==grid[r+1][c]){
                    int adjNode = (r+1)*n+c;
                    if(dsu.find(currNode)==dsu.find(adjNode)) return true; 
                    dsu.unionByRank(currNode,adjNode);
                }
            }
        }
        return false;
    }
};
// Time Complexity: O(m*n*α(m*n)) where m and n are the number of rows and columns in the grid respectively, and α is the inverse Ackermann function which is very slow growing and for all practical purposes can be considered as a constant.
// Space Complexity: O(m*n) in the worst case, when all cells are in different
