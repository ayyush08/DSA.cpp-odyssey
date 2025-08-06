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
        board[i][j] = ' ';// mark as visited
        bool ans = false;
        //check all four directions
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