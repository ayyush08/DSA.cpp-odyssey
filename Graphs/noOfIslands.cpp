// Number of islands
// Given a grid of size N x M (N is the number of rows and M is the number of columns in the grid) consisting of '0's (Water) and ‘1's(Land). Find the number of islands.
//An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// Example 1
// Input: grid = [ ["1", "1", "1", "0", "1"], ["1", "0", "0", "0", "0"], ["1", "1", "1", "0", "1"], ["0", "0", "0", "1", "1"] ]
// Output: 2
// Explanation: This grid contains 2 islands. Each '1' represents a piece of land, and the islands are formed by connecting adjacent lands horizontally or vertically. Despite some islands having a common edge, they are considered separate islands because there is no land connectivity in any of the eight directions between them. Therefore, the grid contains 2 islands.

// Example 2
// Input: grid = [ ["1", "0", "0", "0", "1"], ["0", "1", "0", "1", "0"], ["0", "0", "1", "0", "0"], ["0", "1", "0", "1"," 0"] ]
// Output: 1
// Explanation: In the given grid, there's only one island as all the '1's are connected either horizontally, vertically, or diagonally, forming a single contiguous landmass surrounded by water on all sides.

#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void bfs(int row,int col,vector<vector<int>>& visited,vector<vector<char>>& grid){
        visited[row][col]=1;
        queue<pair<int,int>>q;
        q.push ({row,col});
        int m=grid.size();
        int n=grid[0].size();
        while(!q.empty()){
            int currentRow = q.front().first;
            int currentColumn = q.front().second;
            q.pop();
            for(int neighRow=-1;neighRow<=1;neighRow++){
                for(int  neighCol=-1;neighCol<=1;neighCol++){
                    int newRow=currentRow+neighRow;
                    int newCol = currentColumn+neighCol;
                    if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && grid[newRow][newCol]=='1' && !visited[newRow][newCol]){
                        visited[newRow][newCol]=1;
                        q.push({newRow,newCol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int island=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    island++;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return island;
    }
};

int main(){
    vector<vector<char>> grid={{'1', '1', '1', '0', '1'}, {'1', '0', '0', '0', '0'}, {'1', '1', '1', '0', '1'}, {'0', '0', '0', '1', '1'}};
    Solution obj;
    cout<<obj.numIslands(grid)<<endl;
    return 0;
}