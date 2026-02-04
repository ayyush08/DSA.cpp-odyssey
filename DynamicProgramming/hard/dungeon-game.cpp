// 174. Dungeon Game
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.

// The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

// Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).

// To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

// Return the knight's minimum initial health so that he can rescue the princess.

// Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

// Example 1:

// Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
// Output: 7
// Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
// Example 2:

// Input: dungeon = [[0]]
// Output: 1

// Constraints:

// m == dungeon.length
// n == dungeon[i].length
// 1 <= m, n <= 200
// -1000 <= dungeon[i][j] <= 1000

#include <bits/stdc++.h>
using namespace std;

// Intuition: We need to ensure that at any cell, the knight has at least 1 health point to survive. We can work backwards from the princess's cell to determine the minimum health required at each cell to ensure survival until reaching the princess.
// Why Subtract? Because if we have health H and we enter a cell with value V, the gap between H and V determines how much health we need before entering that cell to ensure we have at least 1 health point after the effect of that cell is applied. By subtracting the cell's value from the required health of the next cell, we can determine the minimum health needed before entering the current cell. Hence avoid dying with 0 hp.

// Approach 1: Memoization (Top-Down DP) O(m*n)+O(m+n) for recursion stack

class Solution
{
public:
    int m;
    int n;
    vector<vector<long long>> dp;
    long long solve(int i, int j, vector<vector<int>> &dungeon)
    {
        if (i >= m || j >= n)
            return LLONG_MAX;
        if (i == m - 1 && j == n - 1)
            return max(1, 1 - dungeon[i][j]);
        if (dp[i][j] != -1)
            return dp[i][j];
        long long down = solve(i + 1, j, dungeon);
        long long right = solve(i, j + 1, dungeon);
        long long need = min(down, right);
        long long points = need - dungeon[i][j];
        return dp[i][j] = max(1LL, points);
    }
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        m = dungeon.size();
        n = dungeon[0].size();
        dp.assign(m, vector<long long>(n, -1));
        long long hp = solve(0, 0, dungeon);
        return hp;
    }
};

// Approach 2: Tabulation (Bottom-Up DP) O(m*n)

class Solution
{
public:
    int m;
    int n;
    vector<vector<long long>> dp;
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        m = dungeon.size();
        n = dungeon[0].size();
        dp.assign(m, vector<long long>(n, LLONG_MAX));
        dp[m - 1][n - 1] = max(1LL, 1LL - dungeon[m - 1][n - 1]);

        // last column
        for (int i = m - 2; i >= 0; i--)
        {
            dp[i][n - 1] = max(1LL, dp[i + 1][n - 1] - dungeon[i][n - 1]);
        }

        // last row
        for (int j = n - 2; j >= 0; j--)
        {
            dp[m - 1][j] = max(1LL, dp[m - 1][j + 1] - dungeon[m - 1][j]);
        }

        // NOTE: Above 2 loops can be avoided by initializing an extra row and column with INF values and setting dp[m-1][n] and dp[m][n-1] to 1. But this is more easier to understand.

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                long long down = dp[i + 1][j];
                long long right = dp[i][j + 1];
                long long need = min(down, right);
                long long points = need - dungeon[i][j];
                dp[i][j] = max(1LL, points);
            }
        }
        return dp[0][0];
    }
};

// Space Optimization - O(n)

class Solution
{
public:
    int m;
    int n;
    vector<vector<long long>> dp;
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        m = dungeon.size();
        n = dungeon[0].size();
        dp.assign(m, vector<long long>(n, LLONG_MAX));
        vector<long long> curr(n);
        vector<long long> prev(n);

        prev[n - 1] = max(1LL, 1LL - dungeon[m - 1][n - 1]);

        // last row
        for (int j = n - 2; j >= 0; j--)
        {
            prev[j] = max(1LL, prev[j + 1] - dungeon[m - 1][j]);
        }

        for (int i = m - 2; i >= 0; i--)
        {
            curr[n - 1] = max(1LL, prev[n - 1] - dungeon[i][n - 1]);
            for (int j = n - 2; j >= 0; j--)
            {
                long long down = prev[j];
                long long right = curr[j + 1];
                long long need = min(down, right);
                long long points = need - dungeon[i][j];
                curr[j] = max(1LL, points);
            }
            prev = curr;
        }
        return prev[0];
    }
};