// 1879. Minimum XOR Sum of Two Arrays
// You are given two integer arrays nums1 and nums2 of length n.

// The XOR sum of the two integer arrays is (nums1[0] XOR nums2[0]) + (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1]) (0-indexed).

// For example, the XOR sum of [1,2,3] and [3,2,1] is equal to (1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4.
// Rearrange the elements of nums2 such that the resulting XOR sum is minimized.

// Return the XOR sum after the rearrangement.

// Example 1:

// Input: nums1 = [1,2], nums2 = [2,3]
// Output: 2
// Explanation: Rearrange nums2 so that it becomes [3,2].
// The XOR sum is (1 XOR 3) + (2 XOR 2) = 2 + 0 = 2.
// Example 2:

// Input: nums1 = [1,0,3], nums2 = [5,3,4]
// Output: 8
// Explanation: Rearrange nums2 so that it becomes [5,4,3].
// The XOR sum is (1 XOR 5) + (0 XOR 4) + (3 XOR 3) = 4 + 4 + 0 = 8.

// Constraints:

// n == nums1.length
// n == nums2.length
// 1 <= n <= 14
// 0 <= nums1[i], nums2[i] <= 107

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumXORSum(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<long long> dp(1 << n, LLONG_MAX);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << n); mask++)
        {
            int already = __builtin_popcount(mask);
            for (int i = 0; i < n; i++)
            {
                if ((mask & (1 << i)) == 0)
                {
                    int newMask = mask | (1 << i);
                    dp[newMask] = min(dp[newMask], (dp[mask] + (nums1[already] ^ nums2[i])));
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};


// Explanation:
// 1. We use a bitmask to represent which elements of nums2 have been used.
// 2. The variable `already` counts how many elements from nums1 have been paired with elements from nums2.
// 3. For each mask, we iterate through all elements of nums2 and check if they have been used.
// 4. If an element has not been used, we calculate the new mask and update the dp array with the minimum XOR sum possible by pairing the current element of nums1 with the unused element of nums2.
// 5. Finally, we return the value in dp[(1 << n) - 1], which represents the minimum XOR sum after all elements have been paired.
// The time complexity is O(n * 2^n), where n is the length of the input arrays, which is feasible given the constraint (n <= 14). The space complexity is O(2^n) due to the dp array. 