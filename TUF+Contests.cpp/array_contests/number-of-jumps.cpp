// Number of Jumps

// 0

// 100
// Easy
// Given an array nums of n integers and an integer k, return the total number of jumps needed in the array.

// An element nums[i] needs to jump another element nums[j] if:

// 0 <= i < j <= n-1
// nums[i] + k < nums[j]

// Examples:
// Input: nums = [3, 1, 10, 6, 5], k = 2

// Output: 5

// Explanation: Number of jumps for each index:

// nums[0] -> 2, nums[1] -> 3, nums[2] -> 0, nums[3] -> 0, nums[4] -> 0

// Total = 2 + 3 + 0 + 0 + 0 = 5

// Input: nums = [1, 4, 5, 1, 7], k = 3

// Output: 3

// Explanation: Number of jumps for each index:

// nums[0] -> 2, nums[1] -> 0, nums[2] -> 0, nums[3] -> 1, nums[4] -> 0

// Total = 2 + 0 + 0 + 1 + 0 = 3

// Constraints:
// 1 <= n <= 105
// -104 <= nums[i] <= 104
// 0 <= k <= 104

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int NumberOfJumps(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;
        multiset<int> seen;
        for (int i = n - 1; i >= 0; i--)
        {
            auto it = seen.upper_bound(nums[i] + k);
            count += distance(it, seen.end());
            seen.insert(nums[i]);
        }
        return count;
    }
};


//Keypoints:
//Naive approach would be O(n^2) to find all valid pairs  which is not feasible for large n as per given constraints.
//Using a multiset allows us to efficiently find the count of elements that are greater than nums[i] + k in O(log n) time for each element.
//Why multiset? Because it allows us to maintain the order of elements and retains duplicates unlike normal sets and provides efficient insertion and upper_bound operations in O(log n) time.
//Intuition: Simply traverse from back and get the upper_bound of nums[i] + k (first element greater than nums[i] + k) , then count of all elements after that in the multiset will be the number of jumps needed for that index.

// Time Complexity: O(n log n) where n is the size of the input array nums, due to the insertion and upper_bound operations on the multiset.
// Space Complexity: O(n) for storing the elements in the multiset.