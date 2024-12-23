// Surrounded Regions
//  Given a matrix mat of size N x M where every element is either ‘O’ or ‘X’. Replace all ‘O’ with ‘X’ that is surrounded by ‘X’. An ‘O’ (or a set of ‘O’) is considered to be surrounded by ‘X’ if there are ‘X’ at locations just below, above, left, and right of it.

// Example 1
// Input: mat = [ ["X", "X", "X", "X"], ["X", "O", "O", "X"], ["X", "X", "O", "X"], ["X", "O", "X", "X"] ]
// Output: [ ["X", "X", "X", "X"], ["X", "X", "X", "X"], ["X", "X", "X", "X"], ["X", "O", "X", "X"] ]
// Explanation:
// The 'O' cells at positions (1,1), (1,2), (2,2), and (3,1) are surrounded by 'X' cells in all directions (horizontally and vertically).
// However, the 'O' region at (3,1) is adjacent to an edge of the board, so it cannot be completely surrounded by 'X' cells. Therefore, it remains unchanged.

// Example 2
// Input: mat = [ ["X", "X", "X"], ["X", "O", "X"], ["X", "X", "X"] ]
// Output: [ ["X", "X", "X"], ["X", "O", "X"], ["X", "X", "X"] ]
// Explanation: The only 'O' cell at position (1,1) is completely surrounded by 'X' cells in all directions (horizontally and vertically). Hence, it is replaced with 'X' in the output.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(int r, int c, vector<vector<int>> &visited,
             vector<vector<char>> &board)
    {
        vector<int> dir = {-1, 1, 0, 0};
        vector<int> dic = {0, 0, 1, -1};
        visited[r][c] = 1;
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nRow = r + dir[i];
            int nCol = c + dic[i];
            if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols && board[nRow][nCol] == 'O' && !visited[nRow][nCol])
            {
                dfs(nRow, nCol, visited, board);
            }
        }
    }

public:
    vector<vector<char>> fill(vector<vector<char>> board)
    {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        for (int j = 0; j < cols; j++)
        {
            if (!visited[0][j] && board[0][j] == 'O')
                dfs(0, j, visited, board);
            if (!visited[rows - 1][j] && board[rows - 1][j] == 'O')
                dfs(rows - 1, j, visited, board);
        }
        for (int i = 0; i < rows; i++)
        {
            if (!visited[i][0] && board[i][0] == 'O')
                dfs(i, 0, visited, board);
            if (!visited[i][cols - 1] && board[i][cols - 1] == 'O')
                dfs(i, cols - 1, visited, board);
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        return board;
    }
};

int main()
{
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    Solution obj;
    vector<vector<char>> ans = obj.fill(board);
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