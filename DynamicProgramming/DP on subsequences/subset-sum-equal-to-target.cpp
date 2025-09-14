// Subset sum equals to target

// Given an array arr of n integers and an integer target, determine if there is a subset of the given array with a sum equal to the given target.

// Examples:
// Input: arr = [1, 2, 7, 3], target = 6

// Output: True

// Explanation: There is a subset (1, 2, 3) with sum 6.

// Input: arr = [2, 3, 5], target = 6

// Output: False

// Explanation: There is no subset with sum 6.

// Memoization- O(N*target) time, O(N*target) + O(N) space

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(int i, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (i == 0)
            return arr[i] == target;
        if (dp[i][target] != -1)
            return dp[i][target];

        bool notTake = check(i - 1, target, arr, dp);
        bool take = false;
        if (target >= arr[i])
            take = check(i - 1, target - arr[i], arr, dp);

        return dp[i][target] = notTake || take;
    }
    bool isSubsetSum(vector<int> arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1)); // cannot use vector<bool> dp as it stores only 0 and 1 and we wont be able to track visited and unvisited states
        return check(n - 1, target, arr, dp);
    }
};

// Tabulation- O(N*target) time, O(N*target) space

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, false)); // In tabulation, dp only stores whether a state is achievable (true/false), but in memoization we also need a marker to differentiate "not computed yet" from "computed as false", so we usually store int (like -1, 0, 1).
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        if (arr[0] <= target)
            dp[0][arr[0]] = true;
        for (int i = 1; i < n; i++)
        {
            for (int sum = 1; sum <= target; sum++)
            {
                bool notTake = dp[i - 1][sum];
                bool take = false;
                if (sum >= arr[i])
                    take = dp[i - 1][sum - arr[i]];

                dp[i][sum] = notTake || take;
            }
        }
        return dp[n - 1][target];
    }
};

// Space Optimization- O(N*target) time, O(target) space

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int target)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        vector<bool> prev(target + 1, false);
        vector<bool> curr(target + 1, false);
        prev[0] = curr[0] = true;
        if (arr[0] <= target)
            prev[arr[0]] = true;
        for (int i = 1; i < n; i++)
        {
            for (int sum = 1; sum <= target; sum++)
            {
                bool notTake = prev[sum];
                bool take = false;
                if (sum >= arr[i])
                    take = prev[sum - arr[i]];

                curr[sum] = notTake || take;
            }
            prev = curr;
        }
        return prev[target];
    }
};