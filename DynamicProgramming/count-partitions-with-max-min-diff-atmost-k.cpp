// 3578. Count Partitions With Max-Min Difference at Most K
// You are given an integer array nums and an integer k. Your task is to partition nums into one or more non-empty contiguous segments such that in each segment, the difference between its maximum and minimum elements is at most k.

// Return the total number of ways to partition nums under this condition.

// Since the answer may be too large, return it modulo 109 + 7.

// Example 1:

// Input: nums = [9,4,1,3,7], k = 4

// Output: 6

// Explanation:

// There are 6 valid partitions where the difference between the maximum and minimum elements in each segment is at most k = 4:

// [[9], [4], [1], [3], [7]]
// [[9], [4], [1], [3, 7]]
// [[9], [4], [1, 3], [7]]
// [[9], [4, 1], [3], [7]]
// [[9], [4, 1], [3, 7]]
// [[9], [4, 1, 3], [7]]
// Example 2:

// Input: nums = [3,3,4], k = 0

// Output: 2

// Explanation:

// There are 2 valid partitions that satisfy the given conditions:

// [[3], [3], [4]]
// [[3, 3], [4]]

// Constraints:

// 2 <= nums.length <= 5 * 104
// 1 <= nums[i] <= 109
// 0 <= k <= 109

#include <bits/stdc++.h>
using namespace std;

// Approach-1: Recursion + Memoization (TLE on Leetcode)

class Solution
{
public:
    int mod = 1e9 + 7;
    int n;
    long long dp[50000 + 1];
    long long func(int i, vector<int> &nums, int k)
    {
        if (i >= n)
            return 1;
        if (dp[i] != -1)
            return dp[i];

        long long count = 0;
        int minEl = INT_MAX;
        int maxEl = INT_MIN;
        for (int j = i; j < n; j++)
        {
            minEl = min(minEl, nums[j]);
            maxEl = max(maxEl, nums[j]);
            if (maxEl - minEl > k) // can't split further so break
                break;
            count = (count + func(j + 1, nums, k)) % mod;
        }
        return dp[i] = count;
    }
    int countPartitions(vector<int> &nums, int k)
    {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return func(0, nums, k);
    }
};

// Here dp[i] = number of ways to partition array from index i to n-1

//// Approach-2: Tabulation (Still TLE on Leetcode)

class Solution
{
public:
    int mod = 1e9 + 7;
    int n;
    long long dp[50000 + 1];
    int countPartitions(vector<int> &nums, int k)
    {
        n = nums.size();
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            long long count = 0;
            int minEl = INT_MAX;
            int maxEl = INT_MIN;
            for (int j = i; j < n; j++)
            {
                minEl = min(minEl, nums[j]);
                maxEl = max(maxEl, nums[j]);
                if (maxEl - minEl > k)
                    break;
                count = (count + dp[j + 1]) % mod;
            }
            dp[i] = count;
        }
        return dp[0];
    }
};

// Approach-3:  DP + Sliding Window + Prefix Sum + Monotonic Deques

class Solution
{
public:
    int countPartitions(vector<int> &nums, int k)
    {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<int> dp(n + 1, 0);
        vector<int> pref(n + 1, 0);

        dp[0] = 1;
        pref[0] = 1;

        deque<int> minQ, maxQ;
        int l = 0, r = 0;

        while (r < n)
        {

            while (!maxQ.empty() && nums[r] > nums[maxQ.back()])
                maxQ.pop_back();
            maxQ.push_back(r);

            while (!minQ.empty() && nums[r] < nums[minQ.back()])
                minQ.pop_back();
            minQ.push_back(r);

            while (nums[maxQ.front()] - nums[minQ.front()] > k)
            {
                l++;
                if (!maxQ.empty() && maxQ.front() < l)
                    maxQ.pop_front();
                if (!minQ.empty() && minQ.front() < l)
                    minQ.pop_front();
            }

            dp[r + 1] = (pref[r] - (l > 0 ? pref[l - 1] : 0) + MOD) % MOD;
            pref[r + 1] = (pref[r] + dp[r + 1]) % MOD;

            r++;
        }

        return dp[n];
    }
};

//Intution:
//We can use dp where dp[i] represents the number of ways to partition the array from index i to n-1.
//To calculate dp[i], we need to consider all possible partitions starting from index i.
//We can use two pointers (l and r) to maintain a sliding window that satisfies the max-min difference condition.
//We also use two deques (minQ and maxQ) to efficiently track the minimum and maximum elements in the current window.
//The prefix sum array (pref) helps in calculating the sum of dp values in O(1) time.
//Why sum dp values? because for each valid partition ending at index j, we can add dp[j + 1] to dp[i].
//Thus, dp[i] = sum of dp[j + 1] for all j such that the subarray nums[i..j] satisfies the max-min difference condition.


//Time Complexity: O(n)
//Space Complexity: O(n)