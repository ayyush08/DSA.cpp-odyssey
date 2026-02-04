// 3082. Find the Sum of the Power of All Subsequences
// You are given an integer array nums of length n and a positive integer k.

// The power of an array of integers is defined as the number of subsequences with their sum equal to k.

// Return the sum of power of all subsequences of nums.

// Since the answer may be very large, return it modulo 109 + 7.

// Example 1:

// Input: nums = [1,2,3], k = 3

// Output: 6

// Explanation:

// There are 5 subsequences of nums with non-zero power:

// The subsequence [1,2,3] has 2 subsequences with sum == 3: [1,2,3] and [1,2,3].
// The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
// The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
// The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
// The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
// Hence the answer is 2 + 1 + 1 + 1 + 1 = 6.

// Example 2:

// Input: nums = [2,3,3], k = 5

// Output: 4

// Explanation:

// There are 3 subsequences of nums with non-zero power:

// The subsequence [2,3,3] has 2 subsequences with sum == 5: [2,3,3] and [2,3,3].
// The subsequence [2,3,3] has 1 subsequence with sum == 5: [2,3,3].
// The subsequence [2,3,3] has 1 subsequence with sum == 5: [2,3,3].
// Hence the answer is 2 + 1 + 1 = 4.

// Example 3:

// Input: nums = [1,2,3], k = 7

// Output: 0

// Explanation: There exists no subsequence with sum 7. Hence all subsequences of nums have power = 0.

// Constraints:

// 1 <= n <= 100
// 1 <= nums[i] <= 104
// 1 <= k <= 100

// dp[i][sum] = number of subsequences from 0 to i with sum equal to sum
// each element has 3 choices here:
// 1. take the element in subsequence and reduce sum
// 2. don't take the element in subsequence but count subsequences from 0 to i
// 3. don't take the element in subsequence and count subsequences from 0 to i-1
// 2 and 3 both look like 'not take' but they are different as 2 counts subsequences including current element but not taking it, while 3 excludes current element altogether

// to take care of this, we traverse the once not taken subsequences again in the 'not take' case because the previous call would have included current element in subsequence, so the latter call excludes it

#include <bits/stdc++.h>
using namespace std;

// Memoization - O(N*k) time, O(N*k) + O(N) space

class Solution
{
public:
    int cnt = 0;
    long long mod = 1e9 + 7;
    int n;
    int target;
    int func(vector<int> &nums, vector<vector<long long>> &dp, int i, int sum)
    {
        if (i < 0)
            return sum == 0;
        if (dp[i][sum] != -1)
            return dp[i][sum];

        long long notTake = func(nums, dp, i - 1, sum);
        notTake += func(nums, dp, i - 1, sum) % mod; //twice to account for both not taking current element in subsequence and excluding it altogether
        long long take = 0;
        if (nums[i] <= sum)
        {
            take = func(nums, dp, i - 1, sum - nums[i]);
        }
        return dp[i][sum] = (notTake + take) % mod;
    }
    int sumOfPower(vector<int> &nums, int k)
    {
        n = nums.size();
        target = k;
        // int m = accumulate(nums.begin(),nums.end(),0);
        vector<vector<long long>> dp(n, vector<long long>(k + 1, -1));
        return func(nums, dp, n - 1, k);
    }
};

// Tabulation - O(N*k) time, O(N*k) space

class Solution
{
public:
    long long mod = 1e9 + 7;
    int n;
    int sumOfPower(vector<int> &nums, int k)
    {
        n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));
        dp[0][0] = 2; // notTake doubles
        if (nums[0] <= k)
            dp[0][nums[0]] = 1; // take first value case
        for (int i = 1; i < n; i++)
        {
            for (int sum = 0; sum <= k; sum++)
            {
                long long notTake = (2 * dp[i - 1][sum]) % mod;
                long long take = 0;
                if (nums[i] <= sum)
                {
                    take = dp[i - 1][sum - nums[i]];
                }
                dp[i][sum] = (take + notTake) % mod;
            }
        }
        return dp[n - 1][k];
    }
};

// Space Optimization O(N*k) time, O(k) space

class Solution
{
public:
    long long mod = 1e9 + 7;
    int n;
    int sumOfPower(vector<int> &nums, int k)
    {
        n = nums.size();
        vector<long long> prev(k + 1, 0);
        vector<long long> curr(k + 1, 0);
        prev[0] = 2; // notTake doubles
        if (nums[0] <= k)
            prev[nums[0]] = 1; // take first value case
        for (int i = 1; i < n; i++)
        {
            for (int sum = 0; sum <= k; sum++)
            {
                long long notTake = (2 * prev[sum]) % mod;
                long long take = 0;
                if (nums[i] <= sum)
                {
                    take = prev[sum - nums[i]];
                }
                curr[sum] = (take + notTake) % mod;
            }
            prev = curr;
        }
        return prev[k];
    }
};