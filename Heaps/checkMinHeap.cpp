// Check if an array represents a min heap
// Given an array of integers nums. Check whether the array represents a binary min-heap or not. Return true if it does, otherwise return false.
// A binary min-heap is a complete binary tree where the key at the root is the minimum among all keys present in a binary min-heap and the same property is recursively true for all nodes in a Binary Tree.

// Example 1
// Input: nums = [10, 20, 30, 21, 23]
// Output: true
// Explanation: Each node has a lower or equal value than its children.

// Example 2
// Input: nums = [10, 20, 30, 25, 15]
// Output: false
// Explanation: The node with value 20 has a child with value 15, thus it is not a min-heap.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isHeap(vector<int>& nums) {
        int len = nums.size();
        for(int i=0;i<=(len/2)-1;i++){
        int leftChild = 2*i+1;
        int rightChild = 2*i+2;
        if((leftChild<len && nums[leftChild]<nums[i])||(rightChild<len && nums[rightChild]<nums[i])){
            return false;
            break;
        }
        }
        return true;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {10, 20, 30, 21, 23};
    vector<int> nums1 = {10, 20, 30, 25, 15};
    cout<<sol.isHeap(nums)<<endl;
    cout<<sol.isHeap(nums1)<<endl;
    return 0;
}