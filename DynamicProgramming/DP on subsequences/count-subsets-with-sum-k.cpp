// Count subsets with sum K

// 24

// 100
// Hard

// Given an array arr of n integers and an integer K, count the number of subsets of the given array that have a sum equal to K. Return the result modulo (109 + 7).

// Examples:
// Input: arr = [2, 3, 5, 16, 8, 10], K = 10

// Output: 3

// Explanation: The subsets are [2, 8], [10], and [2, 3, 5].

// Input: arr = [1, 2, 3, 4, 5], K = 5

// Output: 3

// Explanation: The subsets are [5], [2, 3], and [1, 4].

#include <bits/stdc++.h>
using namespace std;

// Memoization- O(N*K) time, O(N*K) + O(N) space

class Solution
{
    int mod = 1e9 + 7;

public:
    int check(int i, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (i == 0)
            return arr[i] == target;
        if (dp[i][target] != -1)
            return dp[i][target];

        int notTake = check(i - 1, target, arr, dp);
        int take = 0;
        if (target >= arr[i])
            take = check(i - 1, target - arr[i], arr, dp);

        return dp[i][target] = (notTake + take) % mod;
    }
    int perfectSum(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return check(n - 1, k, arr, dp);
    }
};

// Tabulation- O(N*K) time, O(N*K) space

class Solution2
{
public:
    int perfectSum(vector<int> &arr, int k)
    {
        int mod = 1e9 + 7;
        int n = arr.size();
        if (n == 1)
            return arr[0] == k ? 1 : 0;
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = 1;
        if (arr[0] <= k)
            dp[0][arr[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int sum = 1; sum <= k; sum++)
            {
                int notTake = dp[i - 1][sum];
                int take = 0;
                if (sum >= arr[i])
                    take = dp[i - 1][sum - arr[i]];

                dp[i][sum] = (notTake + take) % mod;
            }
        }
        return dp[n - 1][k];
    }
};

// Space Optimization- O(N*K) time, O(K) space

class Solution
{
public:
    int perfectSum(vector<int> &arr, int k)
    {
        int mod = 1e9 + 7;
        int n = arr.size();
        vector<int> prev(k + 1, 0);
        vector<int> curr(k + 1, 0);
        prev[0] = 1;
        if (arr[0] <= k)
            prev[arr[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            curr[0] = 1;
            for (int sum = 1; sum <= k; sum++)
            {
                int notTake = prev[sum];
                int take = 0;
                if (sum >= arr[i])
                    take = prev[sum - arr[i]];

                curr[sum] = (notTake + take) % mod;
            }
            prev = curr;
        }
        return prev[k];
    }
};