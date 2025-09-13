// Cherry pickup II

// Given a n x m 2d integer array called matrix where matrix[i][j] represents the number of cherries you can pick up from the (i, j) cell.Given two robots that can collect cherries, one is located at the top-leftmost (0, 0) cell and the other at the top-rightmost (0, m-1) cell.

// Return the maximum number of cherries that can be picked by the two robots in total, following these rules:

// Robots that are standing on (i, j) cell can only move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1), if it exists in the matrix.

// A robot will pick up all the cherries in a given cell when it passes through that cell.

// If both robots come to the same cell at the same time, only one robot takes the cherries.

// Both robots must reach the bottom row in matrix.

#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION

class Solution
{
public:
    int func(int i, int j1, int j2, vector<vector<int>> &matrix,
             vector<vector<vector<int>>> &dp)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        {
            return -1e8;
        }
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        if (i == n - 1)
        {
            if (j1 == j2)
                return matrix[i][j1];
            return matrix[i][j1] + matrix[i][j2];
        }
        int finalCherries = -1e8;
        for (int di = -1; di <= 1; di++)
        {
            for (int dj = -1; dj <= 1; dj++)
            {
                int cherries = 0;
                if (j1 == j2) // alice and bob on same cell
                    cherries = matrix[i][j1];
                else
                    cherries = matrix[i][j1] + matrix[i][j2];
                cherries += func(i + 1, j1 + di, j2 + dj, matrix, dp);
                finalCherries = max(finalCherries, cherries);
            }
        }
        return dp[i][j1][j2] = finalCherries;
    }
    int cherryPickup(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1)));

        return func(0, 0, m - 1, matrix, dp);
    }
};

// Time Complexity: O(N*M*M) * 9. At max, there will be N*M*M calls of recursion to solve a new problem and in every call, two nested loops together run for 9 times.

// Space Complexity:O(N) + O(N*M*M). We are using a recursion stack space of O(N), where N is the path length and an external DP Array of size ‘N*M*M’.

// TABULATION

class Solution2
{
public:
    int cherryPickup(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1)));
        // base case
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                if (j1 == j2)
                    dp[n - 1][j1][j2] = matrix[n - 1][j1];
                else
                    dp[n - 1][j1][j2] = matrix[n - 1][j1] + matrix[n - 1][j2];
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < m; j1++)
            {
                for (int j2 = 0; j2 < m; j2++)
                {
                    int finalCherries = -1e8;
                    for (int di = -1; di <= 1; di++)
                    {
                        for (int dj = -1; dj <= 1; dj++)
                        {
                            int cherries = 0;
                            if (j1 == j2)
                                cherries = matrix[i][j1];
                            else
                                cherries = matrix[i][j1] + matrix[i][j2];
                            int newJ1 = j1 + di;
                            int newJ2 = j2 + dj;

                            // Check bounds
                            if (newJ1 < 0 || newJ1 >= m || newJ2 < 0 ||
                                newJ2 >= m)
                                cherries += -1e9;
                            else
                                cherries += dp[i + 1][newJ1][newJ2];

                            finalCherries = max(finalCherries, cherries);
                        }
                    }
                    dp[i][j1][j2] = finalCherries;
                }
            }
        }
        return dp[0][0][m - 1];
    }
};

// Time Complexity: O((N*M*M)*9), The outer nested loops run for (N*M*M) times and the inner two nested loops run for 9 times

// Space Complexity:O(N*M*M), As an external array of size ‘N*M*M’ is used.

//SPACE OPTIMIZATION - just use 2d array and remove the 'i' dimension with prev and curr like always