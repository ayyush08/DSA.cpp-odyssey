// Count partitions with given difference
// Given an array arr of n integers and an integer diff, count the number of ways to partition the array into two subsets S1 and S2 such that:

// ∣S1−S2∣ = diff and S1 ≥ S2
// Where |S1| and |S2| are sum of Subsets S1 and S2 respectively.

// Return the result modulo 109 + 7.

// Examples:
// Input: arr = [1, 1, 2, 3], diff = 1

// Output: 3

// Explanation: The subsets are [1, 2] and [1, 3], [1, 3] and [1, 2], [1, 1, 2] and [3].

// Input: arr = [1, 2, 3, 4], diff = 2

// Output: 2

// Explanation: The subsets are [1, 3] and [2, 4], [1, 2, 3] and [4].

#include <bits/stdc++.h>
using namespace std;

// Formula used: count of subsets with given difference = count of subsets with sum equal to (totalSum-diff)/2

// Memoization- O(N*total) time, O(N*total) + O(N) space
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mod = 1e9 + 7;

public:
    int func(int i, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            if (arr[0] == 0 && target == 0) // two options- include or exclude 0
                return 2;
            if (target == 0) // target exhausted
                return 1;
            if (i == 0)
                return arr[i] == target; // only one element left
            return 0;
        }
        if (dp[i][target] != -1)
            return dp[i][target];

        int notTake = func(i - 1, target, arr, dp);
        int take = 0;
        if (target >= arr[i])
            take = func(i - 1, target - arr[i], arr, dp);
        return dp[i][target] = (notTake + take) % mod;
    }
    int countPartitions(int n, int diff, vector<int> &arr)
    {
        int total = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n, vector<int>(total + 1, -1));
        if ((total - diff) < 0 || (total - diff) & 1) // total-diff should be non-negative and even for given formula to work
            return 0;
        int target = (total - diff) / 2;
        if (target < 0)
            return 0;
        return func(n - 1, target, arr, dp);
    }
};

// Tabulation- O(N*total) time, O(N*total) space

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mod = 1e9 + 7;

public:
    int countPartitions(int n, int diff, vector<int> &arr)
    {
        int total = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n, vector<int>(total + 1, 0));
        if ((total - diff) < 0 || (total - diff) & 1)
            return 0;
        int target = (total - diff) / 2;
        if (target < 0)
            return 0;
        if (arr[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (arr[0] != 0 && arr[0] <= target)
            dp[0][arr[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int t = 0; t <= target; t++)
            {
                int notTake = dp[i - 1][t];

                int take = 0;
                if (t >= arr[i])
                    take = dp[i - 1][t - arr[i]];

                dp[i][t] = (take + notTake) % mod;
            }
        }

        return dp[n - 1][target];
    }
};

// Space Optimization- O(total) space

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mod = 1e9 + 7;

public:
    int countPartitions(int n, int diff, vector<int> &arr)
    {
        int total = accumulate(arr.begin(), arr.end(), 0);
        vector<int> prev(total + 1, 0);
        vector<int> curr(total + 1, 0);
        if ((total - diff) < 0 || (total - diff) & 1)
            return 0;
        int target = (total - diff) / 2;
        if (target < 0)
            return 0;
        if (arr[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;

        if (arr[0] != 0 && arr[0] <= target)
            prev[arr[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            curr[0] = 0;
            for (int t = 0; t <= target; t++)
            {
                int notTake = prev[t];

                int take = 0;
                if (t >= arr[i])
                    take = prev[t - arr[i]];

                curr[t] = (take + notTake) % mod;
            }
            prev = curr;
        }

        return prev[target];
    }
};