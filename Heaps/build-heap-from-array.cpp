// Build heap from a given Array
// Given an array of integers nums, convert it in-place into a min-heap.

// A binary min-heap is a complete binary tree where the key at the root is the minimum among all keys present in a binary min-heap and the same property is recursively true for all nodes in a Binary Tree.

// Examples:
// Input: nums = [6, 5, 2, 7, 1, 7]

// Output: [1, 5, 2, 7, 6, 7]

// Explanation: nums[0] <= nums[1], nums[2]

// nums[1] <= nums[3], nums[4]

// nums[2] <= nums[5]

// Input: nums = [2, 3, 4, 1, 7, 3, 9, 4, 6]

// Output: [1, 2, 3, 3, 7, 4, 9, 4, 6]

// Explanation: nums[0] <= nums[1], nums[2]

// nums[1] <= nums[3], nums[4]

// nums[2] <= nums[5], nums[6]

// nums[3] <= nums[7], nums[8]

// Constraints:
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void heapifyDown(vector<int> &nums, int ind)
    {
        int smallest = ind;
        int leftChildIndex = 2 * ind + 1;
        int rightChildIndex = 2 * ind + 2;

        if (leftChildIndex < nums.size() && nums[leftChildIndex] < nums[smallest])
            smallest = leftChildIndex;
        if (rightChildIndex < nums.size() && nums[rightChildIndex] < nums[smallest])
            smallest = rightChildIndex;

        if (smallest != ind)
        {
            swap(nums[smallest], nums[ind]);
            heapifyDown(nums, smallest);
        }
    }
    void buildMinHeap(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapifyDown(nums, i);
        }
    }
};