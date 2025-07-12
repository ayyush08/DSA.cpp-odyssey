// Given an integer array nums. Find the subarray with the largest product, and return the product of the elements present in that subarray.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Examples:
// Input: nums = [4, 5, 3, 7, 1, 2]

// Output: 840

// Explanation: The largest product is given by the whole array itself

// Input: nums = [-5, 0, -2]

// Output: 0

// Explanation: The largest product is achieved with the following subarrays [0], [-5, 0], [0, -2], [-5, 0, -2].

// Input: nums = [1, -2, 3, 4, -4, -3]

// Output:
// 144
// Constraints:
// 1 <= nums.length <= 104
// -10 <= nums[i] <= 10
// -109 <= product of any prefix or suffix of nums <= 109

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int prefix = 1, suffix = 1;
        int n = nums.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n - i - 1];

            ans = max(ans, max(prefix, suffix));
        }
        return ans;
    }
};

//Intuition: The product of a subarray can be calculated by multiplying the elements in that subarray. We can calculate the product from both ends (prefix and suffix) to ensure we capture all possible contiguous subarrays. If we encounter a zero, we reset the product since any product involving zero is zero. The maximum product found during these calculations will be our answer. This way we also take care of negative numbers, as multiplying even negative numbers gives a positive product, which can potentially lead to a larger maximum product while also multiplying odd negative numbers which will yield a negative product hence reducing the maximum product.
//Time Complexity: O(n) - We traverse the array once.
//Space Complexity: O(1) - We use a constant amount of space for variables.