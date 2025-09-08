// Ninja's training

// A ninja has planned a n-day training schedule. Each day he has to perform one of three activities - running, stealth training, or fighting practice. The same activity cannot be done on two consecutive days and the ninja earns a specific number of merit points, based on the activity and the given day.

// Given a n x 3-sized matrix, where matrix[i][0], matrix[i][1], and matrix[i][2], represent the merit points associated with running, stealth and fighting practice, on the (i+1)th day respectively. Return the maximum possible merit points that the ninja can earn.

// Examples:
// Input: matrix = [[10, 40, 70], [20, 50, 80], [30, 60, 90]]
// Output: 210
// Explanation:
// Day 1: fighting practice = 70
// Day 2: stealth training = 50
// Day 3: fighting practice = 90
// Total = 70 + 50 + 90 = 210
// This gives the optimal points.

// Input: matrix = [[70, 40, 10], [180, 20, 5], [200, 60, 30]]
// Output: 290
// Explanation:
// Day 1: running = 70
// Day 2: stealth training = 20
// Day 3: running = 200
// Total = 70 + 20 + 200 = 290
// This gives the optimal points.

// Constraints:
// 1 <= n <= 104
// n == number of rows in matrix
// 3 == number of columns in matrix
// 0 <= matrix[i][j] <= 1000

#include <bits/stdc++.h>
using namespace std;

// Memoization - O(n*4*3) time and O(n*4)+O(n) space
class Solution
{
public:
    int func(vector<vector<int>> &matrix, vector<vector<int>> &dp, int day, int last)
    {
        if (day == 0)
        {
            int maxPoints = 0;
            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                {
                    maxPoints = max(maxPoints, matrix[day][i]);
                }
            }
            return dp[day][last] = maxPoints;
        }
        if (dp[day][last] != -1)
            return dp[day][last];

        int maxPoints = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                int points = matrix[day][i] + func(matrix, dp, day - 1, i);
                maxPoints = max(maxPoints, points);
            }
        }
        return dp[day][last] = maxPoints;
    }
    int ninjaTraining(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));

        return func(matrix, dp, n - 1, 3);
    }
};

// Tabulation - O(n*4*3) time and O(n*4) space

class Solution2
{
public:
    int ninjaTraining(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        dp[0][0] = max(matrix[0][1], matrix[0][2]);
        dp[0][1] = max(matrix[0][0], matrix[0][2]);
        dp[0][2] = max(matrix[0][0], matrix[0][1]);
        dp[0][3] = max(matrix[0][0], max(matrix[0][1], matrix[0][2]));

        for (int day = 1; day < n; day++)
        {
            for (int last = 0; last < 4; last++)
            {
                dp[day][last] = 0;
                for (int task = 0; task < 3; task++)
                {
                    if (task != last)
                    {
                        int points = matrix[day][task] + dp[day - 1][task];
                        dp[day][last] = max(dp[day][last], points);
                    }
                }
            }
        }

        return dp[n - 1][3];
    }
};

// Space Optimization - only previous day is required to calculate current day. O(n*4*3) time and O(4) space

class Solution
{
public:
    int ninjaTraining(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        vector<int> prev(4, 0);

        prev[0] = max(matrix[0][1], matrix[0][2]);
        prev[1] = max(matrix[0][0], matrix[0][2]);
        prev[2] = max(matrix[0][0], matrix[0][1]);
        prev[3] = max(matrix[0][0], max(matrix[0][1], matrix[0][2]));

        for (int day = 1; day < n; day++)
        {
            vector<int> temp(4, 0);
            for (int last = 0; last < 4; last++)
            {
                temp[last] = 0;
                for (int task = 0; task <= 2; task++)
                {
                    if (task != last)
                    {
                        temp[last] = max(temp[last], matrix[day][task] + prev[task]);
                    }
                }
            }
            prev = temp;
        }

        return prev[3];
    }
};