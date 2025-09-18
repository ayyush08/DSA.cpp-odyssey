// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
// Example 2:

// Input: nums = [1], target = 1
// Output: 1

// Constraints:

// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        // dp[i][j] = ways to make sum j by chooosing +/- in first i intergers
        // of num;
        int n = nums.size();
        int sum = 0;
        for (int n : nums)
            sum += n;
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));
        dp[0][sum] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = (-sum); j <= sum; j++)
            {
                int idx = j + sum;
                if (dp[i - 1][idx] > 0)
                {
                    // add '+' choice
                    int plus = j + nums[i - 1] + sum;
                    if (plus >= 0 && plus <= 2 * sum)
                        dp[i][plus] += dp[i - 1][idx];

                    // add '-' choice
                    int minus = j - nums[i - 1] + sum;
                    if (minus >= 0 && minus <= 2 * sum)
                        dp[i][minus] += dp[i - 1][idx];
                }
            }
        }
        return (target + sum >= 0 && target + sum <= 2 * sum)
                   ? dp[n][target + sum]
                   : 0;
    }
};

// ANOTHER APPROACH  - if we notice carefully we can see that this problem can be converted to count of partitions with given difference problem.
// Why? if we take all the elements with + sign in one subset and all the elements with - sign in another subset then the difference of sum of these two subsets should be equal to target. which means we need to find count of partitions with given difference.

class Solution2
{
public:
    int mod = 1e9 + 7;
    int func(int i, int target, vector<vector<int>> &dp, vector<int> &nums)
    {
        if (i == 0)
        {
            if (nums[0] == 0 && target == 0)
                return 2;
            if (target == 0)
                return 1;

            return nums[i] == target;
        }
        if (dp[i][target] != -1)
            return dp[i][target];
        int notTake = func(i - 1, target, dp, nums);
        int take = 0;
        if (target >= nums[i])
            take = func(i - 1, target - nums[i], dp, nums);

        return dp[i][target] = (take + notTake) % mod;
    }
    int targetSum(int n, int target, vector<int> &nums)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if ((total - target) < 0 || (total - target) & 1)
            return 0;
        int diff = (total - target) / 2;
        vector<vector<int>> dp(n + 1, vector<int>(diff + 1, -1));
        return func(n - 1, diff, dp, nums);
    }
};
