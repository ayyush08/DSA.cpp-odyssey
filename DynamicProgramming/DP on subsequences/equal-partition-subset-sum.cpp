// Partition equal subset sum

// Given an array arr of n integers, return true if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal else return false.

// Examples:
// Input: arr = [1, 10, 21, 10]

// Output: True

// Explanation: The array can be partitioned as [1, 10, 10] and [21].

// Input: arr = [1, 2, 3, 5]

// Output: False

// Explanation: The array cannot be partitioned into equal sum subsets.

// Similar to subset sum equal to target problem because if we can find a subset with sum equal to totalSum/2 then the rest of the elements will also have sum equal to totalSum/2


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
    bool equalPartition(int n, vector<int> arr)
    {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if (totalSum & 1)
            return false;
        int target = totalSum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return check(n - 1, target, arr, dp);
    }
};

//Similar tabulation approach and space optimization as in subset sum equal to target problem