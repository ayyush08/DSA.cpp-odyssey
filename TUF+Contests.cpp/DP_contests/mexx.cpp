// MEXX

// 0

// 100
// Easy
// Everyone knows the definition of MEX, including Jamshed. But Jamshed loves MEX, so he comes up with a new problem involving MEX every day, including today.

// Given an array nums of size n. You can partition the array into any number of contiguous subarrays. You need to find the maximum sum which is obtained by adding the MEX of each partitioned subarray.

// Each element of the given array belongs to exactly one of the subarrays.

// The MEX (minimum excluded) of an array is the smallest non-negative integer that does not belong to the array. For instance:

// The MEX of [2,2,1] is 0, because 0 does not belong to the array.

// The MEX of [3,1,0,1] is 2, because 0 and 1 belong to the array, but 2 does not.

// The MEX of [0,3,1,2] is 4 because 0, 1, 2, and 3 belong to the array, but 4 does not.

// Examples:
// Input : n = 5, nums = [1, 0, 5, 0, 2]

// Output : 3

// Explanation : We have array as : 1 0 5 0 2

// So we divide the array in 4 different partitions i.e. [1 0] [5] [0] [2].

// So the MEX of the 4 partitions are : [1 0] -> 2 , [5] -> 0 , [0] -> 1 , [2] -> 0.

// So the sum of MEX of all partitions is : 2 + 0 + 1 + 0 => 3.

// Input : n = 10, nums = [1, 3, 2, 0, 1, 0, 2, 2, 2, 0]

// Output : 8

// Explanation : we can partition the array in three parts as shown below :

// 1st partition -> [1, 3, 2, 0] -> Mex for 1st partition is 4

// 2nd partition -> [1, 0, 2, 2, 2] -> Mex for 2nd partition is 3

// 3rd partition -> [0] -> Mex for 3rd partition is 1

// So total sum = 4 + 3 + 1 => 8.

// Constraints:
// 1 <= t <= 103
// 1 <= n <= 103
// 0 <= arr[i] <= n
// It is guaranteed that sum of n over all testcase does not exceed 104.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int func(int i, int j, vector<int> &dp, vector<int> &nums)
    {
        if (i == j)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        vector<int> freq(j + 2, 0);
        int mexx = 0, cost = 0;
        for (int partition = i; partition < j; partition++)
        {
            freq[nums[partition]]++;
            while (freq[mexx])
                mexx++;
            cost = max(cost, mexx + func(partition + 1, j, dp, nums));
        }
        return dp[i] = cost;
    }

public:
    int mexx(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return func(0, n, dp, nums);
    }
};