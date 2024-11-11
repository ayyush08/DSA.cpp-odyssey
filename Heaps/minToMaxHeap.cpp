// Convert Min Heap to Max Heap

// Given a min-heap in array representation named nums, convert it into a max-heap and return the resulting array.
// A min-heap is a complete binary tree where the key at the root is the minimum among all keys present in a binary min-heap and the same property is recursively true for all nodes in the Binary Tree.
// A max-heap is a complete binary tree where the key at the root is the maximum among all keys present in a binary max-heap and the same property is recursively true for all nodes in the Binary Tree.

// Example 1
// Input: nums = [10, 20, 30, 21, 23]
// Output: [30, 21, 23, 10, 20]

// Example 2
// Input: nums = [-5, -4, -3, -2, -1]
// Output: [-1, -2, -3, -4, -5]

// Example 3
// Input: nums = [2, 6, 3, 100, 120, 4, 5]
// Output:
// 4

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void heapifyDown(vector<int>&nums,int size,int i){
        if(nums.size()==0) return;
        int largest = i;
        int leftChild = 2*i+1;
        int rightChild = 2*i+2;
        if(leftChild<size && nums[leftChild]>nums[largest]) largest=leftChild;
        if(rightChild<size && nums[rightChild]>nums[largest]) largest=rightChild;

        if(largest!=i){
            swap(nums[largest],nums[i]);
            heapifyDown(nums,size,largest);
        }
    }
    vector<int> minToMaxHeap(vector<int> nums) {
        for(int i=(nums.size()/2)-1;i>=0;i--){
            heapifyDown(nums,nums.size(),i);
        }
        return nums;
    }
};


int main() {
    Solution s;
    vector<int> nums = {10, 20, 30, 21, 23};
    vector<int> res = s.minToMaxHeap(nums);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}