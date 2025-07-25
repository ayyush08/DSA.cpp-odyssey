// Next Permutation
// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr:

// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1].

// The next permutation of an array of integers is the next lexicographically greater permutation of its integers.

// More formally, if all the permutations of the array are sorted in lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted order.

// If such arrangement is not possible (i.e., the array is the last permutation), then rearrange it to the lowest possible order (i.e., sorted in ascending order).

// You must rearrange the numbers in-place and use only constant extra memory.

// Examples:
// Input: nums = [1,2,3]

// Output: [1,3,2]

// Explanation: The next permutation of [1,2,3] is [1,3,2].

// Input: nums = [3,2,1]

// Output: [1,2,3]

// Explanation: [3,2,1] is the last permutation. So we return the first: [1,2,3].

// Approach: We find the first longest prefix that is not in descending order, then find the smallest number larger than the prefix and swap them. Finally, reverse the suffix to get the next permutation.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int idx = -1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                idx = i;
                break;
            }
        }

        if (idx == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i >= idx; i--)
        {
            if (nums[i] > nums[idx])
            {
                swap(nums[i], nums[idx]);
                break;
            }
        }
        reverse(nums.begin() + idx + 1, nums.end());
        return;
    }
};


//Time Complexity: O(3N)  = O(N)
//Space Complexity: O(1)