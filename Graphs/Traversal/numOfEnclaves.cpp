// Number of enclaves
// Given an N x M binary matrix grid, where 0 represents a sea cell and 1 represents a land cell. A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid. Find the number of land cells in the grid for which we cannot walk off the boundary of the grid in any number of moves.


// Example 1
// Input: grid = [[0, 0, 0, 0], [1, 0, 1, 0], [0, 1, 1, 0], [0, 0, 0, 0]]
// Output: 3

// Example 2
// Input: grid = [[0, 0, 0, 1],[0, 0, 0, 1], [0, 1, 1, 0], [0, 0, 1, 0], [0, 0, 0, 0]]
// Output:3

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int r = grid.size();
        int c = grid[0].size();
        int visited[r][c]={0};
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if((i==0 || j==0 || i==r-1 || j==c-1) && grid[i][j]==1){
                    visited[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        vector<int> dir = {-1, 1, 0, 0};
        vector<int> dic = {0, 0, -1, 1};
        while(!q.empty()){
            int frontRow = q.front().first;
            int frontCol = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newRow=frontRow+dir[i];
                int newCol = frontCol+dic[i];
                if(newRow>=0 && newRow<r && newCol>=0 && newCol<c){
                    if(grid[newRow][newCol]==1 && visited[newRow][newCol]==0){
                        visited[newRow][newCol]=1;
                        q.push({newRow,newCol});
                    }
                }
            }
        }
        int enclaves=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1 && visited[i][j]==0) enclaves++;
            }
        }
        return enclaves;
    }
};

int main(){
    vector<vector<int>> grid={{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    Solution obj;
    cout<<obj.numberOfEnclaves(grid)<<endl;
    return 0;
}