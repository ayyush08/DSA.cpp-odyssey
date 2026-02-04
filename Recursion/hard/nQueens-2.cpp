// 52. N-Queens II
// Companies
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

// Example 1:

// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
// Example 2:

// Input: n = 1
// Output: 1

// Constraints:

// 1 <= n <= 9

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cnt;
    vector<bool> rowUsed, diagUp, diagDown;
    void func(int c, int n)
    {
        if (c == n)
        {
            cnt++;
            return;
        }
        for (int r = 0; r < n; r++)
        {
            if (rowUsed[r])
                continue;
            if (diagUp[r - c + n - 1])
                continue;
            if (diagDown[r + c])
                continue;
            rowUsed[r] = diagUp[r - c + n - 1] = diagDown[r + c] = 1;
            func(c + 1, n);
            rowUsed[r] = diagUp[r - c + n - 1] = diagDown[r + c] = 0;
        }
    }
    int totalNQueens(int n)
    {
        cnt = 0;
        rowUsed.assign(n, 0);
        diagUp.assign(2 * n - 1, 0);
        diagDown.assign(2 * n - 1, 0);

        func(0, n);
        return cnt;
    }
};

//Time Complexity: O(N!)
//Space Complexity: O(N)