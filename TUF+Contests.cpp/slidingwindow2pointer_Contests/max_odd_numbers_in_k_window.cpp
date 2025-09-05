// Max Odd Numbers in K Window
// Given an integer array nums and an integer k, return the maximum number of odd numbers present in a subarray of size k within nums.

// Examples:
// Input: nums = [2, 3, 3, 2, 9, 2, 5], k = 4
// Output: 3
// Explanation: The subarray [3, 3, 2, 9] is the optimal choice with the maximum odd numbers possible = 3.

// Input: nums = [9, 2, 2, 5, 8, 6], k = 3
// Output: 1
// Explanation: [9, 2, 2] is one of the optimal subarrays, [2, 5, 8] is also valid.

// Constraints:
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= n

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxOddinKSizeWindow(vector<int> &nums, int k)
    {
        int l = 0, r = k - 1;
        int n = nums.size();
        int ans = 0, sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += (nums[i] & 1);
        }
        ans = sum;
        while (r + 1 < n)
        {
            sum -= (nums[l] & 1);
            l++;
            r++;
            sum += (nums[r] & 1);
            ans = max(ans, sum);
        }
        return ans;
    }
};