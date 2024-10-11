// Check if there exists a subsequence with sum K
// Given an array nums and an integer k. R﻿eturn true if there exist subsequences such that the sum of all elements in subsequences is equal to k else false.
// Example 1
// Input : nums = [1, 2, 3, 4, 5] , k = 8
// Output : Yes
// Explanation : The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up to 8.
// Example 2
// Input : nums = [4, 3, 9, 2] , k = 10
// Output : No
// Explanation : No subsequence can sum up to 10.
// Example 3
// Input : nums = [1, 10, 4, 5] , k = 16
// Output:
// 2

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool func(int index, int sum, vector<int> &nums)
    {
        if (index == nums.size())
        {
            return sum == 0;
        }
        return func(index + 1, sum - nums[index], nums) | func(index + 1, sum, nums);
    }
    bool checkSubsequenceSum(vector<int> &nums, int k)
    {
        // your code goes here
        return func(0, k, nums);
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 8;
    cout << (s.checkSubsequenceSum(nums, k) ? "yes" : "no") << endl;
    return 0;
}

//Count the number of subsequences with sum K
class Solution2{
    public:
    int func(int index,int sum,vector<int>&nums){
        if(sum==0) return 1;
        if(index==nums.size() || sum<0){
            return 0;
        }
        // return count+func(index+1,sum-nums[index],nums)
        // if()
        return func(index+1,sum,nums)+func(index+1,sum-nums[index],nums);
    }   	
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here
        return func(0,k,nums);
    }
};