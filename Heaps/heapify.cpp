// Heapify Algorithm

// Given an array nums representing a min-heap and two integers ind and val, set the value at index ind (0-based) to val and perform the heapify algorithm such that the resulting array follows the min-heap property.

// Modify the original array in-place, no need to return anything.

// Examples:
// Input: nums = [1, 4, 5, 5, 7, 6], ind = 5, val = 2

// Output: [1, 4, 2, 5, 7, 5]

// Explanation: After setting index 5 to 2, the resulting heap in array form = [1, 4, 5, 5, 7, 2]

// Parent of nums[5] = nums[2] = 5 > nums[5] = 2, so they are swapped.

// Final array = [1, 4, 2, 5, 7, 5]

// Input: nums = [2, 4, 3, 6, 5, 7, 8, 7], ind = 0, val = 7

// Output: [3, 4, 7, 6, 5, 7, 8, 7]

// Explanation: After setting index 0 to 7, the resulting heap in array form =[7, 4, 3, 6, 5, 7, 8, 7]

// The parent of nums[2] = nums[0] = 7 > nums[2] = 3, so they are swapped. No further swaps are needed.

// Final array = [3, 4, 7, 6, 5, 7, 8, 7]

// Constraints:
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 0 <= ind < nums.length
// -104 <= val <= 104
// nums represents a min-heap

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void heapifyUp(vector<int> &nums, int ind)
    {
        int parentIndex = (ind - 1) / 2;
        if (ind > 0 && nums[parentIndex] > nums[ind])
        {
            swap(nums[parentIndex], nums[ind]);
            heapifyUp(nums, parentIndex);
        }
    }
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
    void heapify(vector<int> &nums, int ind, int val)
    {
        if (nums[ind] < val)
        {
            nums[ind] = val;
            heapifyDown(nums, ind);
        }
        else
        {
            nums[ind] = val;
            heapifyUp(nums, ind);
        }
    }
};