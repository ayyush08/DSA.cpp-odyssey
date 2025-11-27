// Word Search

// Given a grid of n x m dimension grid of characters board and a string word.The word can be created by assembling the letters of successively surrounding cells, whether they are next to each other vertically or horizontally. It is forbidden to use the same letter cell more than once.

// Return true if the word exists in the grid otherwise false.

// Examples:
// Input : board = [ ["A", "B", "C", "E"] , ["S" ,"F" ,"C" ,"S"] , ["A", "D", "E", "E"] ] , word = "ABCCED"

// Output : true

// Input : board = [["A", "B", "C", "E"] , ["S", "F", "C", "S"] , ["A", "D", "E", "E"]] , word = "SEE"

// Output : true

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(vector<vector<char>> &board, string word, int i, int j, int k)
    {
        if (k == word.size())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            word[k] != board[i][j])
            return false;

        char c = board[i][j];
        board[i][j] = ' '; // mark as visited
        bool ans = false;
        // check all four directions
        ans |= check(board, word, i + 1, j, k + 1);
        ans |= check(board, word, i - 1, j, k + 1);
        ans |= check(board, word, i, j + 1, k + 1);
        ans |= check(board, word, i, j - 1, k + 1);

        board[i][j] = c; // unmark the cell for backtracking

        return ans;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    if (check(board, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
};

// Time Complexity : O(N * M * 4^L) where N is rows, M is columns and L is the word length; recursive search through board.

// Space Complexity : O(L) due to recursive call stack depth, where L is the length of the word.

// Code 2

class Solution
{
public:
    int m;
    int n;
    vector<int> dir = {-1, 1, 0, 0};
    vector<int> dic = {0, 0, 1, -1};
    bool isValid(int i, int j)
    {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
    bool func(int r, int c, vector<vector<char>> &board, int wid, string &word, vector<vector<bool>> &visited)
    {
        if (visited[r][c] || board[r][c] != word[wid])
            return false;
        if (wid == word.size() - 1)
            return true;
        visited[r][c] = true;
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dir[i];
            int nc = c + dic[i];
            if (isValid(nr, nc))
            {
                if (func(nr, nc, board, wid + 1, word, visited))
                    return true;
            }
        }
        visited[r][c] = false;
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        n = board[0].size();
        bool ans = false;
        int wid = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                if (!visited[i][j])
                {
                    if (func(i, j, board, wid, word, visited))
                        return true;
                }
            }
        }
        return ans;
    }
};