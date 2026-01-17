// 307. Range Sum Query - Mutable
// Given an integer array nums, handle multiple queries of the following types:

// Update the value of an element in nums.
// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:

// NumArray(int[] nums) Initializes the object with the integer array nums.
// void update(int index, int val) Updates the value of nums[index] to be val.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

// Example 1:

// Input
// ["NumArray", "sumRange", "update", "sumRange"]
// [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
// Output
// [null, 9, null, 8]

// Explanation
// NumArray numArray = new NumArray([1, 3, 5]);
// numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
// numArray.update(1, 2);   // nums = [1, 2, 5]
// numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8

// Constraints:

// 1 <= nums.length <= 3 * 104
// -100 <= nums[i] <= 100
// 0 <= index < nums.length
// -100 <= val <= 100
// 0 <= left <= right < nums.length
// At most 3 * 104 calls will be made to update and sumRange.

#include <bits/stdc++.h>
using namespace std;

class NumArray
{
private:
    vector<int> segmentTree;
    vector<int> nums;
    int n;
    void buildSegmentTree(int i, int left, int right)
    {
        if (left == right)
        {
            segmentTree[i] = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildSegmentTree(2 * i + 1, left, mid);
        buildSegmentTree(2 * i + 2, mid + 1, right);
        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }
    int query(int i, int start, int end, int left, int right)
    {
        if (start > right || end < left)
            return 0;
        if (left >= start && right <= end)
            return segmentTree[i];
        int mid = left + (right - left) / 2;
        return query(2 * i + 1, start, end, left, mid) + query(2 * i + 2, start, end, mid + 1, right);
    }
    void updateTree(int left, int right, int i, int treeIndex, int val)
    {
        if (left == right)
        {
            segmentTree[treeIndex] = val;
            return;
        }
        int mid = left + (right - left) / 2;
        if (i <= mid)
            updateTree(left, mid, i, 2 * treeIndex + 1, val);
        else
            updateTree(mid + 1, right, i, 2 * treeIndex + 2, val);
        segmentTree[treeIndex] = segmentTree[2 * treeIndex + 1] + segmentTree[2 * treeIndex + 2];
    }

public:
    NumArray(vector<int> &nums)
    {
        this->nums = nums;
        n = nums.size();
        segmentTree.assign(4 * n, 0);
        buildSegmentTree(0, 0, n - 1);
    }

    void update(int index, int val)
    {
        updateTree(0, n - 1, index, 0, val);
    }

    int sumRange(int left, int right)
    {
        return query(0, left, right, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
