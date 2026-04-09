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
// At most 3 * 104 calls will be made to update and sumRange


#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    int n;
    int blockSize;
    vector<int>blocks;
    vector<int>nums;
    NumArray(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        blockSize = ceil(sqrt(n));
        blocks.assign(blockSize,0);
        for(int i=0;i<n;i++){
            blocks[i/blockSize]+=nums[i];
        }
    }
    
    void update(int index, int val) {
        int blockIndex = index/blockSize;
        blocks[blockIndex]-=nums[index];
        blocks[blockIndex]+=val;
        nums[index]=val;
    }
    
    int sumRange(int left, int right) {
        int blockStart = left/blockSize;
        int blockEnd = right/blockSize;
        int sum = 0;
        if(blockStart==blockEnd){
            for(int i=left;i<=right;i++) sum+=nums[i];  //same block;
        }
        else{
            //1. left partial sum (left to end of startblock)
            int endOfStartBlock = (blockStart+1)*blockSize-1;
            for(int i=left;i<=endOfStartBlock;i++) sum+=nums[i];
            //2. complete middle blocks;
            for(int i=(blockStart+1);i<blockEnd;i++) sum+=blocks[i];
            //3.right partial sum(start of end block to right);
            int startOfEndBlock = blockEnd*blockSize;
            for(int i=startOfEndBlock;i<=right;i++) sum+=nums[i];
        }
        return sum;
    }
};

//Time Complexity: O(sqrt(n)) for both update and sumRange operations.
//Space Complexity: O(n) for storing the original array and O(sqrt(n)) for storing the block sums, resulting in O(n) overall space complexity.

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */