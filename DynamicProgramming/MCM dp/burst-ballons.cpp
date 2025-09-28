// Burst balloons
// Given n balloons, indexed from 0 to n - 1, each balloon is painted with a number on it represented by an array nums. Burst all the balloons.

// If the ith balloon is burst, the coins obtained are nums[i - 1] * nums[i] * nums[i + 1]. If i - 1 or i + 1 goes out of bounds of the array, treat it as if there is a balloon with a 1 painted on it.

// Return the maximum coins that can be collected by bursting the balloons wisely.

// Examples:
// Input : nums = [3, 1, 5, 8]

// Output : 167

// Explanation :

// nums = [3, 1, 5, 8] --> [3, 5, 8] --> [3, 8] --> [8] --> []

// coins = 3*1*5  +  3*5*8  + 1*3*8 + 1*8*1 = 167.

// Input : nums = [1, 2, 3, 4]

// Output : 40

// Explanation :

// nums = [1, 2, 3, 4] --> [1, 2, 4] --> [1, 4] --> [4] --> []

// coins = 2*3*4 + 1*2*4 + 1*1*4 + 1*4*1 = 40.

#include <bits/stdc++.h>
using namespace std;

// Memoization - O(n^3) time and O(n^2)+O(n) space

class Solution
{
public:
    int func(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int maxi = INT_MIN;
        for (int k = i; k <= j; k++)
        {
            int cost = nums[i - 1] * nums[k] * nums[j + 1] + func(i, k - 1, nums, dp) + func(k + 1, j, nums, dp);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return func(1, n, nums, dp);
    }
};

// Tabulation - O(n^3) time and O(n^2) space
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i > j)
                    continue;
                int maxi = INT_MIN;
                for (int k = i; k <= j; k++)
                {
                    int cost = nums[i - 1] * nums[k] * nums[j + 1] +
                               dp[i][k - 1] +
                               dp[k + 1][j];
                    maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};