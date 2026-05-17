// Q3. Largest Local Values in a Matrix II

// You are given an n x m integer matrix matrix containing non-negative integers.

// A non-zero cell (row, col) checks the cells near it as follows:

// Let x = matrix[row][col].
// Consider every cell within x rows and x columns of (row, col).
// Ignore cells that are outside the matrix. 
// Ignore the cells where both the row distance and column distance are exactly x.
// The cell (row, col) is a local maximum if it is non-zero and no considered cell has a value greater than x.

// Return an integer denoting the number of local maximums in matrix.


// ​​​​​​​Example 1:

// Input: matrix = [[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,2,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0]]

// Output: 1

// ​​​​​​​​​​​​​​​​​​​​​

// Explanation:

// For the non-zero cell (3, 3), x = matrix[3][3] = 2.
// The highlighted cells are the considered cells within x rows and x columns of (3, 3).
// The four cells with both row and column distances equal to x = 2 are ignored.
// No considered cell has a value greater than 2, so (3, 3) is a local maximum.
// There are no other non-zero cells, so the answer is 1.
// Example 2:

// Input: matrix = [[1,2],[3,4]]

// Output: 1

// Explanation:

// Only the cell with value 4 is a local maximum. Every other non-zero cell considers a cell with a greater value.

// Example 3:

// Input: matrix = [[1,0,1],[0,1,0],[1,0,1]]

// Output: 5

// Explanation:

// For a cell with value 1, the considered cells are the cell itself and its 4-directionally adjacent cells that are inside the matrix.
// Each of the five cells with value 1 only considers cells with values 0 or 1, so all five of them are local maximums.
// Example 4:

// Input: matrix = [[1,1],[1,1]]

// Output: 4

// Explanation:

// All cells have the same value. Therefore, no cell considers another cell with a greater value, so all 4 cells are local maximums.

//  

// Constraints:

// 1 <= n == matrix.length <= 200
// 1 <= m == matrix[i].length <= 200
// 0 <= matrix[i][j] <= 200

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m;
    int n;
    vector<vector<vector<int>>>prefixMaxColRange;
    bool isValidLocal(vector<vector<int>>& matrix,int r,int c){
        int x = matrix[r][c];
        int rStart = max(0,r-x);
        int cStart = max(0,c-x);

        int rEnd = min(m-1,r+x);
        int cEnd = min(n-1,c+x);
        for (int i = rStart; i <= rEnd; i++) {
            int cStart, cEnd; 
            if (abs(i - r) == x) { //shrink column range by 1 if row distance is exactly x
                cStart = max(0, c - x + 1);
                cEnd = min(n - 1, c + x - 1);
            } else { //otherwise, consider the full column range
                cStart = max(0, c - x);
                cEnd = min(n - 1, c + x);
            }
            //check if there is a value greater than x in the column range for row i
            if (cStart <= cEnd) {
                if (prefixMaxColRange[i][cStart][cEnd] > x) return false;
            }
        }
        return true;
    }
    int countLocalMaximums(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int locals = 0;
        prefixMaxColRange.assign(m, vector<vector<int>>(n, vector<int>(n, 0))); //max value for each column range for each row (reduces complexity from O(n^4) to O(n^3))
        for (int r = 0; r < m; ++r) {
            for (int c1 = 0; c1 < n; ++c1) {
                int curr = 0;
                for (int c2 = c1; c2 < n; ++c2) {
                    curr = max(curr, matrix[r][c2]);
                    prefixMaxColRange[r][c1][c2] = curr;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]){
                    if(isValidLocal(matrix,i,j)) locals++;
                }
            }
        }
        return locals;
    }
};