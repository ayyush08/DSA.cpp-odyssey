// 3634. Minimum Removals to Balance Array
// You are given an integer array nums and an integer k.

// An array is considered balanced if the value of its maximum element is at most k times the minimum element.

// You may remove any number of elements from nums​​​​​​​ without making it empty.

// Return the minimum number of elements to remove so that the remaining array is balanced.

// Note: An array of size 1 is considered balanced as its maximum and minimum are equal, and the condition always holds true.

// Example 1:

// Input: nums = [2,1,5], k = 2

// Output: 1

// Explanation:

// Remove nums[2] = 5 to get nums = [2, 1].
// Now max = 2, min = 1 and max <= min * k as 2 <= 1 * 2. Thus, the answer is 1.
// Example 2:

// Input: nums = [1,6,2,9], k = 3

// Output: 2

// Explanation:

// Remove nums[0] = 1 and nums[3] = 9 to get nums = [6, 2].
// Now max = 6, min = 2 and max <= min * k as 6 <= 2 * 3. Thus, the answer is 2.
// Example 3:

// Input: nums = [4,6], k = 2

// Output: 0

// Explanation:

// Since nums is already balanced as 6 <= 4 * 2, no elements need to be removed.

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 1 <= k <= 10^5

#include <bits/stdc++.h>
using namespace std;

//Minimum Removals to Balance Array = Total elements - Maximum balanced subarray length
//Time Complexity: O(n log n) for sorting + O(n) for two pointers = O(n log n)
//Space Complexity: O(1)

class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        int removals = 0;
        while (r < n)
        {
            long long maxi = nums[r];
            long long mini = nums[l];

            while (l < r && maxi > k * mini)
            {
                l++;
                mini = nums[l];
            }
            removals = max(removals, r - l + 1);
            r++;
        }
        return n - removals;
    }
};