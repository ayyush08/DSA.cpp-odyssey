// 3859. Count Subarrays With K Distinct Integers
// You are given an integer array nums and two integers k and m.

// Return an integer denoting the count of subarrays of nums such that:

// The subarray contains exactly k distinct integers.
// Within the subarray, each distinct integer appears at least m times.

// Example 1:

// Input: nums = [1,2,1,2,2], k = 2, m = 2

// Output: 2

// Explanation:

// The possible subarrays with k = 2 distinct integers, each appearing at least m = 2 times are:

// Subarray	Distinct
// numbers	Frequency
// [1, 2, 1, 2]	{1, 2} → 2	{1: 2, 2: 2}
// [1, 2, 1, 2, 2]	{1, 2} → 2	{1: 2, 2: 3}
// Thus, the answer is 2.

// Example 2:

// Input: nums = [3,1,2,4], k = 2, m = 1

// Output: 3

// Explanation:

// The possible subarrays with k = 2 distinct integers, each appearing at least m = 1 times are:

// Subarray	Distinct
// numbers	Frequency
// [3, 1]	{3, 1} → 2	{3: 1, 1: 1}
// [1, 2]	{1, 2} → 2	{1: 1, 2: 1}
// [2, 4]	{2, 4} → 2	{2: 1, 4: 1}
// Thus, the answer is 3.

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105
// 1 <= k, m <= nums.length

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k, int m)
    {
        int n = nums.size();
        long long ans = 0;
        vector<int> freq1(1e5 + 1, 0);
        vector<int> freq2(1e5 + 1, 0);
        // wide window
        int distinct1 = 0;
        int l1 = 0;
        // narrow window
        int distinct2 = 0;
        int l2 = 0;
        // elements>=m
        int feasibles = 0;
        // growing window pointer
        int r = 0;
        while (r < n)
        {
            if (freq1[nums[r]] == 0)
                distinct1++;
            freq1[nums[r]]++;
            if (freq2[nums[r]] == 0)
                distinct2++;
            freq2[nums[r]]++;

            if (freq2[nums[r]] == m)
                feasibles++;

            while (distinct1 > k)
            {
                freq1[nums[l1]]--;
                if (freq1[nums[l1]] == 0)
                    distinct1--;
                l1++;
            }
            while (distinct2 > k)
            {
                if (freq2[nums[l2]] == m)
                    feasibles--;
                freq2[nums[l2]]--;
                if (freq2[nums[l2]] == 0)
                    distinct2--;
                l2++;
            }
            while (freq2[nums[l2]] > m)
            {
                freq2[nums[l2]]--;
                l2++;
            }
            if (distinct1 == k && feasibles == k)
            {
                ans += (l2 - l1 + 1);
            }
            r++;
        }
        return ans;
    }
};

/*
The solution uses a **two–sliding-window technique** to efficiently count valid subarrays. A **wide window (`l1 → r`)** ensures the subarray has **at most `k` distinct numbers**, while a **narrow window (`l2 → r`)** additionally ensures that every distinct number appears **at least `m` times**. Two frequency arrays track counts in each window, and a variable `feasibles` counts how many numbers have reached frequency `m`. As the right pointer `r` expands, both windows update their frequencies. The wide window shrinks if distinct elements exceed `k`, while the narrow window shrinks to maintain feasibility (removing extra occurrences so frequencies don't exceed what’s needed). When the wide window has exactly `k` distinct elements and all `k` elements are feasible (`feasibles == k`), every starting index between `l1` and `l2` forms a valid subarray ending at `r`, so `(l2 - l1 + 1)` is added to the answer. This ensures all valid subarrays are counted in **O(n)** time.

*/

// Time Complexity: O(n) where n is the length of the input array `nums`.
// Space Complexity: O(n) due to the frequency arrays used to track counts of distinct integers