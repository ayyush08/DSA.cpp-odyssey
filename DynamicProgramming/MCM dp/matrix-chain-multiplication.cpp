// Matrix Chain Multiplication
// Given an array arr[] which represents the dimensions of a sequence of matrices where the ith matrix has the dimensions (arr[i-1] x arr[i]) for i>=1, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

// Examples:

// Input: arr[] = [2, 1, 3, 4]
// Output: 20
// Explanation: There are 3 matrices of dimensions 2 × 1, 1 × 3, and 3 × 4, Let this 3 input matrices be M1, M2, and M3. There are two ways to multiply:     ((M1 x M2) x M3) and (M1 x (M2 x M3)), note that the result of (M1 x M2) is a 2 x 3 matrix and result of (M2 x M3) is a 1 x 4 matrix.
// ((M1 x M2) x M3)  requires (2 x 1 x 3) + (2 x 3 x 4) = 30
// (M1 x (M2 x M3))  requires (1 x 3 x 4) + (2 x 1 x 4) = 20.
// The minimum of these two is 20.
// Input: arr[] = [1, 2, 3, 4, 3]
// Output: 30
// Explanation: There are 4 matrices of dimensions 1 × 2, 2 × 3, 3 × 4, 4 × 3. Let this 4 input matrices be M1, M2, M3 and M4. The minimum number of multiplications are obtained by ((M1 x M2) x M3) x M4). The minimum number is (1 x 2 x 3) + (1 x 3 x 4) + (1 x 4 x 3) = 30.

#include <bits/stdc++.h>
using namespace std;

// 1. Top-down approach using recursion with memoization

class Solution
{
private:
    int fun(int l, int r, vector<vector<int>> &dp, vector<int> &arr)
    {
        if (l + 1 == r)
            return 0;
        int ans = INT_MAX;
        if (dp[l][r] != -1)
            return dp[l][r];
        for (int i = l + 1; i < r; i++)
        {
            int curr = fun(l, i, dp, arr) + fun(i, r, dp, arr) + arr[l] * arr[i] * arr[r];
            ans = min(ans, curr);
        }
        return dp[l][r] = ans;
    }

public:
    int matrixMultiplication(vector<int> &arr)
    {
        // dp[l][r]-> min multiplications performed to multiply a[l]*a[l+a]..a[r];
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return fun(0, n - 1, dp, arr);
    }
};

// Another approach with same logic but different structure
class Solution
{
private:
    int func(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
    {
        if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;

        for (int k = i; k < j; k++)
        {
            int ans = func(arr, i, k, dp) + func(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];

            mini = min(mini, ans);
        }
        return dp[i][j] = mini;
    }

public:
    int matrixMultiplication(vector<int> &arr, int N)
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return func(arr, 1, N - 1, dp);
    }
};

// 2. Bottom-up approach using tabulation - O(n^3) time and O(n^2) space
class Solution
{
public:
    int matrixMultiplication(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int i = 1; i < n; i++)
            dp[i][i] = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                int mini = 1e9;
                for (int k = i; k < j; k++)
                {
                    int curr = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    mini = min(mini, curr);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n - 1];
    }
};