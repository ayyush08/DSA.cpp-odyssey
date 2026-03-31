// 3681. Maximum XOR of Subsequences
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array nums of length n where each element is a non-negative integer.

// Select two subsequences of nums (they may be empty and are allowed to overlap), each preserving the original order of elements, and let:

// X be the bitwise XOR of all elements in the first subsequence.
// Y be the bitwise XOR of all elements in the second subsequence.
// Return the maximum possible value of X XOR Y.

// Note: The XOR of an empty subsequence is 0.

// Example 1:

// Input: nums = [1,2,3]

// Output: 3

// Explanation:

// Choose subsequences:

// First subsequence [2], whose XOR is 2.
// Second subsequence [2,3], whose XOR is 1.
// Then, XOR of both subsequences = 2 XOR 1 = 3.

// This is the maximum XOR value achievable from any two subsequences.

// Example 2:

// Input: nums = [5,2]

// Output: 7

// Explanation:

// Choose subsequences:

// First subsequence [5], whose XOR is 5.
// Second subsequence [2], whose XOR is 2.
// Then, XOR of both subsequences = 5 XOR 2 = 7.

// This is the maximum XOR value achievable from any two subsequences.

// Constraints:

// 2 <= nums.length <= 10^5
// 0 <= nums[i] <= 10^9

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long basis[32];

    void insert(long long x)
    {
        for (int i = 31; i >= 0; i--)
        {
            if (!(x & (1LL << i)))
                continue;

            if (basis[i] == 0)
            {
                basis[i] = x;
                return;
            }

            x ^= basis[i];
        }
    }
    long long getMax()
    {
        long long ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            ans = max(ans, ans ^ basis[i]);
        }
        return ans;
    }
    int maxXorSubsequences(vector<int> &nums)
    {
        for (int x : nums)
        {
            insert(x);
        }
        return getMax();
    }
};

//Time Complexity: O(N * log(max(nums[i]))), where N is the length of the input array nums and max(nums[i]) is the maximum element in nums. This is because we iterate through each element in nums and for each element, we perform a logarithmic number of operations based on the number of bits required to represent the maximum element.

//Space Complexity: O(log(max(nums[i]))), where max(nums[i]) is the maximum element in nums. This is because we are using an array of size 32 to store the basis, which is a constant space complexity.
